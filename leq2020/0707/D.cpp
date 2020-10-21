#include <bits/stdc++.h>
using namespace std;
vector<int> s;
vector<int> A;
void solve () {
  int n, ins;
  cin >> n;
  s.push_back(0);
  A.resize(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> ins;
    s.push_back(ins + s[i]);
  }
  A[0] = 0;
  for (int cur = 1; cur <= n; cur++) {
    A[cur] = 0x3f3f3f3f;
    for (int lst = 0; lst < cur; lst++) {
      A[cur] = min(A[cur], A[lst] + s[n] - s[cur]);
      A[lst] += s[cur] - s[lst];
    }
  }
  cout << A[n] <<endl;
}
int main () {
  int cases;
  cin >> cases;
  while (cases--) {
    s.clear();
    A.clear();
    solve();
  }
  return 0;
}
