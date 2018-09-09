#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll mp[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,
       16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
int n,m;
int count(ll k){
  int ans=0;
  while(k>0){
    ans+=k%2;
    k=k>>1;
  }
  return ans;
}
ll deal(string &str){
  ll r=0;
  int s=str.size();
  for(int i=0;i<s;i++){
    r=r*2+(str[i]-'0');
  }
  return r;
}
void trans(ll t){
  // cout<<t<<endl;
  string ans="";
  for(int i=0;i<m;i++){
    ans=char(t%2+'0')+ans;
    // cout<<"["<<ans<<","<<t<<"]";
    t=t>>1;
  }
  cout<<ans<<endl;
}
void solve(){
  cin>>n>>m;
  string ins;
  int inr;
  vector<ll> dump;
  vector<int> nums;
  ll t;
  for(int i=0;i<n;i++){
     cin>>ins;
     cin>>inr;
     dump.push_back(deal(ins));
     nums.push_back(inr);
     // cout<<dump[i]<<endl;
     // trans(dump[i]);
  }
  int ans=0;
  for(ll i=0;i<=mp[m]-1;i++){
    int flag=0;
    for(int j=0;j<n;j++){
      if(count(dump[j]&i)+count(((mp[m]-1)-dump[j])&((mp[m]-1)-i))!=nums[j]){
        flag=1;
        break;
      }
    }
    if(flag==0){
      t=i;
      ans++;
    }
  }
  if(ans==1){
    trans(t);
    return;
  }
  cout<<ans<<" solutions"<<endl;
  return;
}
int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    solve();
  }
  return 0;
}
  
  
  
  
