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
const int MAX = 1e6, MOD = 1e9 + 7;
void print(deque<int>a) {
	deque<int>b = a;
	while (!b.empty()) {
		cout << b.front() << " ";
		b.pop_front();
	}

}
void solve() {
	int n, m; cin >> n >> m;
	deque<int>q;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push_back(x);
	}
	while (m--) {
		int x; cin >> x;
		stack<int>stk;
		int res = 1;
		// cout << "before: ";
		// print(q);
		// cout << endl;
		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			if (u == x) {
				cout << res << " ";
				break;
			}
			stk.push(u);
			res++;
		}
		while (!stk.empty()) {
			int u = stk.top();
			stk.pop();
			q.push_front(u);
		}
		q.push_front(x);

		// cout << "after: ";
		// print(q);
		// cout << endl;
	}
}
int main () {
	char ch = 'a' + 2;
	cout << ch << endl;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}