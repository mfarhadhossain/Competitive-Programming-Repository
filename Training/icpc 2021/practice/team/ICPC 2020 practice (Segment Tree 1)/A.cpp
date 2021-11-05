#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
#define endl "\n"
int A[MAX];
ll TREE[4 * MAX];
void build(int node, int l, int r) {
	if (l == r) {TREE[node] = A[l]; return;}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	TREE[node] = min(TREE[node * 2] , TREE[2 * node + 1]);
}
void update(int node, int l, int r, int pos) {
	if (l > pos || r < pos)return;
	if (l == r) {TREE[node] = A[l]; return;}
	int mid = (l + r) / 2;
	if (pos <= mid)update(2 * node  , l    , mid, pos);
	else        update(2 * node + 1, mid + 1, r  , pos);
	TREE[node] = min(TREE[node * 2] , TREE[2 * node + 1]);
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return MOD;
	if (l >= L && r <= R) {return TREE[node];}
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R);
	ll y = query(2 * node + 1, mid + 1, r  , L, R);
	return min(x , y);
}
void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build(1, 1, n);
	while (q--) {
		int l, r; cin >> l >> r;

		cout << query(1, 1, n, l, r) << endl;
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
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case " << tc << ":\n";
		solve();
	}
	return 0;
}