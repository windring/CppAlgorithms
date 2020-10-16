#include "stdlib.h"
#include "stdbool.h"
//起始下标为1 
struct MyStack{
  int length;
  int *S;
  int top;
  void (*init)(struct MyStack *stack,int len);
  bool (*StackEmpty)(struct MyStack *stack);
  bool (*Push)(struct MyStack *stack,int x);
  int* (*Pop)(struct MyStack *stack);
};
void init(struct MyStack *stack,int len){
  stack->S=(int*)malloc(sizeof(int)*(len+1));
}
bool StackEmpty(struct MyStack *stack){
  return stack->top==0?1:0;
}
bool Push(struct MyStack *stack,int x){
  if(stack->top==stack->length)return false;
  stack->top++;
  stack->S[stack->top]=x;
  return true;
}
int* Pop(struct MyStack *stack){
  int *p=(int*)malloc(sizeof(int)*2);
  if(stack->StackEmpty(stack))return (p[0]=1,p);
  stack->top--;
  return (p[0]=0,p[1]=stack->S[stack->top+1],p);
}
