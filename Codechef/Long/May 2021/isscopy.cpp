#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree <
//                     T,
//                     null_type,
//                     less<T>,
//                     rb_tree_tag,
//                     tree_order_statistics_node_update >;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
const int N = 4e6 + 5;

int phi[N], ans[N];
int main () {
    //ios_base::sync_with_stdio(false);

    //cin.tie(0);



    for (int i = 0; i < N; i++) {

        phi[i] = i;

        ans[i] = 0;

    }

    for (int p = 2; p < N; p++) {

        if (phi[p] == p) {

            phi[p] = p - 1;

            for (int i = 2 * p; i < N; i += p)

                phi[i] = (phi[i] / p) * (p - 1);

        }

    }
    for (int i = 0; i < 10; i++) {
        cout << i << " " << phi[i] << endl;
    }
    for (int i = 1; i < N; i++) {

        ans[i] += i - 1;

        for (int j = 2 * i; j < N; j += i) {

            ans[j] += i * ((1 + phi[j / i]) / 2);

        }

    }

    int t;

    cin >> t;

    while (t--) {

        int k;

        cin >> k;

        cout << ans[4 * k + 1] << "\n";

    }
}