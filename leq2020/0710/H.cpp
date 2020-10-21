#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PR;
typedef map<int,int> M;
const int maxn=1e3+3;
const int maxs=120+12;
struct edge{int to,cost;};
vector<edge> G[maxs*maxs*2];
int dis[maxs][maxn];
int ans[2*maxs*maxs];
void solve(){
  for(int i=0;i<2*maxs*maxs;i++)G[i].clear();
  memset(ans,0,sizeof(ans));
  memset(dis,0,sizeof(dis));
  int n,m,s;
  cin>>n>>m>>s;
  int t;
  cin>>t;
  int a,b,f;
  for(int i=0;i<m;i++){
    cin>>a>>b>>f;
    a--;b--;
    G[a].push_back(edge{b,f});
    G[b].push_back(edge{a,f});
  }
  int x,p;
  vector<int> X(s+1);
  vector<int> P(s+1);
  for(int i=0;i<s;i++){
    cin>>x>>p;
    x--;
    P[i]=p;
    X[i]=x;
  }
  int c,d;
  cin>>c>>d;
  c--;d--;
  P[s]=0;
  X[s]=d;
  auto dijkstra=[&](int st,int maxdis,int d[],int num){
    priority_queue< PR,vector<PR>,greater<PR> > que;
    memset(d,0x3f3f3f3f,sizeof(int)*num);
    d[st]=0;
    que.push(PR(0,st)); // route len, index
    while(!que.empty()){
      PR p=que.top();que.pop();
      int v=p.second;
      if(d[v]<p.first)continue;
      for(int i=0;i<G[v].size();i++){
        edge e=G[v][i];
        if(d[v]+e.cost<=maxdis)if(d[e.to]>d[v]+e.cost){
          d[e.to]=d[v]+e.cost;
          que.push(PR(d[e.to],e.to));
        }
      }
    }
  };
  for(int i=0;i<s;i++)dijkstra(X[i],t,dis[i],maxn);
  int cs;
  for(cs=0;X[cs]!=c;cs++);
  M T[maxs];
  T[cs][0]=0;
  for(int i=0;i<s;i++)for(int j=0;j<=s;j++){
    if(i==j)continue;
    int now=dis[i][X[j]];
    if(now>t)continue;
    T[i][P[i]<P[j]?t:now]=0;
    T[j][P[i]<P[j]?t-now:0]=0;
  }
  n=0;
  for(int i=0;i<=s;i++)for(auto it=T[i].begin();it!=T[i].end();it++)it->second=n++;
  for(int i=0;i<2*maxs*maxs;i++)G[i].clear();
  for(int i=0;i<s;i++){
    if(T[i].empty())continue;
    auto it1=T[i].begin();
    auto it2=it1;
    for(it2++;it2!=T[i].end();it1=it2++){
      G[it1->second].push_back(edge{
        it2->second,
        P[i]*(it2->first - it1->first)
      });
    }
  }
  for(int i=0;i<s;i++)for(int j=0;j<=s;j++){
    if(i==j)continue;
    int now=dis[i][X[j]];
    if(now>t)continue;
    int a=T[i][P[i]<P[j]?t:now];
    int b=T[j][P[i]<P[j]?t-now:0];
    G[a].push_back(edge{b,0});
  }
  dijkstra(T[cs][0],1<<30,ans,2*maxs*maxs);
  cout<<ans[n-1]<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}