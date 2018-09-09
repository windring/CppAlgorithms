#include <bits/stdc++.h>
using namespace std;
const int nmax=1e3+5;
const int tmax=1e2+5;
const int nodesmax=(tmax+1)*nmax+1;
bool medical[nmax];
map<int,int> cap[nodesmax];
int previous[nodesmax];
int q[nodesmax];
int safty;
bool bfs(int source,int sink){
  int cur,last=1;
  memset(previous,-1,sizeof(previous));
  q[0]=source;
  previous[source]=source;
  for(int cur=0;cur<last;cur++){
    int i=q[cur];
    for(auto it=cap[i].begin();it!=cap[i].end();it++){
      int j=it->first;
      if(previous[j]<0&&it->second>0){
        previous[j]=i;
        if(j==sink){
          return true;
        }
        q[last]=j;
        last++;
      }
    }
  }
  return false;
}
int maxflow(int source,int sink,int g){
  int bot,flow=0;
  int i;
  while(flow<g&&bfs(source,sink)){
    bot=0x3f3f3f3f;
    for(int j=sink;j!=source;j=i){
      i=previous[j];
      bot=min(bot,cap[i][j]);
    }
    for(int j=sink;j!=source;j=i){
      i=previous[j];
      cap[i][j]-=bot;
      cap[j][i]+=bot;
    }
    flow+=bot;
  }
  return min(flow,g);
}
void solve(){
  int n,i,g,s,m,x,r;
  cin>>n;
  cin>>i>>g>>s;
  cin>>m;
  for(int j=0;j<m;j++){
    cin>>x;
    medical[x]=true;
  }
  safty=(s+1)*n;
  for(int j=0;j<=safty;j++)cap[j].clear();
  for(int j=0;j<n;j++){
    for(int k=0;k<s;k++){
      int i1=k*n+j;
      int i2=i1+n;
      cap[i1][i2]=g;
      cap[i2][i1]=0;
    }
  }
  cin>>r;
  int a,b,p,t;
  for(int j=0;j<r;j++){
    cin>>a>>b>>p>>t;
    for(int k=t;k<=s;k++){
      int i1=(k-t)*n+a;
      int i2=medical[b]?safty:k*n+b;
      cap[i1][i2]+=p;
      cap[i2][i1]=0;
    }
  }
  cout<<maxflow(i,safty,g)<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--){
    memset(medical,0,sizeof(medical));
    solve();
  }
  return 0;
}