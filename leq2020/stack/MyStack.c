#include "stdio.h"
#include "stdlib.h" 
#include "MyStack.h"

struct MyStack myStack={
  .length=100,
  .top=0,
  .init=init,
  .StackEmpty=StackEmpty,
  .Push=Push,
  .Pop=Pop
};
void print(int *S,int len){
  int i=1;
  for(i;i<=len;i++){
    printf("%d ",S[i]);
  }
}
int main(){
  int i=0;
  myStack.init(&myStack,myStack.length);
  for(i;i<100;i++)
    myStack.Push(&myStack,i);
  i=0;
  for(i;i<100;i++)
    myStack.Pop(&myStack);
  print(myStack.S,myStack.length);
  printf("top: %d.",myStack.top);
  myStack.Push(&myStack,1024);
  printf("top: %d.",myStack.top);
  if(!myStack.StackEmpty(&myStack))
    printf("pop: %d.",*(myStack.Pop(&myStack)+1));
  printf("top: %d.",myStack.top);
}
