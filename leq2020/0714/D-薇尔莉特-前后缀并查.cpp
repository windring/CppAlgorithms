#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+3;
const int maxm=1e4+4;
int f1[maxm][maxn];
int f2[maxm][maxn];
int ff[maxn];
int rt[maxm][2];
int vis[maxn];
int Find(int *f,int x){
  return f[x]==x?x:f[x]=Find(f,f[x]);
}
int Union(int *f,int x,int y){
  int i=Find(f,x),j=Find(f,y);
  if(i==j)return -1;
  return f[i]=f[j]; // 因为有点复杂，所以不做 rank 压缩
}
int main(){
  int n,m;
  // cin>>n>>m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    // cin>>rt[i][0]>>rt[i][1];
    scanf("%d%d",&rt[i][0],&rt[i][1]);
  }
  for(int i=1;i<=n;i++)f1[0][i]=f2[m+1][i]=i;
  for(int i=1;i<=m;i++){
    memcpy(f1[i],f1[i-1],sizeof(f1[i-1]));
    Union(f1[i],rt[i][0],rt[i][1]);
  }
  for(int i=m;i>=1;i--){
    memcpy(f2[i],f2[i+1],sizeof(f2[i+1]));
    Union(f2[i],rt[i][0],rt[i][1]);
  }
  int d;
  // cin>>d;
  scanf("%d",&d);
  int l,r;
  for(int i=0;i<d;i++){
    // cin>>l>>r;
    scanf("%d%d",&l,&r);
    memcpy(ff,f1[l-1],sizeof(f1[l-1]));
    memset(vis,0,sizeof(vis));
    for(int j=1;j<=n;j++){
      int x=j;
      int y=Find(f2[r+1],x);
      Union(ff,x,y);
    }
    for(int j=1;j<=n;j++)vis[Find(ff,j)]++;
    cout<<*max_element(vis,vis+maxn)<<endl;
  }
  return 0;
}