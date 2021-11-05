#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX_SZ = 1e4 + 7, MAX = 1e6 + 7, MOD = 1e9 + 7;
ll A[MAX_SZ], lazy[4 * MAX_SZ], TREE[4 * MAX_SZ];
bool isprime[MAX + 1000];
int Primes[MAX], id; // for <=10^6
void sieve()
{
	isprime[1] = true;
	Primes[0] = 2;
	id++;
	for (int i = 4; i <= MAX + 100; i += 2)
		isprime[i] = true; // is not a prime
	for (int i = 3; i <= MAX + 100; i += 2)
	{
		if (isprime[i] == false)
		{
			Primes[id++] = i;
			if (i + i <= MAX)
				for (int j = i + i; j <= 100 + MAX; j += i)
					isprime[j] = true;
		}
	}
}
void propagate(int node, int L, int R) {
	int mid = (L + R) / 2;

	TREE[node] = (R - L + 1) * 1LL * lazy[node];

	lazy[node * 2] = (mid - L + 1) * lazy[node];
	lazy[node * 2 + 1] = (R - mid) * lazy[node];
	lazy[node] = 0;
}
void build(int node, int l, int r) {
	if (l == r) {
		lazy[node] = 0;
		if (isprime[A[l]] == false)
			TREE[node] = 1;
		else TREE[node] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * node  , l    , mid);
	build(2 * node + 1, mid + 1, r  );
	TREE[node] = TREE[node * 2] + TREE[2 * node + 1];
}
void update(int node, int l, int r, int L, int R, ll val) {
	if (l > R  || r < L)return;
	if (l >= L && r <= R) {
		lazy[node] = val;
		TREE[node] = r - l + 1;
		return;
	}
	if (lazy[node])
		propagate(node, l, r);
	int mid = (l + r) / 2;
	update(2 * node  , l    , mid, L, R, val);
	update(2 * node + 1, mid + 1, r  , L, R, val);
	TREE[node] = TREE[node * 2] + TREE[2 * node + 1];
}
ll query(int node, int l, int r, int L, int R) {
	if (l > R || r < L)return 0;
	if (l >= L && r <= R) {
		return TREE[node];
	}
	if (lazy[node])
		propagate(node, l, r);
	int mid = (l + r) / 2;
	ll x = query(2 * node  , l    , mid, L, R);
	ll y = query(2 * node + 1, mid + 1, r  , L, R);
	return x + y;
}
void solve() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	build(1, 1, n);
	while (q--) {
		int type, l, r;

		scanf("%d %d %d", &type, &l, &r);

		if (type == 0) { // update
			ll val; scanf("%d", &val);
			if (isprime[val] == false) {
				val = 1;
			}
			else {
				val = 0;
			}
			update(1, 1, n, l, r , val);
		}
		else {
			printf("%d\n", query(1, 1, n, l , r));
		}
	}
}
int main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	sieve();

	int t = 1; scanf("%d", &t);
	for (int tc = 1 ; tc <= t; tc++) {

		printf("Case %d:\n", tc);
		solve();

		memset(lazy, 0, sizeof lazy);
		memset(TREE, 0, sizeof TREE);
	}
	return 0;
}