#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll art=1e6+6;
ll powermod(ll a,ll b, ll mod){
  __int128 ans=1;
  __int128 aa=a;
  while(b){
    // cout<<ll(aa%mod)<<endl;
    if(b%2)ans=((ans%mod)*aa)%mod;
    aa=((aa%mod)*aa)%mod;
    b/=2;
  }
  return ans;
}
bool isprime(ll x){
  srand(time(NULL));
  for(int i=0;i<10;i++){
    ll now=rand()%20+10;
    if(powermod(now,x-1,x)!=1)return false;
  }
  return true;
}
int main(){
  ll n;
  cin>>n;
  int a[64];
  memset(a,0,sizeof(a));
  int nums=0;
  for(ll i=2;i<art;i++){ // 1e6 的范围可以接受，可以不打素数表
    if(n%i==0){
      while(n%i==0){
        n/=i;
        a[nums]++;
      }
      nums++;
    }
    if(n==1)break;
  }
  if(n>1){
    ll s=sqrt(n);
    if(s*s==n){
      a[nums]=2;
      nums++;
    }else{
      if(isprime(n)){
        a[nums]=1;
        nums++;
      }else{
        a[nums++]=1;
        a[nums++]=1;
      }
    }
  }
  ll ans=1;
  for(ll i=0;i<nums;i++){
    ans*=(a[i]+1);
  }
  cout<<ans<<endl;
  return 0;
}