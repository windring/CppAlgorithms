#include <bits/stdc++.h>
using namespace std;
int st[6500+5];
void shift(string &str,int n){
  int len=str.length();
  reverse(str.begin(),str.begin()+len-n);
  reverse(str.begin(),str.end());
}
void solve(){
  int cnt=0;
  string str1,str2;
  cin>>str1>>str2;
  if(str1==str2){
    cout<<0<<endl;
    return;
  }
  string str3=str1,str4=str2;
  sort(str3.begin(),str3.end());
  sort(str4.begin(),str4.end());
  if(str3!=str4){
    cout<<"-1"<<endl;
    cout<<"-1"<<endl;
    return;
  }
  int len=str1.length();
  for(int i=0;i<len;i++){
    int o=int(str1.find(str2[i]));
    o++;
    if(o==len)continue;
    shift(str1,st[cnt++]=len-o);
    shift(str1,st[cnt++]=1);
    shift(str1,st[cnt++]=len);
  }
  cout<<cnt<<endl;
  for(int i=0;i<cnt;i++){
    cout<<st[i];
    if(i!=cnt-1) cout<<" ";
    else cout<<endl;
  }
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}