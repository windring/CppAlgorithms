#include <bits/stdc++.h>
using namespace std;
const int nmax=1e3+5;
int n,m;
struct Point{int x,y;}ps[nmax],ch[nmax];
int cross(const Point &o,const Point &a,const Point &b){ // 逆时针为正
  // return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
  // return a.x*b.y-a.x*o.y-o.x*b.y+o.x*o.y-a.y*b.x+a.y*o.x+o.y*b.x-o.y*o.x;
  return a.x*b.y - a.x*o.y - o.x*b.y - a.y*b.x + a.y*o.x + o.y*b.x;
}
int length2(const Point &a,const Point &b){ // 距离的平方
  // return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
  return a.x*a.x-2*a.x*b.x+b.x*b.x+a.y*a.y-2*a.y*b.y+b.y*b.y;
}
bool islb(const Point &a,const Point &b){ // a是否在b左下方
  return a.y<b.y||a.y==b.y&&a.x<b.x;
}
bool isfar(const Point &o,const Point &a,const Point &b){
  return length2(a,o)>length2(b,o);
}
int Jarvis_march(){ // 求凸包到ch
  int start=0;
  for(int i=0;i<n;i++)if(islb(ps[i],ps[start]))start=i;
  int m=0; // 凸包定点数
  ch[m]=ps[start];
  for(m=1;1;m++){
    int next=start;
    for(int i=0;i<n;i++){
      int c=cross(ch[m-1],ps[i],ps[next]);
      if(c>0 // 逆时针
         ||c==0&&isfar(ch[m-1],ps[i],ps[next]) // 同一直线但更远
        )next=i;
    }
    if(next==start)return m;
    ch[m]=ps[next];
  }
}
int ternary_search(int a,int b,int l,int r){ // 因为凸包是顺序的，所以可以用三元搜索
  int c1=(2*l+r)/3;
  int c2=(l+2*r)/3;
  if(r-l<3){
    return cross(ch[a],ch[c2%m],ch[b]);
  }
  else if(cross(ch[a],ch[c1%m],ch[b])>cross(ch[a],ch[c2%m],ch[b]))
    return ternary_search(a,b,l,c2);
  else
    return ternary_search(a,b,c1,r);
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>ps[i].x>>ps[i].y;
  }
  int ans=0;
  m=Jarvis_march();
  for(int i=0;i<m;i++)
    for(int j=i+1;j<m;j++){
      int l=ternary_search(i,j,i,j);
      int r=ternary_search(j,i,j,i+m);
      ans=max(ans,l+r);
    }
  if(ans%2) cout<<ans/2<<".5"<<endl;
  else cout<<ans/2<<endl;
}
int main(){
  int cases;
  cin>>cases;
  while(cases--)solve();
  return 0;
}