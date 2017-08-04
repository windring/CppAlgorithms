#include "iostream"
using namespace std;
int _p[]={0,1,5,8,9,10,17,17,20,24,30};
int CutRod(int p[],int n);
int MemoizedCutRod(int p[],int n);
int MemoizedCutRodAux(int p[],int n,int r[]);
int BottomUpCutRod(int p[],int n);
int ExtendedBottomUpCutRod(int p[],int s[],int n);
int PrintCutRodSolution(int p[],int n);
int PrintCutRodSolution(int p[],int n)
{
  int _s[n+1];
  int a=ExtendedBottomUpCutRod(p,_s,n);
  while(n>0)
  {
    cout<<_s[n]<<"  ";
    n=n-_s[n];
  }
  cout<<"| ";
  return a;
}  
int ExtendedBottomUpCutRod(int p[],int s[],int n)
{
  int r[n+1];
  r[0]=0;
  for(int j=1;j<=n;j++)
  {
    int q=-1;
    for(int i=1;i<=j;i++)
    {
      if(q<p[i]+r[j-i])
      {
        q=p[i]+r[j-i];
        s[j]=i;
       }
    }
    r[j]=q;
  }
  return r[n];
} 
int BottomUpCutRod(int p[],int n)
{
  int r[n+1];
  r[0]=0;
  for(int j=1;j<=n;j++)
  {
    int q=-1;
    for(int i=1;i<=j;i++)
    {
      int s=p[i]+r[j-i];
      q=q>s?q:s;
    }
    r[j]=q;
  }
  return r[n];
}
int MemoizedCutRodAux(int p[],int n,int r[])
{
  if(r[n]>=0)
    return r[n];
  int q;
  if(n==0)
  {
    q=0;
  }else{
    q=-1;
    for(int i=1;i<=n;i++)
    {
       int s=MemoizedCutRodAux(p,n-i,r)+p[i];
       q=q>s?q:s;
    }
    r[n]=q;
  }
  return q;
} 
int MemoizedCutRod(int p[],int n)
{
  int r[n+1];
  for(int i=0;i<=n;i++)
  {
    r[i]=-1;
  }
  return MemoizedCutRodAux(p,n,r);
}
int CutRod(int p[],int n)
{
  if(n==0)
    return 0;
  int q=-1;
  for(int i=1;i<=n;i++)
  {
    int r=CutRod(p,n-i)+p[i];
    q=q>r?q:r;
  }
  return q;
}
int main()
{
  cout<<CutRod(_p,30)<<endl;
  cout<<PrintCutRodSolution(_p,30)<<endl;
  cout<<MemoizedCutRod(_p,30)<<endl;
  cout<<BottomUpCutRod(_p,30)<<endl;
  return 0;
}
