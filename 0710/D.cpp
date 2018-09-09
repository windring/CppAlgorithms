#include <bits/stdc++.h>
using namespace std;
const int len=1e5+5;
int mp[len][4];
int sn[len][2];
void solve(){
  int n,g;
  cin>>n>>g;
  g--;
  memset(sn,0,sizeof(sn));
  for(int i=0;i<n;i++){
    for(int j=0;j<4;j++){
      cin>>mp[i][j];
      mp[i][j]--;
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){ // 搜索每一个节点
    for(int j=0;j<2;j++){ // 搜索互相垂直的两个方向
      if(sn[i][j%2])continue;
      bool flag=false;
      while(sn[i][j%2]==0){
        int k=mp[i][j];
        sn[i][j%2]=1;
        if(i==g)flag=true;
        int l;
        for(l=0;mp[k][l]!=i;l++);
        i=k;
        j=l^2; // 0 <-> 2, 1 <-> 3
      }
      if(!flag)ans++;
    }
  }
  cout<<ans<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}