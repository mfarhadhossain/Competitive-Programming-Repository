#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6 + 5, MOD = 1e9 + 7;
ll phi[4 * MAX], res[4 * MAX];
bool mark[4 * MAX];
void func()
{
	for (int i = 0; i < MAX; i++)phi[i] = i;
	//phi[1] = 1; // should be defined
	mark[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (!mark[i]) {
			for (int j = i; j < MAX; j += i)
			{
				mark[j] = 1;
				phi[j] = phi[j] / i * 1LL * (i - 1);
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << i << " " << phi[i] << endl;
	}
	for (int i = 1; i < MAX; i++) {
		res[i] += i - 1;
		for (int j = i + i; j < MAX; j += i) {
			ll ret = 1 + phi[j / i];
			ret /= 2;
			ret *= i;
			res[j] += ret;
		}
	}
}
void solve() {
	ll k; cin >> k;
	cout << res[4 * k + 1] << endl;
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
	func();
	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++) {
	// 	//cout << "Case #" << tc << ": ";
	// 	//cout << "Case " << tc << ": ";
	// 	solve();
	// }
	return 0;
}