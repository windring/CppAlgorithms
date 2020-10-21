#include <bits/stdc++.h>
using namespace std;
struct node{
  int r1,r2,r3;
  /*
  bool operator < (const node &r) const {
    return this->r2 < r.r2;
  }
  */
};
struct cmp{
  bool operator()(const node &l,const node &r){
    return l.r2<r.r2;
  }
};
void solve(){
  int n;
  // cin>>n;
  scanf("%d",&n);
  vector<node> vs(n);
  for(int i=0;i<n;i++){
    // cin>>vs[i].r1>>vs[i].r2>>vs[i].r3;
    scanf("%d%d%d",&vs[i].r1,&vs[i].r2,&vs[i].r3);
  }
  sort(vs.begin(),vs.end(),[](const node &l,const node &r){
    return l.r1<r.r1;
  });
  set<node,cmp> st;
  int th=0;
  int ans=0;
  st.insert(vs[th]);
  for(th++,ans++;th<n;th++){ // 新处理apha
    auto it1=st.lower_bound(vs[th]);
    auto it2=it1; // if it1 == st.end(),it2--,r2 依然比 apha 小
    it2--; // if it1 == st.begin(),it2--不受影响
    if(
      it1==st.begin()|| // apha r2 最小
      it2->r3 > vs[th].r3 // apha r3 较小
    ){
      while(it1!=st.end() && it1->r3 > vs[th].r3){
        // 删除 it1 后 it1 将失效
        // erase(it1++)的写法是可以的
        it2=it1;
        it2++;
        st.erase(it1);
        it1=it2;
      }
      st.insert(vs[th]);
      ans++;
    }
  }
  // cout<<ans<<endl;
  printf("%d\n",ans);
}
int main(){
  int cases;
  // cin>>cases;
  scanf("%d",&cases);
  while(cases--)solve();
  return 0;
}