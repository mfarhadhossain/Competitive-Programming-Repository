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
const int MAX = 1e7 + 7, mod = 1e9 + 7;
ll prefix[MAX];
bool isprime[MAX + 1000];
int primes[MAX], id; // for <=10^6
void sieve()
{
	primes[0] = 2;
	id++;
	for (int i = 4; i <= MAX + 100; i += 2) isprime[i] = true; // is not a prime
	for (int i = 3; i <= MAX + 100; i += 2)
	{
		if (isprime[i] == false)
		{
			primes[id++] = i;
			if (i + i <= MAX)
				for (int j = i + i; j <= 100 + MAX; j += i)
					isprime[j] = true;
		}
	}
}
ll sod(ll n)
{
	ll res = 1;
	for (int i = 0; i < id && primes[i] <= n; i++) {
		ll curr_sum = 1;
		ll curr_term = 1;
		while (n % primes[i] == 0) {
			n = n / primes[i];

			curr_term *= primes[i];
			curr_sum += curr_term;
		}
		res *= curr_sum;

	}
	if (n >= 2)
		res *= (1LL + n);
	return res;
}
void precal() {
	prefix[1] = 1;
	ll ok = 0;
	for (int i = 2; i <= 1000000; i++) {
		prefix[i] = sod(i);
		ok = max(ok, prefix[i] - prefix[i - 1]);
	}
	cout << ok << endl;
}
void solve() {
	ll c; cin >> c;

}
int main () {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	sieve();
	precal();
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++) {
	// 	//cout << "Case #" << tc << ": ";
	// 	//cout << "Case " << tc << ": ";
	// 	solve();
	// }
	return 0;
}