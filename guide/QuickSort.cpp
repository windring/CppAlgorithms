#include "iostream"
using namespace std;
int partition(int A[],int p,int r);
void quicksort(int A[],int p,int r);
int _A[]={223,5213,3,434,2,3,12,332,12};
void print();
int main()
{
  int size=sizeof(_A)/sizeof(_A[0]);
  cout<<"hello world"<<endl;
  cout<<"all size:"<<sizeof(_A)<<",single size:"<<sizeof(_A[0])<<endl;
  print();
  quicksort(_A,0,size-1);
  print();
  return 0;
}
void print()
{
  int end=sizeof(_A)/sizeof(_A[0]);
  for(int i=0;i<end;i++)
    cout<<_A[i]<<"  ";
  cout<<endl;
}
void quicksort(int A[],int p,int r)
{
  if(p<r)
  {
    int q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  } 
}
int partition(int A[],int p,int r)
{
  int x=A[r];
  int i=p-1;
  for(int j=p;j<=r-1;j++)
  {
    if(A[j]<=x)
    {
      i=i+1;
      int k=A[j];
      A[j]=A[i];
      A[i]=k;
    }
  }
  int h=A[i+1];
  A[i+1]=A[r];
  A[r]=h;
  return i+1;
} 
