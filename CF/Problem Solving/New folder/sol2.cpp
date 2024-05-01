#include<bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> t;
    while (t--) {
        string s, res;
        cin >> s;
        int cnt = 0;
        for (auto i : s) {
            if (i != 'X')
                res.push_back(i);
        }
        n = res.size();
        for (int i = 0; i < n - 1; i++) {
            if (res[i] != res[i + 1]) {
                cnt++;
                i++;
            }
        }

        cout << cnt * 2 << endl;
    }
    return 0;
}
