#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1ll<<60;
const int len=130;
ll as[len][len]={0};
ll bs[len][len]={0};
ll f[len][len][len];
int main(){
  int n,m;
  cin>>n>>m;
  memset(f,128,sizeof(f));
  for(int y=1;y<=n;y++){
    for(int x=1;x<=m;x++){
      cin>>as[x][y];
    }
  }
  for(int y=1;y<=n;y++){
    for(int x=1;x<=m;x++){
      cin>>bs[x][y];
    }
  }
  ll ans=-inf;
  f[1][1][1]=as[1][1]+bs[1][1];
  if(n==1&m==1)ans=f[1][1][1];
  for(int grids=2;grids<=m+n-1;grids++){
    for(int x1=1;x1<=grids;x1++){
      for(int x2=1;x2<=grids;x2++){
        int y1=grids+1-x1;
        int y2=grids+1-x2;
        int i=grids-1;
        f[grids][x1][x2]=max(f[i][x1-1][x2],f[grids][x1][x2]);
        f[grids][x1][x2]=max(f[i][x1][x2-1],f[grids][x1][x2]);
        f[grids][x1][x2]=max(f[i][x1][x2],f[grids][x1][x2]);
        f[grids][x1][x2]=max(f[i][x1-1][x2-1],f[grids][x1][x2]);
        if(x1==x2){
          f[grids][x1][x2]+=as[x1][y1]+bs[x1][y1];
        }else{
          f[grids][x1][x2]+=as[x1][y1]+as[x2][y2];
        }
        if(grids==n+m-1){
          if(x1>m)continue;
          if(y2>n)continue;
          ans=max(ans,f[grids][x1][x2]);
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
