#include<bits/stdc++.h>
using namespace std;
int gen(int idx, int curr, std::vector<int> a, int N) {
	if (idx == N) {
		if (curr % 360 == 0)return 1;
		return 0;
	}
	int ret = 0;
	ret = gen(idx + 1, curr + a[idx], a, N);
	ret |= gen(idx + 1, curr - a[idx], a, N);
	return ret;
}
void solve() {
	int N;
	cin >> N;
	std::vector < int > a(N);

	for (int i = 0; i < N; i++) cin >> a[i];
	if (gen(0, 0, a, N)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
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
	while (t--)solve();
	return 0;
}