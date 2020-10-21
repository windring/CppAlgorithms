#include <bits/stdc++.h>
using namespace std;
const int len=1e3+3;
const int upper=2e2;
int o[len][3];
int a[2][len];
int main(){
  int n,m,k,l;
  memset(a,0,sizeof(a));
  cin>>n>>m>>k>>l;
  m+=100;k+=100;l+=100;
  for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>o[i][j];
  int th=0;
  for(int i=0;i<=l;i++)a[th][i]=-1;
  for(int i=k;i<=upper;i++)a[th][i]=1;
  for(int i=n-1;i>=0;i--){
    int nth=!th;
    int x=1,y=0,z=-1; // Koutarou, to good end
    if(i%2){ // Sena, to bad end
      x=-1;y=0;z=1;
    }
    for(int j=0;j<=upper;j++){
      int n1=j+o[i][0]>200?200:j+o[i][0];
      int n2=j-o[i][1]<0?0:j-o[i][1];
      int n3=200-j;
      a[nth][j]=(o[i][0]&&a[th][n1]==x)||(o[i][1]&&a[th][n2]==x)||(o[i][2]&&a[th][n3]==x)?x:
                (o[i][0]&&a[th][n1]==y)||(o[i][1]&&a[th][n2]==y)||(o[i][2]&&a[th][n3]==y)?y:z;
    }
    th=!th;
  }
  int ans=a[th][m];
  if(ans==0){
    cout<<"Normal Ending"<<endl;
  }else if(ans==1){
    cout<<"Good Ending"<<endl;
  }else{
    cout<<"Bad Ending"<<endl;
  }
  return 0;
}