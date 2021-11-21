#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int main() {
	int m; cin >> m;
	vector<int>bad(MAX), map(MAX), v;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (map[x] == 0) {
			v.push_back(x);
		}
		map[x]++;
	}
	for (int x : v) {
		for (int j = x; j < MAX; j += x)
			bad[j] += map[x];
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << m - bad[x] << endl;
	}
	return 0;
}
