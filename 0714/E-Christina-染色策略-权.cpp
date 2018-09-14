#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int len=4e2+4;
ll mp[len][len];
int dir[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
struct node{
  double w;ll s;
  int x,y; // unused
};
void solve(){
  int n,m,f;
  memset(mp,0,sizeof(mp));
  cin>>n>>m>>f;
  for(int y=1;y<=n;y++){
    for(int x=1;x<=m;x++){
      cin>>mp[x][y];
    }
  }
  vector<node> que;
  for(int y=1;y<=n;y++){
    for(int x=1;x<=m;x++){
      ll w=0,ns=0;
      for(int i=0;i<4;i++){
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx<1||nx>m)continue;
        if(ny<1||ny>n)continue;
        w+=(mp[nx][ny]^mp[x][y]);
        ns++;
      }
      que.push_back(node{double(w)/double(ns),w,x,y});
    }
  }
  sort(que.begin(),que.end(),[](const node &l,const node &r){
    // return l.w>r.w;
    return l.s>r.s;
  });
  ll s[2]={0,0};
  for(int i=0;i<n*m;i++){
    s[i%2]+=que[i].s;
    // mp[que[i].x][que[i].y]=i%2;
  }
  /*
  for(int y=1;y<=n;y++){
    for(int x=1;x<=m;x++){
      cout<<mp[x][y];
    }
    cout<<endl;
  }
  */
  cout<<(s[f%2]-s[(f+1)%2])/2<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}