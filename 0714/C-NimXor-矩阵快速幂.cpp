#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
struct mat{ll a[4][4];};
mat matmul(mat le,mat ri){
  mat ret;
  for(int r=0;r<4;r++){
    for(int c=0;c<4;c++){
      ll tmp=0;
      for(int i=0;i<4;i++){
        tmp=(le.a[r][i]*ri.a[i][c])%mod+tmp;
        tmp=tmp%mod;
      }
      ret.a[r][c]=tmp;
    }
  }
  return ret;
}
mat powmat(mat dear,ll x){
  mat ret;
  ll tmp[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
  memcpy(ret.a,tmp,sizeof(tmp));
  while(x){
    if(x&1)ret=matmul(ret,dear);
    dear=matmul(dear,dear);
    x/=2;
  }
  return ret;
}
ll pow2(ll x){
  ll a=2;
  ll ret=1;
  while(x){
    if(x&1)ret=ret*a%mod;
    a=a*a%mod;
    x/=2;
  }
  return ret;
}
int main(){
  int n;
  cin>>n;
  mat a;
  ll tmp[4][4]={{1,0,1,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}};
  memcpy(a.a,tmp,sizeof(tmp));
  ll right[4]={9,6,4,2};
  if(n<5){
    cout<<pow2(n)-right[4-n]<<endl;
    return 0;
  }
  ll ans=pow2(n);
  mat b=powmat(a,n-4);
  /*
  for(int r=0;r<4;r++){
    for(int c=0;c<4;c++){
      cout<<b.a[r][c]<<" ";
    }
    cout<<endl;
  }
  */
  ll c=0;
  for(int i=0;i<4;i++){
    c=(b.a[0][i]*right[i])%mod+c;
    c=c%mod;
  }
  ans=ans-c;ans=ans%mod;ans=ans+mod;ans=ans%mod;
  cout<<ans<<endl;
  return 0;
}