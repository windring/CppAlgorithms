#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n,m;
  cin>>n>>m;
  vector<string> ins;
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    ins.push_back(s);
  }
  int b(0),w(0),dj(0),bj(0),wj(0),js(0);
  for(int i=0;i<m;i++){
    int j=0;
    while(ins[j][i]!='B')j++;
    b=j;
    while(ins[j][i]!='W')j++;
    w=j;
    if(b==0&&w==n-1&&n>3)dj++;
    else{
      if(b==0&&w>2)bj+=w-2;
      else if(w==n-1&&b<n-3)wj+=n-b-1-2;
      js+=w-b-1;
    }
  }
  bool ans=(n==4&&dj%2)||(wj>bj)||(wj>=bj-1&&js%2);
  cout<<(ans?"White":"Black")<<" wins"<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}
