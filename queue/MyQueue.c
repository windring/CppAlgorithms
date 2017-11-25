#include "stdio.h"
#include "MyQueue.h"
#include "windows.h"
#include "conio.h"

struct MyQueue myQueue={
  .head=1,
  .tail=1,
  .length=100,
  .init=init,
  .EnQueue=EnQueue,
  .DeQueue=DeQueue
};
void print(struct MyQueue *queue,int len,HANDLE *handle_out){
  int i=1;
  for(i;i<queue->tail;i++){
    SetConsoleTextAttribute(*handle_out, FOREGROUND_INTENSITY);
    if(i==queue->tail-1)
      SetConsoleTextAttribute(*handle_out, FOREGROUND_GREEN);
    if(i==queue->head)
      SetConsoleTextAttribute(*handle_out, FOREGROUND_INTENSITY|FOREGROUND_RED);
    printf("%d ",queue->Q[i]);
  }
}
int main(){
  HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);    //获得标准输出设备句柄  
  CONSOLE_SCREEN_BUFFER_INFO csbi;                        //定义窗口缓冲区信息结构体  
  GetConsoleScreenBufferInfo(handle_out, &csbi);
  int i=1;
  myQueue.init(&myQueue,myQueue.length);
  for(i;i<=20;i++){
    myQueue.EnQueue(&myQueue,i);
    print(&myQueue,myQueue.length,&handle_out);
    Sleep(300);
    system("cls");
  }
  myQueue.EnQueue(&myQueue,2);
  myQueue.EnQueue(&myQueue,3);
  print(&myQueue,myQueue.length,&handle_out); 
  return 0;
}
