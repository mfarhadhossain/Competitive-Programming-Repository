#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e5 + 7, MOD = 1e9 + 7;
int A[MAX], TREE[4 * MAX];

void build(int node, int l, int r) {
	if (l == r) {
		TREE[node] = A[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1  , mid + 1, r);
}
void update(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return;
	if (l >= L && r <= R) {
		TREE[node] ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * node  , l    , mid, L, R);
	update(2 * node + 1, mid + 1, r  , L, R);
}
ll query(int node, int l, int r, int pos) {
	if (l > pos || r < pos)return 0;
	if (l == r) {
		return TREE[node];
	}
	int mid = (l + r) / 2;
	if (pos <= mid)
		return query(2 * node  , l    , mid, pos)^TREE[node];
	else
		return query(2 * node + 1  , mid + 1, r, pos)^TREE[node];
}
void solve() {
	string s; cin >> s;

	int n = s.size();

	for (int i = 0; i < n; i++) {
		A[i + 1] = s[i] - '0';
	}
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		char type;
		cin >> type;
		if (type == 'I') {
			int l, r; cin >> l >> r;
			update(1, 1, n, l, r);
		}
		else {
			int idx; cin >> idx;
			cout << query(1, 1, n, idx) << endl;
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

	int t = 1, n, k; cin >> t;
	for (int tc = 1 ; tc <= t; tc++) {
		//if (t > 1)cout << "\n";
		cout << "Case " << (tc) << ":\n";
		solve();
	}
	return 0;
}