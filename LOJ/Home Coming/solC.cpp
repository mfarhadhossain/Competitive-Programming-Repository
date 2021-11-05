#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {
    int n, k; cin >> n >> k;
    ll res = 0;
    vector<ll>v(n);
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pq.push(v[i]);
    }
    ll sum = 0;
    while (pq.size() > 1) {
        int tk = k - 1;
        ll x = pq.top();
        pq.pop();
        sum = 0;
        while (!pq.empty() && tk--) {
            sum += pq.top();
            pq.pop();
        }
        res += x + sum;
        pq.push(x + sum);
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}