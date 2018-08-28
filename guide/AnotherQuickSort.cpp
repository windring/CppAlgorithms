//another QuickSort like Hoare
//or just to be Hoare
#include "iostream"
using namespace std;
void print(int* A,int n);
void swap(int* A,int l,int r){
  if(A[l]!=A[r]){
    A[l]=A[l]^A[r];
    A[r]=A[l]^A[r];
    A[l]=A[l]^A[r];
  }
}
void quickSort(int* A,int l,int r){
  if(l>r)return;
  int val=A[l],start=l,end=r;
  while(l<r){
    while(A[r]>=val&&r>l)
      r--;
    while(A[l]<=val&&l<r)
      l++;
    swap(A,l,r);
    print(A,8);
  }
  swap(A,start,l);
  quickSort(A,start,l-1);
  quickSort(A,r+1,end);
}
void print(int* A,int n){
  for(int i=0;i<=n;i++)
    cout<<A[i]<<" ";
  cout<<endl;
}
int main(){
  int A[]={1,2,3,2,1,5,43,231,34};
  print(A,8);
  quickSort(A,0,8);
  print(A,8);
  return 0;
}
 
