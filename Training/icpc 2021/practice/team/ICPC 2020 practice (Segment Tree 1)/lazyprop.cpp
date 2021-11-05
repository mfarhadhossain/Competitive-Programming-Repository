// program to find number of on light bulbs in a range
// range query, range update
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int A[MAX], lazy[4 * MAX], ON[MAX];
void propagate(int node, int L, int R) {
	int mid = (L + R) / 2;

	lazy[node] = 0;
	lazy[node * 2] ^= 1;
	lazy[node * 2 + 1] ^= 1;

	ON[node * 2] = (mid - L + 1) - ON[node * 2];
	ON[node * 2 + 1] = (R - mid + 1) - ON[node * 2 + 1];
}
void build(int node, int l, int r) {
	if (l == r) {
		lazy[node] = 0;
		ON[node] = A[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	ON[node] = ON[node * 2] + ON[2 * node + 1];
}
void update(int node, int l, int r, int L, int R) {
	if (l > R  || r < L)return;
	if (l >= L && r <= R) {
		lazy[node] ^= 1;
		ON[node] = (r - l + 1) - ON[node];
		return;
	}
	if (lazy[node])
		propagate(node, L, R);
	int mid = (l + r) / 2;
	update(2 * node  , l    , mid, L, R);
	update(2 * node + 1, mid + 1, r  , L, R);
	ON[node] = ON[node * 2] + ON[2 * node + 1];
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return 0;
	if (l >= L && r <= R) {
		return ON[node];
	}
	if (lazy[node])
		propagate(node, L, R);
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R);
	ll y = query(2 * node + 1, mid + 1, r  , L, R);
	return x + y;
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build(1, 1, n);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1) { // update
			update(1, 1, n, l, r);
		}
		else {
			cout << query(1, 1, n, l, r) << endl;
		}
	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; //cin >> t;
	while (t--)solve();
	return 0;
}