#include <bits/stdc++.h>
using namespace std;
const int len=2e4+5;
string str;
int sa[len],myanks[len],tmp[len],lcp[len];
int k,length; // 构造sa
void print(){
  for(int i=0;i<=str.length();i++){
    cout<<sa[i]<<" "<<myanks[i]<<" "<<lcp[i]<<" "<<str.c_str()+sa[i]<<endl;
  }
}
bool cmp_sa(const int l,const int r){
  if(myanks[l]!=myanks[r])return myanks[l]<myanks[r];
  int ll=(l+k<=length?myanks[l+k]:-1); // 长度不足，更小
  int rr=(r+k<=length?myanks[r+k]:-1); // 有效跨度比较
  return ll<rr;
}
bool construct_sa(){ // n lg^2 n
  for(int i=0;i<=length;i++){
    sa[i]=i;
    myanks[i]=i<length?str[i]:-1;
  }
  for(k=1;k<=length;k*=2){
    sort(sa,sa+length+1,cmp_sa);
    tmp[sa[0]]=0;
    for(int i=1;i<=length;i++){
      tmp[sa[i]]=tmp[sa[i-1]]+(cmp_sa(sa[i-1],sa[i])?1:0);
    }
    // for(int i=0;i<=length;i++)cout<<tmp[i]<<",";cout<<endl;
    memcpy(myanks,tmp,sizeof(int)*(length+1));
  }
}
bool construct_lcp(){ // n
  for(int i=0;i<=length;i++)myanks[sa[i]]=i;
  int h=lcp[0]=0;
  for(int i=0;i<length;i++){
    int j=sa[myanks[i]-1];
    if(h>0)h--; // j 为位，前 h-1 相等
    for(;j+h<length&&i+h<length;h++){
      if(str[j+h]!=str[i+h])break;
    }
    lcp[myanks[i]-1]=h;
  }
}
int main(){
  getline(cin,str);
  length=str.length();
  construct_sa();
  construct_lcp();
  lcp[0]=lcp[length]=-1;
  // print();
  vector<int> ans;
  for(int i=1;i<length;i++){
    int now=lcp[i];
    if(now==0){ans.push_back(1);continue;}
    int l=i,r=i;
    while(lcp[l]>=now)l--;
    while(lcp[r]>=now)r++;
    // cout<<"lr"<<l<<","<<r<<endl;
    ans.push_back(r-l);
  }
  if(ans.size()<1)ans.push_back(0);
  sort(ans.begin(),ans.end(),greater<int>());
  // for(int i=0;i<ans.size();i++)cout<<ans[i]<<",";
  vector<int> norep;
  norep.push_back(ans[0]);
  int size=ans.size();
  for(int i=1;i<size;i++){
    int lg=ans[i];
    int pr=ans[i-1];
    if(lg==pr)continue;
    norep.push_back(lg);
  }
  // for(int i=0;i<norep.size();i++)cout<<norep[i]<<",";
  vector<int> suffix;
  size=norep.size();
  suffix.push_back(0);
  for(int i=0;i<size;i++){
    int a=suffix[i]+norep[i];
    suffix.push_back(a);
  }
  // for(int i=0;i<suffix.size();i++)cout<<suffix[i]<<",";
  int q;
  cin>>q;
  int a,b;
  for(int i=0;i<q;i++){
    cin>>a>>b;
    if(b>norep.size()){
      b=norep.size();
    }
    if(a>b){
      cout<<"0"<<endl;
      continue;
    }
    cout<<suffix[b]-suffix[a-1]<<endl;
  }
  return 0;
}