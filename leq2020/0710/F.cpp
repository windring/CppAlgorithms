#include <bits/stdc++.h>
using namespace std;
const int len=1e4+4;
int n,m,k;
set<int> link[len];
int maxlen[len];
vector<int> childs[len];
int works[len];
bool red[len];
void sink(int i,int j){
  maxlen[i]=max(maxlen[i],j);
  if(link[i].size()!=1)return;
  red[i]=true;
  int next=*(link[i].begin());
  link[next].erase(i);
  childs[next].push_back(i);
  sink(next,maxlen[i]+1);
}
void solve(){
  int a,b;
  cin>>n>>m>>k;
  memset(red,0,sizeof(red));
  memset(works,0,sizeof(works));
  memset(maxlen,0,sizeof(maxlen));
  for(int i=0;i<n;i++){
    childs[i].clear();
    link[i].clear();
  }
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--;b--;
    link[a].insert(b);
    link[b].insert(a);
  }
  for(int i=0;i<n;i++){
    if(link[i].size()>1)continue;
    if(maxlen[i]>0)continue;
    sink(i,1);
  }
  int willSink=0;
  for(int i=0;i<n;i++){
    if(red[i]){
      works[willSink++]=i;
    }
  }
  sort(works,works+willSink,[&](const int &l,const int &r){return maxlen[l]<maxlen[r];});
  for(int now=willSink-1;now>=0&&k>0;now--){
    int i=works[now];
    if(maxlen[i]==0)continue;
    k--;
    int d=maxlen[i];
    willSink-=d;
    for(d--;;d--){
      maxlen[i]=0;
      if(d==0)break;
      int j;
      for(j=0;maxlen[childs[i][j]]!=d;j++);
      i=childs[i][j];
    }
  }
  cout<<willSink<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}