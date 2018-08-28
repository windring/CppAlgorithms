//Hoare sort
#include "iostream"
using namespace std;
int HoarePartition(int A[],int p,int r);
void HoareQuickSort(int A[],int p,int r);
void print();
int _A[]={3,2,5,23,2312,4342,12,321,3241,4,6,5,8,7};
int main()
{
  int size=sizeof(_A)/sizeof(_A[0]);
  print(); 
  HoareQuickSort(_A,0,size-1);
  print();
  return 0;
}
void print()
{
  int size=sizeof(_A)/sizeof(_A[0]);
  for(int i=0;i<size;i++)
    cout<<_A[i]<<"  ";
  cout<<endl; 
}
int HoarePartition(int A[],int p,int r)
{
  int x=A[p];
  int j=p-1;
  int k=r+1;
  while(true)
  {
    do
    {
      j++;
    }while(A[j]<x);
    do
    {
      k--;
     }while(A[k]>x);
     if(j<k)
     {
       int h=A[j];
       A[j]=A[k];
       A[k]=h;
     }else{
       return k+1;
     }
   }
}
void HoareQuickSort(int A[],int p,int r)
{
  if(p<r)
  {
    int q=HoarePartition(A,p,r);
    HoareQuickSort(A,p,q-1);
    HoareQuickSort(A,q,r);
  }
}
