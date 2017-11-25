#include "stdbool.h"
#include "stdlib.h"
struct MyQueue{
  int *Q;
  int head;
  int tail;
  int length;
  void (*init)(struct MyQueue *queue,int len);
  bool (*EnQueue)(struct MyQueue *queue,int x);
  int* (*DeQueue)(struct MyQueue *queue);
};
void init(struct MyQueue *queue,int len){
  queue->Q=(int*)malloc(sizeof(int)*(len+1));
}
bool EnQueue(struct MyQueue *queue,int x){
  if(queue->head==(queue->tail+1)%queue->length)return false;
  queue->Q[queue->tail]=x;
  if(queue->tail==queue->length)
    queue->tail=1;
  else
    queue->tail++;
  return true;
}
int* DeQueue(struct MyQueue *queue){
  int *p=(int*)malloc(sizeof(int)*2);
  if(queue->head==queue->tail)
    return (p[0]=1,p);
  int x=queue->Q[queue->head];
  if(queue->head==queue->length)
    queue->head=1;
  else
    queue->head++;
  return (p[0]=0,p[1]=x,p);
}
