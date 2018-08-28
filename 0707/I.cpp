#include <bits/stdc++.h>
#define SORT sort(que[y].begin(),que[y].end(),[&](const int &l,const int &r){return peos[l].x<peos[r].x;})
using namespace std;
const int len=3000+5;
struct peo{int x,y,s;bool a;char d;};
int grid[len][len];
void solve(){
  int l,w,p;
  memset(grid,-1,sizeof(grid));
  cin>>l>>w>>p;
  int x,y,s;
  char d;
  vector<peo> peos;
  peos.push_back(peo{});
  vector< deque<int> > que(w+1);
  for(int i=0;i<p;i++){
    cin>>x>>y>>s>>d;
    peos.push_back(peo{x,y,s,false,d});
    que[y].push_back(i+1);
  }
  int t;
  for(t=0;p>0;t++){
    // cout<<p<<endl;
    // right first
    for(y=1;y<=w;y++){
      SORT;
      int m=que[y].size();
      for(int i=m-1;i>=0;i--){
        peo &now=peos[que[y][i]];
        if(now.d!='R')continue;
        int xnew=now.x+now.s;
        if(i<m-1 && xnew>=peos[que[y][i+1]].x){
          xnew=peos[que[y][i+1]].x-1;
          now.a=(xnew-now.x)<=((now.s+1)/2);
        }else{
          now.a=false;
        }
        if(xnew>l){
          p--;
          que[y].pop_back();
          m--;
        }else{
          now.x=xnew;
          grid[y][xnew]=t;
        }
      }
    }
    // left second
    for(y=1;y<=w;y++){
      SORT;
      int m=que[y].size();
      for(int i=0;i<m;i++){
        peo &now=peos[que[y][i]];
        if(now.d!='L')continue;
        int xnew=now.x-now.s;
        if(i>0&&xnew<=peos[que[y][i-1]].x){
          xnew=peos[que[y][i-1]].x+1;
          now.a=(now.x-xnew)<=((now.s+1)/2);
        }else{
          now.a=false;
        }
        if(xnew<1){
          p--;
          que[y].pop_front();
          i--;
          m--;
        }else{
          now.x=xnew;
          grid[y][xnew]=t;
        }
      }
    }
    // top to bottom, right, turn left
    for(y=2;y<=w;y++){ // first line cannot turn left (y--)
      int m=que[y].size();
      for(int i=m-1;i>=0;i--){
        peo &now=peos[que[y][i]];
        if(now.d!='R'||!now.a)continue;
        if(grid[y-1][now.x]==t)continue;
        now.a=false;
        grid[y][now.x]=-1;
        grid[y-1][now.x]=t;
        int id=que[y][i];
        que[y][i]=que[y][0];
        que[y].pop_front();
        que[y-1].push_back(id);
      }
    }
    // bottom to top, left turn left
    for(y=w-1;y>=1;y--){ // last line cannot turn left (y++)
      int m=que[y].size();
      for(int i=m-1;i>=0;i--){
        peo &now=peos[que[y][i]];
        if(now.d!='L'||!now.a)continue;
        if(grid[y+1][now.x]==t)continue;
        now.a=false;
        grid[y][now.x]=-1;
        grid[y+1][now.x]=t;
        int id=que[y][i];
        que[y][i]=que[y][0];
        que[y].pop_front();
        que[y+1].push_back(id);
      }
    }
    // bottom to top, right turn right
    for(y=w-1;y>=1;y--){ // last line cannot turn right
      int m=que[y].size();
      for(int i=m-1;i>=0;i--){
        peo &now=peos[que[y][i]];
        if(now.d!='R'||!now.a)continue;
        if(grid[y+1][now.x]==t)continue;
        now.a=false;
        grid[y][now.x]=-1;
        grid[y+1][now.x]=t;
        int id=que[y][i];
        que[y][i]=que[y][0];
        que[y].pop_front();
        que[y+1].push_back(id);
      }
    }
    // top to bottom, left turn right
    for(y=2;y<=w;y++){
      int m=que[y].size();
      for(int i=m-1;i>=0;i--){
        peo &now=peos[que[y][i]];
        if(now.d!='L'||!now.a)continue;
        if(grid[y-1][now.x]==t)continue;
        now.a=false;
        grid[y][now.x]=-1;
        grid[y-1][now.x]=t;
        int id=que[y][i];
        que[y][i]=que[y][0];
        que[y].pop_front();
        que[y-1].push_back(id);
      }
    }
  }
  cout<<t<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}
