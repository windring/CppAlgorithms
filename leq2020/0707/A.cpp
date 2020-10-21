#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{ll n,t;};
vector<node> factorization(ll n){
  vector<node> p;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      int t=0;
      while(n%i==0){
        n/=i;
        t++;
      }
      p.push_back(node{i,t});
    }
  }
  if(n>1)p.push_back(node{n,1});
  return p;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--){
    ll n,k;
    cin>>n>>k;
    vector<node> ns=factorization(n);
    vector<node> ks=factorization(k);
    int t=0;
    int flag=0;
    for(int i=0;i<ns.size();i++){
      int j=i;
      if(j>=ks.size()){flag=1;break;}
      if(ns[i].n!=ks[j].n){
        while(j<ks.size()&&ns[i].n!=ks[j].n)j++;
      }
      if(j==ks.size()){flag=1;break;}
      double x=double(ns[i].t)/double(ks[j].t);
      int tt=x;
      if(x>double(tt))tt++;
      t=max(t,tt);
    }
    if(flag){
      cout<<"unbounded"<<endl;
      continue;
    }
    cout<<t<<endl;
  }
  return 0;
}
