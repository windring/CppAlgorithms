#include <bits/stdc++.h>
using namespace std;
const int len=1e7+7;
struct node{int l,r,s;}a[len];
int cnt=0;
void Insert(int th,int pos,int num){
  if(pos==-1){
    a[th].s++;
    return;
  }
  int bit=num&(1<<pos);
  if(bit==0){
    if(a[th].l==-1){
      a[th].l=++cnt;
      a[cnt]=node{-1,-1,0};
    }
    a[th].s++;
    Insert(a[th].l,pos-1,num);
  }else{
    if(a[th].r==-1){
      a[th].r=++cnt;
      a[cnt]=node{-1,-1,0};
    }
    a[th].s++;
    Insert(a[th].r,pos-1,num);
  }
}
int Query(int th,int pos,int k,int xorn){
  if(pos==-1)return 0;
  int bit=xorn&(1<<pos);
  // cout<<"pos"<<pos<<","<<bit<<","<<xorn<<"th"<<th<<","<<k<<endl;
  if(bit==0){
    int next;
    if(a[th].l!=-1 && a[a[th].l].s>=k){
      next=a[th].l;
      // cout<<"pos"<<pos<<":"<<0<<endl;
      return Query(next,pos-1,k,xorn);
    }else{
      next=a[th].r;
      // cout<<"pos"<<pos<<":"<<1<<","<<(1<<pos)<<endl;
      return Query(next,pos-1,k-a[a[th].l].s,xorn)+(1<<pos);
    }
  }else{
    int next;
    if(a[th].r!=-1&&a[a[th].r].s>=k){
      next=a[th].r;
      return Query(next,pos-1,k,xorn);
    }else{
      next=a[th].l;
      return Query(next,pos-1,k-a[a[th].r].s,xorn)+(1<<pos);
    }
  }
}
int main(){
  int n,q;
  a[0]=node{-1,-1,0};
  cin>>n>>q;
  int ins;
  for(int i=0;i<n;i++){
    cin>>ins;
    Insert(0,31,ins);
  }
  int op,xorn=0;
  for(int i=0;i<q;i++){
    cin>>op>>ins;
    if(op==1){
      xorn=xorn^ins;
    }else if(op==2){
      Insert(0,31,ins^xorn);
    }else{
      cout<<Query(0,31,ins,xorn)<<endl;
    }
  }
  return 0;
}