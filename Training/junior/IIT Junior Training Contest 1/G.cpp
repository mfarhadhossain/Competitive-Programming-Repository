#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
    ll r1, c1, r2, c2;

    cin >> r1 >> c1;
    cin >> r2 >> c2;

    if (r1 == r2 && c1 == c2)
        cout << "0\n";
    else if (abs(r1 - r2) + abs(c1 - c2) <= 3 || r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2)
        cout << "1\n";
    else if ( (r1 + c1) % 2 == (r2 + c2) % 2)
        cout << "2\n";
    else {
        int f = 0;
        for (int i = -3; i <= 3; i++) {
            for (int j = -3; j <= 3; j++) {

                if (abs(i) + abs(j) > 3)continue;


                ll r3 = r1 + i;
                ll c3 = c1 + j;

                ll d = abs(r3 - r2) + abs(c3 - c2);

                if (d <= 3 || (r3 - c3 == r2 - c2 || r3 + c3 == r2 + c2)) {
                    cout << "2\n";
                    f = 1;
                    break;

                }
            }
            if (f)break;

        }
        if (f == 0)cout << "3\n";
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--)solve();
    return 0;
}