#include <bits/stdc++.h>
using namespace std;
struct V{
  int x,y;
};
struct cmp{
  bool operator()(const V &l,const V &r){
    if (l.x!=r.x) {
      return l.x<r.x;
    }
    return l.y<r.y;
  }
};
map<struct V,struct V,cmp> Lmp;
map<struct V,struct V,cmp> Rmp;
void solve(){
  V pos={0,0};
  V dir={1,0};
  V minv={0,0};
  V maxv={0,0};
  vector<V> road;
  road.push_back(pos);
  string str;
  cin>>str;
  int s=str.size();
  for(int i=0;i<s;i++){
    // cout<<str[i]<<endl;
    if(str[i]=='F'){
      // dir no change
    }
    if(str[i]=='B'){
      dir.x=0-dir.x;
      dir.y=0-dir.y;
    }
    if(str[i]=='L'){
      dir=Lmp[dir];
    }
    if(str[i]=='R'){
      dir=Rmp[dir];
    }
    pos.x+=dir.x;
    pos.y+=dir.y;
    minv.x=min(minv.x,pos.x);
    minv.y=min(minv.y,pos.y);
    maxv.x=max(maxv.x,pos.x);
    maxv.y=max(maxv.y,pos.y);
    road.push_back(pos);
  }
  int w=maxv.x-minv.x+1;
  int h=maxv.y-minv.y+1;
  // cout<<"w:"<<w<<","<<"h:"<<h<<endl;
  vector<string> ans(h,string(w,'#'));
  s=road.size();
  for(int i=0;i<s;i++){
    // cout<<"dk:"<<i<<endl;
    // cout<<road[i].y+(-minv.y)<<","<<road[i].x+(-minv.x)<<endl;
    ans[road[i].y+(-minv.y)][road[i].x+(-minv.x)]='.';
  }
  // cout<<"end this"<<endl;
  s=ans.size();
  cout<<h+2<<" "<<w+1<<endl;
  cout<<string(w+1,'#')<<endl;
  for(int i=0;i<s;i++){
    cout<<ans[i];
    cout<<"#"<<endl;
  }
  cout<<string(w+1,'#')<<endl;
}
int main(){
  Lmp[V{0,1}]=V{1,0};
  Lmp[V{0,-1}]=V{-1,0};
  Lmp[V{1,0}]=V{0,-1};
  Lmp[V{-1,0}]=V{0,1};
  Rmp[V{0,1}]=V{-1,0};
  Rmp[V{0,-1}]=V{1,0};
  Rmp[V{1,0}]=V{0,1};
  Rmp[V{-1,0}]=V{0,-1}; 
  int cases;
  cin>>cases;
  cout<<cases<<endl;
  for(int i=0;i<cases;i++){
    solve();
  }
  return 0;
}