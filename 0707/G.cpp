#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) {
  while(b){
    ll t=b;
    b=a%b;
    a=t;
  }
  return a;
}
void solve(){
  ll n,m,l;
  cin>>n>>m>>l;
  ll a,b;
  vector< vector<ll> > es(n);
  for(ll i=0;i<m;i++){
    cin>>a>>b;
    a--;b--;
    es[a].push_back(b);
  }
  vector<ll> cur(n),chg(n,1);
  stack<ll> stk;
  for(ll i=0;i<n;i++){
    cin>>cur[i];
    stk.push(i);
  }
  while(!stk.empty()){
    ll y=stk.top();stk.pop();
    ll gf=cur[y];
    chg[y]=0;
    for(ll x : es[y]){
      ll bf=cur[x];
      cur[x]=gcd(gf,bf);
      if(cur[x]!=bf)if(!chg[x]){
        chg[x]=1;
        stk.push(x);
      }
    }
  }
  ll ans=0;
  for(ll i : cur){
    ans+=(i==l);
  }
  cout<<ans<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}