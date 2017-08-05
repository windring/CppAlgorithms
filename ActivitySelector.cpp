//Activity Selector
#include "iostream"
#include "vector"
using namespace std;
int _s[]={0,1,3,0,5,3,5,6,8,8,2,12};
int _f[]={0,4,5,6,7,9,9,10,11,12,14,16};
vector< vector<int> > _c;
vector< vector<int> > _b;
void DynamicActivitySelector(int s[],int f[],int n);
void Print(int i,int j);
void RecursiveActivitySelector(int k,int n);
void GreedyActivitySelector(int s[],int f[]);
void GreedyActivitySelector(int s[],int f[],int n)
{
  cout<<"1 ";
  int k=1;
  for(int m=2;m<=n;m++)
  {
    if(s[m]>=f[k])
    {
      cout<<m<<" ";
      k=m;
    }
  }
  cout<<endl;
}
void RecursiveActivitySelector(int k,int n)
{
  int m=k+1;
  while(m<=n&&_s[m]<_f[k])
    m++;
  if(m<=n)
  {
    cout<<m<<" ";
    RecursiveActivitySelector(m,n);
  }
}
void DynamicActivitySelector(int s[],int f[],int n)
{
  vector< vector<int> > c(n+1,vector<int>(n+1,0));
  vector< vector<int> > b(n+1,vector<int>(n+1,0));
  for(int i=1;i<=n-1;i++)
    c[i][i+1]=0;
  for(int l=3;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {
      int j=i+l-1;
      int t=0;
      c[i][j]=0;
      for(int k=i+1;k<=j-1;k++)
      {
        if(f[i]<=s[k]&&f[k]<=s[j])
        {
          t=c[i][k]+c[k][j]+1;
        }
        if(t>c[i][j])
        {
          c[i][j]=t;
          b[i][j]=k;
        }
      }
    }
  }
  _c=c;
  _b=b;
}
void Print(int i,int j)
{
  if(_c[i][j]==0)
    cout<<i<<" "<<j<<endl;
  else
  {
    Print(i,_b[i][j]);
    Print(_b[i][j],j);
  }
}
int main()
{
  cout<<"Dynamic Function"<<endl;
  DynamicActivitySelector(_s,_f,11);
  for(int i=1;i<=11;i++)
  {
    for(int j=1;j<=11;j++)
    {
      cout<<_c[i][j]<<"|"<<_b[i][j]<<" ";
    }
    cout<<endl;
  }
  Print(1,11);
  cout<<"Recursive Function"<<endl;
  RecursiveActivitySelector(0,11);
  cout<<endl;
  cout<<"Greedy Function"<<endl;
  GreedyActivitySelector(_s,_f,11);
  return 0;
}
