#include <bits/stdc++.h>
/* what the fuck this do */
using namespace std;
typedef long long ll;
const ll maxn=1e3+3;
const ll mod=1e9+7;
int f[maxn];
vector<ll> v[maxn],c[maxn];
ll dp[maxn][maxn];
ll n,len;
string str;
string x="abcdefghijklmnopqrstuvwxyz0123456789";
//        abcdefghijklmnopqrstuvwxyz0123456789
void getFail(){ // 拿到 next 数组
  f[0]=f[1]=0;
  for(int i=1;i<len;i++){
    ll j=f[i];
    while(j&&str[i]!=str[j])j=f[j];
    f[i+1]=str[i]==str[j]?j+1:0;
  }
}
void addedge(ll a,ll b){
  if(a==len||b==len)return;
  if(v[a].size())if(v[a].size()==b){
    c[a][0]++; // 已经有 b 个位被匹配过，并且这一次要匹配的是 b 位。
    return;
  }
  v[a].push_back(b); // 前 a 位的 b 位与 x[j] 匹配。
  c[a].push_back(1); // 匹配++
}
int main(){
  cin>>str;
  cin>>n;
  len=str.length();
  getFail();
  for(int i=0;i<len;i++){
    for(int j=0;j<36;j++){
      int k=i;
      while(k&&str[k]!=x[j])k=f[k];
      if(str[k]==x[j])k++;
      addedge(i,k); // 前 i 位最后一个与 x[j] 匹配的。 没有为 0 ，否则位数 ++。
    }
  }
  dp[0][0]=1;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<len;j++){
      for(int k=0;k<v[j].size();k++){
        int now=v[j][k]; // 前 j 位与 模式串某位最后一位匹配的指针
        dp[i+1][now]+=dp[i][j]*c[j][k]; // *匹配了多少次
        dp[i+1][now]%=mod;
      }
    }
  }
  for(int i=0;i<36;i++){
    ll ans=0;
    for(int j=0;j<len;j++){
      int k=j;
      while(k&&str[k]!=x[i])k=f[k];
      if(str[k]==x[i])k++;
      if(k!=len){
        ans+=dp[n-1][j];
        ans%=mod;
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}