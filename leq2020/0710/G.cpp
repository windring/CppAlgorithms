#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  cin>>n;
  int ans;
  double maxn=0;
  double a,b,c;
  for(int i=0;i<n;i++){
    cin>>a>>b>>c;
    double now=c+b*b/4.0/a;
    if(now>maxn){
      maxn=now;
      ans=i+1;
    }
  }
  cout<<ans<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}