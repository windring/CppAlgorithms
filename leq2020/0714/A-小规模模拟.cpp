#include <bits/stdc++.h>
using namespace std;
void solve(){
  int mk[30];
  int rg[14];
  memset(mk,0,sizeof(mk));
  int x;
  for(int i=0;i<14;i++){
    cin>>x;
    rg[i]=x;
    mk[x]++;
  }
  int nanani=0,yo=0;
  for(int i=1;i<=27;i++){
    if(mk[i]==2)nanani++;
  }
  if(nanani==7){
    cout<<1<<endl;
    return;
  }
  auto f=[&](int x){
    int duo=0,kuo=0;
    int a[2]={rg[x],rg[x+1]};
    if(a[0]!=a[1])return -1;
    a[0]=a[0]%9;
    a[1]=a[1]%9;
    if(a[0]==1||a[0]==0||a[1]==1||a[0]==0)kuo++;
    vector<int> b;
    for(int i=0;i<14;i++){
      if(rg[i]%9==0||rg[i]%9==1)duo=1;
      if(i==x||i==x+1)continue;
      b.push_back(rg[i]);
    }
    int koko=0,sho=0;
    for(int i=0;i<12;i+=3){
      int flag=0;
      if(b[i]==b[i+1]&&b[i+1]==b[i+2])koko++;
      if((b[i]+1==b[i+1])&&(b[i+1]+1==b[i+2]))if(
        (b[i]>=1&&b[i+2]<=9)||
        (b[i]>=10&&b[i+2]<=18)||
        (b[i]>=19&&b[i+2]<=27)
      )sho++;
      for(int j=i;j<i+3;j++)if(b[j]%9==1||b[j]%9==0)flag=1;
      kuo+=flag;
    }
    if(koko+sho!=4)return -1;
    if(
      (duo==0)||
      (kuo==5)||
      koko==4||
      sho==4
      )return 1;
    int nums=0;
    for(int i=0;i<9;i+=3){
      if(b[i]==b[i+1]&&b[i+1]==b[i+2])if(i==6||b[i]+1==b[i+3])nums++;
    }
    if(nums==3){
      if(b[9]+1==b[10]&&b[10]+1==b[11]){
        return 1;
      }
    }
    return -1;
  };
  for(int p=0;p<13;p++){
    if(f(p)==1){
      cout<<1<<endl;
      return;
    }
  }
  cout<<0<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}