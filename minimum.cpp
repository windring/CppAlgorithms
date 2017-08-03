#include "iostream"
using namespace std;
int _A[]={1,23,2,3,6,5,4,0};
int minimum(int A[])
{
  int min=A[0];
  int size=sizeof(_A)/sizeof(_A[0]);
  for(int i=1;i<size;i++)
  {
    if(min>A[i])
      min=A[i];
  }
  return min;
}
int main()
{
  int a=minimum(_A);
  cout<<a<<endl;
  return 0;
}
