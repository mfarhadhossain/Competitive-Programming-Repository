#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int A[MAX];
ll neg_TREE[4 * MAX], zero_TREE[4 * MAX];
void build(int node, int l, int r) {
	if (l == r) {
		if (A[l] < 0) {
			neg_TREE[node] = 1;
		}
		else {

			neg_TREE[node] = 0;
		}

		if (A[l] == 0) {
			zero_TREE[node] = 1;
		}
		else {
			zero_TREE[node] = 0;
		}
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	neg_TREE[node] = neg_TREE[node * 2] + neg_TREE[2 * node + 1];
	zero_TREE[node] = zero_TREE[node * 2] + zero_TREE[2 * node + 1];
}
void update(int node, int l, int r, int pos) {
	if (l > pos || r < pos)return;
	if (l == r) {
		if (A[l] < 0) {
			neg_TREE[node] = 1;
		}
		else {

			neg_TREE[node] = 0;
		}

		if (A[l] == 0) {
			zero_TREE[node] = 1;
		}
		else {
			zero_TREE[node] = 0;
		}
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)update(2 * node  , l    , mid, pos);
	else        update(2 * node + 1, mid + 1, r  , pos);
	neg_TREE[node] = neg_TREE[node * 2] + neg_TREE[2 * node + 1];
	zero_TREE[node] = zero_TREE[node * 2] + zero_TREE[2 * node + 1];
}
ll query(int node, int l, int r, int L, int R, int type) {
	if (l > R || r < L)return 0;
	if (l >= L && r <= R) {
		if (type == 0) {
			return zero_TREE[node];
		}
		return neg_TREE[node];
	}
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R, type );
	ll y = query(2 * node + 1, mid + 1, r  , L, R, type);
	return x + y;
}
void solve(int n, int q) {

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	build(1, 1, n);

	string type;
	while (q--) {
		//cout << "current array: ";
		//for (int i = 1; i <= n; i++)cout << A[i] << ' ';
		//cout << endl;

		cin >> type;
		if (type == "P") {
			int l, r; cin >> l >> r;

			int z = query(1, 1, n, l, r, 0);
			int neg = query(1, 1, n, l, r, 1);
			//cout << "number of zeroes: " << z << endl;
			//cout << "number of negatives: " << neg << endl;
			if (z != 0) {
				cout << "0";
			}
			else if (neg % 2 == 0) {
				cout << "+";
			}
			else {
				cout << "-";
			}
		}
		if (type == "C") {
			int idx, val; cin >> idx >> val;
			A[idx] = val;
			update(1, 1, n, idx);
		}
	}
	cout << endl;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1, n, k; //cin >> t;
	while (cin >> n >> k) {
		//if (t > 1)cout << "\n";
		//cout << "Case " << (t++) << ":\n";
		solve(n, k);
	}
	return 0;
}