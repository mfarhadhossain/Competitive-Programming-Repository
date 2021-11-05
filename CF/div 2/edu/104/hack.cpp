#include "bits/stdc++.h"

using namespace std;
using LL = long long;

constexpr int N = 1e5 + 5;

void solve() {
	LL n;
	cin >> n;

	int res = 0;

	for (LL a = 3; ; a += 2) {
		LL d = a * a;
		LL b = d / 2, c = (d + 1) / 2;
		if (c > n) break;

		if (c * c - b * b == a * a) {
			res++;
		}
	}

	cout << res << "\n";
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("hackin.txt","r",stdin);
    freopen("hackout.txt","w",stdout);

	int t;
	cin >> t;

	while (t--) solve();
}


