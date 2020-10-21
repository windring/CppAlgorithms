#include <bits/stdc++.h>
using namespace std;
const int maxn=1e9;
typedef long long ll;
ll F[99];
int th;
void solve(){
  ll n;
  cin>>n;
  int a,b,c;
  for(int k=th-1;k>2;k--){
    c=(n*F[k-1-k%2])%F[k];
    if(c*F[k-1]<n){
      break;
    }
  }
  a=(n-c*F[k-1])/F[k];
  b=a+c;
  cout<<a<<" "<<b<<endl;
}
int main(){
  int cases;
  cin>>cases;
  F[1]=F[2]=1;
  for(th=3;(F[th]=F[th-1]+F[th-2])<=maxn;th++);
  while(cases--)solve();
  return 0;
}