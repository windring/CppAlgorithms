#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
void solve(){
  int n,ds,c;
  int a,b,s;
  cin>>n>>ds>>c;
  vector< vector<P> > G(n+1,vector<P>()); // to, cost
  priority_queue< P, vector<P>, greater<P> > que; // path sum, node
  for(int i=0;i<ds;i++){
    cin>>a>>b>>s;
    G[b].push_back(P(s,a));
  }
  vector<int> d(n+1,0x3f3f3f3f);
  que.push(P(0,c));
  d[c]=0;
  while(!que.empty()){
    P p=que.top();
    que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    int size=G[v].size();
    for(int i=0;i<size;i++){
      P e=G[v][i];
      if(d[e.second]>d[v]+e.first){
        d[e.second]=d[v]+e.first;
        que.push(P(d[e.second],e.second));
      }
    }
  }
  int ans=0;
  int time=0;
  for(int i=1;i<=n;i++){
    if(d[i]!=0x3f3f3f3f){
      ans++;
      time=max(time,d[i]);
    }
  }
  cout<<ans<<" "<<time<<endl;
}
int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    solve();
  }
  return 0;
}
