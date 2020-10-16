#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* what the held will it do */
const ll maxn=1e6+6;
const ll mod=1e9+7;
vector<ll> a[maxn];
ll vis[maxn],s[maxn],c[maxn],n,ans=0;
ll dfs1(ll x){
  int size=a[x].size();
  for(int i=0;i<size;i++){
    if(vis[a[x][i]])continue;
    vis[a[x][i]]=1;
    dfs1(a[x][i]);
    s[x]+=s[a[x][i]];
  }
}
ll dfs2(ll x){
  ll ret=1,pfh=0,down=0,size0=0;
  ll size=a[x].size();
  for(int i=0;i<size;i++){
    if(vis[a[x][i]])continue;
    down=(down+s[a[x][i]]);
    ret=(ret*c[1]%mod)+(ret*s[a[x][i]]%mod);
    ret=ret%mod;
    pfh=(s[a[x][i]]*s[a[x][i]]+pfh);
  }
  for(int i=0;i<size;i++){
    if(!vis[a[x][i]])continue;
    ret=ret*(c[1]+n-1-down)%mod;
    pfh=pfh+(n-1-down)*(n-1-down);
    size0=(n-1-down)*(1+down)%mod;
    break;
  }
  pfh=(n-1)*(n-1)-pfh;
  pfh/=2;
  pfh%=mod;
  ret=(ret-(c[size-2]*pfh)%mod)%mod;
  ret+=mod;
  ret%=mod;
  ret=(ret+(c[size-1]*pfh)%mod)%mod;
  ret=(ret-c[size])%mod;
  ret+=mod;
  ret%=mod;
  ret=(ret*c[n-size-1])%mod;
  ans=ans+ret;
  ans%=mod;
  ans=(ans-c[n-2]*size0)%mod;
  ans+=mod;
  ans%=mod;
  for(int i=0;i<size;i++){
    if(vis[a[x][i]])continue;
    vis[a[x][i]]=1;
    dfs2(a[x][i]);
  }
  return 0;
}
int main(){
  cin>>n;
  ll x,y;
  for(int i=1;i<n;i++){
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  c[0]=1;
  c[1]=19260817;
  for(int i=1;i<=n;i++)s[i]=1;
  for(int i=2;i<=n;i++)c[i]=(c[i-1]*c[1])%mod;
  memset(vis,0,sizeof(vis));
  vis[1]=1;
  dfs1(1);
  memset(vis,0,sizeof(vis));
  vis[1]=1;
  dfs2(1);
  ans=ans%mod+mod;
  ans=ans%mod;
  cout<<ans<<endl;
  return 0;
}