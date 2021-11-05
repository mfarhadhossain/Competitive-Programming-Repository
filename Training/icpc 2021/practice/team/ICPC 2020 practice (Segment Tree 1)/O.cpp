#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int A[MAX];
ll TREE[4 * MAX];
void build(int node, int l, int r) {
	if (l == r) {TREE[node] = A[l]; return;}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	TREE[node] = __gcd(TREE[node * 2] , TREE[2 * node + 1]);
}
void update(int node, int l, int r, int pos) {
	if (l > pos || r < pos)return;
	if (l == r) {TREE[node] = A[l]; return;}
	int mid = (l + r) / 2;
	if (pos <= mid)update(2 * node  , l    , mid, pos);
	else        update(2 * node + 1, mid + 1, r  , pos);
	TREE[node] = __gcd(TREE[node * 2] , TREE[2 * node + 1]);
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return 0;
	if (l >= L && r <= R) {return TREE[node];}
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R);
	ll y = query(2 * node + 1, mid + 1, r  , L, R);
	return __gcd(x , y);
}
void solve() {
	int n, q; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build(1, 1, n);
	cin >> q;
	while (q--) {
		int type, l, r; cin >> type >> l >> r;
		if (type == 1) {
			cout << query(1, 1, n, l, r) << endl;
		}
		else {
			A[l] = r;
			update(1, 1, n, l);
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

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		solve();
	}
	return 0;
}