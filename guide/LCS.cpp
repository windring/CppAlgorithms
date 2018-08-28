//LongestCommonSubsequenceProblem
#include "iostream"
#include "vector"
using namespace std;
vector< vector<int> > _c;
vector< vector<char> > _b;
char _x[]={':','A','B','C','B','D','A','B'};
char _y[]={':','B','D','C','A','B','A'};
/*
 *        {0,                       (i=0 and j=0)
 * c[i,j]={c[i-1,j-1]+1,            (i,j>0 and xi=yj)
 *        {max(c[i,j-1],c[i-1,j]),  (i,j>0 and xi!=yj)
 */
void LCS_Length(char x[],char y[]);
void Print_LCS(char x[],int i,int j);
void Print_LCS(int i,int j)
{
  if(i==0||j==0)
    return;
  if(_b[i][j]=='Q')
  {
    Print_LCS(i-1,j-1);
    cout<<_x[i];
  }else if(_b[i][j]=='T'){
    Print_LCS(i-1,j);
  }else{
    Print_LCS(i,j-1);
  } 
}
void LCS_Length(char x[],char y[])
{
  int m=sizeof(_x)/sizeof(_x[0]);
  int n=sizeof(_y)/sizeof(_y[0]);
  vector< vector<char> > b(m,vector<char>(n,0));
  vector< vector<int> > c(m,vector<int>(n,0));
  for(int i=0;i<m;i++)
    c[i][0]=0;
  for(int j=0;j<n;j++)
    c[0][j]=0;
  for(int i=1;i<m;i++)
  {
    for(int j=1;j<n;j++)
    {
      if(x[i]==y[j])
      {
        c[i][j]=c[i-1][j-1]+1;
        b[i][j]='Q';
      }else if(c[i-1][j]>=c[i][j-1])
      {
        c[i][j]=c[i-1][j];
        b[i][j]='T';
      }else{
        c[i][j]=c[i][j-1];
        b[i][j]='L';
      }
    }
  }
  _c=c;
  _b=b;
}
int main()
{
  LCS_Length(_x,_y);
  Print_LCS(7,6);
  cout<<endl;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<7;j++)
    {
      cout<<_c[i][j]<<_b[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
