// program to find number of on light bulbs in a range
// range query, range update
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
ll A[MAX], lazy[4 * MAX], TREE[4 * MAX];
void propagate(int node, int L, int R) {
	int mid = (L + R) / 2;

	TREE[node] += (R - L + 1) * 1LL * lazy[node];

	lazy[node * 2] += lazy[node];
	lazy[node * 2 + 1] += lazy[node];
	lazy[node] = 0;
}
void build(int node, int l, int r) {
	if (l == r) {
		lazy[node] = 0;
		TREE[node] = A[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	TREE[node] = TREE[node * 2] + TREE[2 * node + 1];
}
void update(int node, int l, int r, int L, int R, ll val) {
	if (l > R  || r < L)return;
	propagate(node, l, r);
	if (l >= L && r <= R) {
		lazy[node] += val;
		propagate(node, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * node  , l    , mid, L, R, val);
	update(2 * node + 1, mid + 1, r  , L, R, val);
	TREE[node] = TREE[node * 2] + TREE[2 * node + 1];
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return 0;

	propagate(node, l, r);

	if (l >= L && r <= R) {
		propagate(node, l, r);
		return TREE[node];
	}
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R);
	ll y = query(2 * node + 1, mid + 1, r  , L, R);
	return x + y;
}
void solve() {
	int n, q; cin >> n >> q;
	// for (int i = 1; i <= n; i++) {
	// 	cin >> A[i];
	// }
	// build(1, 1, n);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 0) { // update
			ll val; cin >> val;
			update(1, 1, n, l + 1, r + 1, val);
		}
		else {
			cout << query(1, 1, n, l + 1, r + 1) << endl;
		}
	}
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1 ; tc <= t; tc++) {

		cout << "Case " << tc << ":\n";
		solve();

		memset(lazy, 0, sizeof lazy);
		memset(TREE, 0, sizeof TREE);
	}
	return 0;
}