#include <bits/stdc++.h>
#define SORT(T) sort((T).begin(),(T).end())
using namespace std;
void solve(){
  int n,s,f;
  cin>>n>>s>>f;
  int uf=n-f;
  vector<int> T(n);
  for(int i=0;i<n;i++)cin>>T[i];
  int k;
  cin>>k;
  vector<int> P(k);
  for(int i=0;i<k;i++)cin>>P[i];
  sort(T.begin(),T.begin()+f);
  sort(T.begin()+f,T.end());
  int l=max(0,s-uf);
  int r=min(f,s)+1;
  auto test=[&](int x){
    int maxn=T[n-s+x-1]; // T[f+n-f-(s-x)-1];
    for(int i=0;i<k-f-(s-x);i++){
      maxn=max(maxn,T[k-s+x-i-1] // f+(n-f-(s-x))-i-1
                    +
                    P[i]);
    }
    for(int i=0;i<x;i++){
      int now=T[f-i-1]+(k-x+i<0?0:P[k-x+i]);
      if(now<maxn)return false;
    }
    return true;
  };
  while(l<r-1){
    int x=(r+l)/2;
    if(test(x)) l=x;
    else r=x;
  }
  cout<<l<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}
