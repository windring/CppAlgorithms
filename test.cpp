#include "iostream"
using namespace std;
int main()
{
  int i=0;
  do
  {
    i++;
    cout<<i<<endl;
  }while(i<10);
  cout<<i<<","<<i++<<","<<i<<","<<++i<<","<<i<<endl;
}
