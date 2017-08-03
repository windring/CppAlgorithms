#include "iostream"
#include "stdlib.h"
using namespace std;
int _A[]={1,2,3,4,87,6,5,8};
int randomizedselect(int A[],int p,int r,int i);
int randomizedpartition(int A[],int p,int r);
int partition(int A[],int p,int r);
int partition(int A[],int p,int r)
{
  int x=A[r];
  int i=p-1;
  for(int j=p;j<r;j++)
  {
    if(A[j]<=x)
    {
      i++;
      int h=A[i];
      A[i]=A[j];
      A[j]=h;
    }
  }
  int h=A[i+1];
  A[i+1]=A[r];
  A[r]=h;
  return i+1;
}
int randomizedpartition(int A[],int p,int r)
{
  int i=rand()%(r-p)+p;
  int h=A[r];
  A[r]=A[i];
  A[i]=h;
  return partition(A,p,r);
}
int randomizedselect(int A[],int p,int r,int i)
{
  if(p==r)
    return A[p];
  int q=randomizedpartition(A,p,r);
  int k=q-p+1;
  if(i==k)
    return A[q];
  else if(i<k)
    return randomizedselect(A,p,q-1,i);
  else
    return randomizedselect(A,q+1,r,i-k);
}
int main()
{
  cout<<":";
  int size=sizeof(_A)/sizeof(_A[0]);
  cout<<randomizedselect(_A,0,size-1,8)<<endl;
  return 0;
}
