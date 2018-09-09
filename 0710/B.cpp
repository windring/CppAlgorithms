#include <bits/stdc++.h>
using namespace std;
const int len=3600+5;
const int tmax=3600;
int bs[16];
int seen[len];
int s[len];
void solve(){
  int n,t;
  cin>>n>>t;
  for(int i=0;i<n;i++)cin>>bs[i];
  memset(s,0,sizeof(s));
  memset(seen,0,sizeof(seen));
  queue<int> que;
  que.push(0);
  seen[0]=1;
  while(!que.empty()){
    int k=que.front();
    que.pop();
    for(int i=0;i<n;i++){
      int k2=min(tmax,max(0,k+bs[i]));
      if(seen[k2])continue;
      seen[k2]=1;
      que.push(k2);
      s[k2]=s[k]+1;
    }
  }
  int ans;
  for(ans=t;!seen[ans];ans++);
  cout<<s[ans]<<" "<<ans-t<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}