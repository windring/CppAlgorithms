#include "iostream"
#include "vector"
using namespace std;
int _s[]={0,1,3,0,5,3,5,6,8,8,2,12,100};
int _f[]={0,4,5,6,7,9,9,10,11,12,14,16,100};
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
  cout<<"dsafasdfasdfsadfdf";
  for(int i=0;i<n;++i)
  {
    cout<<"dfads";
    c[i][i]=0;
    c[i][i+1]=0; 
  }
  for(int l=0;l<=n;++l)
  {
    for(int i=1;i<=n-l;++i)
    {
      int j=i+l;
      int max=0;
      for(int r=i;r<=j;++r)
      {
        int lt=r;
        int lr=r;
        while(lt>=i&&f[lt]>s[r])
          lt--;
        while(lr<=j&&s[lr]<f[r])
          lr++;
        int t=c[i][lt]+c[lr][j]+1;
        if(max<t)
        {
          max=t;
          b[i][j]=r;
        }
      }
      c[i][j]=max;
    }
  }
  _c=c;
  _b=b;
}
void Print(int i,int j)
{
  if(i==j)
    return;
  Print(i,_b[i][j]);
  cout<<_b[i][j]<<" ";
  Print(_b[i][j],j);
}
int main()
{
  RecursiveActivitySelector(0,11);
  cout<<endl;
  GreedyActivitySelector(_s,_f,11);
  DynamicActivitySelector(_s,_f,11);
  for(int i=0;i<=11;i++)
  {
    for(int j=0;j<=11;j++)
    {
      cout<<_c[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
