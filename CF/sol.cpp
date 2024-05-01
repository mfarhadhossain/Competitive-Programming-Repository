#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;

int dp[MAX][5];

int go(int index, int prev, int n, string &s) {
    if (index == n) {
        return 0;
    }
    if (dp[index][prev] != -1)
        return dp[index][prev];
    int ret = 0;
    int curr = -1;
    if (s[index] == 'R') {
        curr = 1;
    }
    else if (s[index] == 'G') {
        curr = 2;
    }
    else if (s[index] == 'B') {
        curr = 3;
    }
    if (curr != -1) {
        if (prev != 0 and prev != curr and curr != -1) {
            ret = max(ret, 1 + go(index + 1, 0, n, s));

        }
        if (prev == 0) {
            ret = max(ret, go(index + 1, curr, n, s));
        }
    }
    ret = max(ret, go(index + 1, prev, n, s));
    return dp[index][prev] = ret;
}
void solve() {
    memset(dp, -1, sizeof dp);

    string s; cin >> s;

    int n = s.size();

    int ret = 0;

    for (int i = 0; i < n; i++) {
        int curr = 0;
        if (s[i] == 'R') {
            curr = 1;
        }
        else if (s[i] == 'G') {
            curr = 2;
        }
        else if (s[i] == 'B') {
            curr = 3;
        }
        else {
            continue;
        }
        ret = max(ret, go(i + 1, curr, n, s));
    }
    cout << ret * 2 << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
/*
16
XRGBXGRB
RBGXGRB
GRRXGRR
X
RGBXGRBGB
RGBXGRBG
RGBXGRBGB
XXXX
RGRG
RRRRRRB
BXGXBG
RXGXBXRXG
XXX
RGGBBR
RBBGRG
XRGBGRB
*/
