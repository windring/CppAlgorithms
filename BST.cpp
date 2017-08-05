//OptimalBinarySearchTree
#include "iostream"
#include "vector"
#include "limits.h"
using namespace std;
float _p[]={.0,.15,.10,.05,.10,.20};
float _q[]={.05,.10,.05,.05,.05,.10};
vector< vector<float> > _e;
vector< vector<float> > _root;
void OptimalBST(float p[],float q[],int n);
void OptimalBST(float p[],float q[],int n)
{
  vector< vector<float> > e(n+2,vector<float>(n+1,0));
  vector< vector<float> > w(n+2,vector<float>(n+1,0));
  vector< vector<float> > root(n+1,vector<float>(n+1,0));
  for(int i=1;i<=n+1;i++)
  {
    e[i][i-1]=q[i-1];
    w[i][i-1]=q[i-1];
  }
  for(int l=1;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {
      int j=i+l-1;
      e[i][j]=INT_MAX;
      w[i][j]=w[i][j-1]+p[j]+q[j];
      for(int r=i;r<=j;r++)
      {
        float t=e[i][r-1]+e[r+1][j]+w[i][j];
        if(t<e[i][j])
        {
          e[i][j]=t;
          root[i][j]=r;
        }
      }
    }
  }
  _e=e;
  _root=root;
}
int main()
{
  OptimalBST(_p,_q,5);
  for(int j=5;j>=1;j--)
  {
    for(int i=1;i<=j;i++)
      cout<<_root[i][j]<<"  ";
    cout<<endl;
  }
  for(int j=5;j>=0;j--)
  {
    for(int i=1;i<=j+1;i++)
      cout<<_e[i][j]<<"  ";
    cout<<endl;
  }
  return 0;
}
