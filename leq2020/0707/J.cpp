#include <bits/stdc++.h>
using namespace std;
struct node{int y,x;};
vector<string> mp,mpbk;
vector< vector<node> > mpr;
vector< vector<node> > mpc;
vector< vector<node> > mpm;
vector< vector<node> > mpn;
unordered_map<string,int> inmp;
int n,h,w;
void find(vector< vector<node> > &ap,const string &str){
  for(int i=0;i<ap.size();i++){
    string ins;
    for(auto x=ap[i].begin();x!=ap[i].end();x++){
      ins+=mp[(*x).y][(*x).x];
    }
    auto c=ins.find(str);
    // cout<<ins<<endl;
    if(c!=string::npos){
      // cout<<ins<<endl;
      int flag=0;
      for(int j=c;j-c<str.size();j++){
        if(mpbk[ap[i][j].y][ap[i][j].x]!='.'){
          // cout<<mpbk[ap[i][j].y][ap[i][j].x]<<endl;
          // cout<<j<<endl;
          flag=1;
        }
        mpbk[ap[i][j].y][ap[i][j].x]='.';
      }
      if(flag){
        inmp[str]++;
        // cout<<"yes"<<endl;
      }
    }
  }
  // cout<<"============="<<endl;
}
void cycle(){
  for(auto x=inmp.begin();x!=inmp.end();x++){
    find(mpr,(*x).first);
    find(mpc,(*x).first);
    find(mpm,(*x).first);
    find(mpn,(*x).first);
  }
}
void re(vector< vector<node> > &ap){
  for(int i=0;i<ap.size();i++){
    reverse(ap[i].begin(),ap[i].end());
  }
}
void res(){
  re(mpr);
  re(mpc);
  re(mpm);
  re(mpn);
}
int solve(){
  cin>>n>>h>>w;
  string ins;
  for(int i=0;i<h;i++){
    cin>>ins;
    mp.push_back(ins);
  }
  mpbk=mp;
  /*create -> map*/ 
  for(int i=0;i<h;i++){
    vector<node> ins;
    for(int j=0;j<w;j++){
      ins.push_back(node{i,j});
    }
    mpr.push_back(ins);
  }
  /*create | map*/
  for(int i=0;i<w;i++){
    vector<node> ins;
    for(int j=0;j<h;j++){
      ins.push_back(node{j,i});
    }
    mpc.push_back(ins);
  }
  /*create lefttop to rightbottom map*/
  for(int i=0;i<w+h;i++){
    vector<node> ins;
    int sy=h-i>0?h-i-1:0;
    int sx=i-h>0?i-h:0;
    for(int j=0;;j++){
      if(sy+j>=h)break;
      if(sx+j>=w)break;
      ins.push_back(node{sy+j,sx+j});
    }
    mpm.push_back(ins);
  }
  /*create righttop to leftbottom map*/
    for(int i=0;i<w+h;i++){
    vector<node> ins;
    int sx=i-h>0?i-h:0;
    int sy=i-h>=0?h-1:i;
    for(int j=0;;j++){
      if(sy-j<0)break;
      if(sx+j>=w)break;
      ins.push_back(node{sy-j,sx+j});
    }
    mpn.push_back(ins);
  }
  for(int i=0;i<n;i++){
    cin>>ins;
    inmp[ins]=0; 
  }
  cycle();
  res();
  cycle();
  int flag=0;
  for(auto x=inmp.begin();x!=inmp.end();x++){
    if((*x).second>=2){
      // cout<<(*x).first<<endl;
      cout<<"ambiguous"<<endl;
      return 0;
    }
    if((*x).second==0){
      // out<<(*x).first<<endl;
      cout<<"no solution"<<endl;
      return 0;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(mpbk[i][j]!='.'){
        cout<<mpbk[i][j];
        flag=1;
      }
    }
  }
  if(flag==1){
    cout<<endl;
  }else{
    cout<<"empty solution"<<endl;
  }
  return 0;
}
int main(){
  int test;
  cin>>test;
  for(int i=0;i<test;i++){
    mp.clear();
    mpbk.clear();
    mpr.clear();
    mpc.clear();
    mpm.clear();
    mpn.clear();
    inmp.clear();
    solve();
  }
  return 0;
}
