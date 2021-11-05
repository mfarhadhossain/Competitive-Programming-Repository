#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
inline ll LPOW(ll a, ll e)
{
	if (e == 0)
		return 1;
	if (a == 1)
		return 1;
	ll num = 1;
	while (e)
	{
		if (e % 2)
		{
			num = num * a;
		}
		e /= 2;
		a = a * a;
	}
	return num;
}
ll sod(ll x) {
	if (x < 10)return x;
	return (x % 10) + sod(x / 10);
}
ll f(ll n) {
	while (n >= 10) {
		n = sod(n);
	}
	return n;
}
void solve() {
	for (int a = 2; a <= 10; a++) {

		for (int b = 0; b <= 10; b++) {
			cout << a*b << " " << b << " = " << f(LPOW(a * b, b)) << endl;
		}
	}
}
int main () {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif


	solve();
	return 0;
}