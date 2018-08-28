#include <bits/stdc++.h>
using namespace std;
struct line{int x1,y1,x2,y2,type;};
const int inf=0x3f3f3f3f;
enum{r,t,b,l}; // 讲究
void solve(){
  int n;
  cin>>n;
  vector<int> xs(n),ys(n);
  vector<line> lines,tops,bots;
  for(int i=0;i<n;i++){
    cin>>xs[i]>>ys[i];
  }
  for(int i=0;i<n;i++){
    int j=(i+1)%n;
    if(xs[j]>xs[i]){
      lines.push_back(line{xs[i],ys[i],xs[j],ys[j],t});
      tops.push_back(line{xs[i],ys[i],xs[j],ys[j],t});
    }else if(xs[j]<xs[i]){
      lines.push_back(line{xs[j],ys[j],xs[i],ys[i],b});
      bots.push_back(line{xs[j],ys[j],xs[i],ys[i],b});
    }else if(ys[j]<ys[i]) lines.push_back(line{xs[i],ys[i],xs[j],ys[j],r});
    else  lines.push_back(line{xs[j],ys[j],xs[i],ys[i],l});
  }
  sort(lines.begin(),lines.end(),[](const line &l,const line &r){
    return l.x1<r.x1 || (l.x1==r.x1&&l.type<r.type); // 在 x 相同时调整顺序
  });
  sort(tops.begin(),tops.end(),[](const line &l,const line &r){return l.y1<r.y1;});
  sort(bots.begin(),bots.end(),[](const line &l,const line &r){return l.y1<r.y1;});
  int i,j,ans;
  i=j=ans=0;
  while(1){
    int ymax=tops[i].y1,ymin=bots[j].y1;
    int xmin=inf;
    int xlimit=-inf;
    int dmax=-inf;
    for(int k=0;k<n;k++){
      line now=lines[k];
      if(now.y2<ymax&&now.y1>ymin){
        switch(now.type){
          case l:
            if(now.x1>=xlimit){
              xmin=now.x1;
            }
            break;
          case r:
            if(now.x1>=xlimit){
              dmax=max(dmax,now.x1-xmin);
            }
            xmin=inf;
            break;
          case b:case t:
            xlimit=max(xlimit,now.x2);
            break;
        }
      }
    }
    if(dmax>=ymax-ymin){
      i++;
      ans=max(ans,ymax-ymin);
    }
    if(dmax<=ymax-ymin){
      j++;
      ans=max(ans,dmax);
    }
    if(i>=tops.size()||j>=bots.size())break;
  }
  cout<<ans<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
  return 0;
}
