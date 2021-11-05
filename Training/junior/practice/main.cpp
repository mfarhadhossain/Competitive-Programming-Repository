#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main ()
{
    int n; cin >> n;
    std::vector<ll> S(n), T(n), res(n), A(n), B(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    res[0] = T[0];
    ll t = res[0];
    for (int i = 1; i < n; i++) {
        res[i] = min( t + S[i - 1] , T[i]);
        t = res[i];
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}