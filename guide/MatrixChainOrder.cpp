#include "iostream"
#include "vector"
#include "limits.h"
using namespace std;
vector< vector<int> > _m;
vector< vector<int> > _s;
int _p[]={30,35,15,5,10,20,25};
void MatrixChainOrder(int p[]);
void PrintOptimalParens(int i,int j);
void PrintOptimalParens(int i,int j)
{
if(i==j)
    cout<<"A["<<i<<"]";
  else
  {
  cout<<"(";
    PrintOptimalParens(i,_s[i][j]);
    PrintOptimalParens(_s[i][j]+1,j);
    cout<<")";
  }
}
void MatrixChainOrder(int p[])
{
  int n=6;
  vector< vector<int> > m(n,vector<int>(n,0));
  vector< vector<int> > s(n,vector<int>(n,0));
  for(int i=0;i<n;i++)
    m[i][i]=0;
  for(int l=2;l<=n;l++)
  {
    for(int i=0;i<n-l+1;i++)
    {
      int j=i+l-1;
      m[i][j]=INT_MAX;
      for(int k=i;k<=j-1;k++)
      {
        int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
        if(q<m[i][j])
        {
          m[i][j]=q;
          s[i][j]=k;
        }
      }
    }
  }
  _m=m;
  _s=s;
}
int main()
{
  MatrixChainOrder(_p);
  PrintOptimalParens(0,5);
  cout<<endl;
  return 0;
}
