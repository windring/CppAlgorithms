#include <bits/stdc++.h>
using namespace std;
int main () {
    int x;
    cin >> x;
    for (int i = 0; i < x; i++) {
        int t;
        cin >> t;
        int q = t / 10;
        if ((t % 10) >= 5) q++;
        if (q == 0 || q == 18 || q == 36) {
            cout << 18 << endl;
            continue;
        }
        if (q % 18 < 10) cout << 0;
        cout << q % 18 << endl;
    }
    return 0;
}