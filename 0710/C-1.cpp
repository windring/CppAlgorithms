#include <bits/stdc++.h>
using namespace std;
const int nmax=1e3+5;
int n,m;
struct Point{int x,y;}ps[nmax];
int cross(const Point &a,const Point &b,const Point &c){
  return a.x*b.y-b.x*a.y+b.x*c.y-c.x*b.y+c.x*a.y-a.x*c.y;
}
bool islb(const Point &a,const Point &b){ // a是否在b左下方
  return a.x<b.x;
}
int Jarvis_march(){ // 求凸包到ch
	int k, i, j = 0;
	for (int i = 1; i < n; i++)if(islb(ps[i],ps[j]))j=i;
	swap(ps[0],ps[j]);
	for (k = 1; true; k++){
		j = (k==1?1:0);
		for (int i = 0; i < n; i++)
			if (cross(ps[k-1], ps[i], ps[j]) > 0)
				j = i;
		if (j == 0)
			return k;
		swap(ps[k],ps[j]);
	}
}
int ternary_search(int a,int b,int l,int r){ // 因为凸包是顺序的，所以可以用三元搜索
  int c1=(2*l+r)/3;
  int c2=(l+2*r)/3;
  if(r-l<3){
    return cross(ps[a],ps[c2%m],ps[b]);
  }
  else if(cross(ps[a],ps[c1%m],ps[b])>cross(ps[a],ps[c2%m],ps[b]))
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