#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
void solve() {

}
int main () {
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	freopen("input.txt", "w", stdout);
#endif
	cout << 120 << endl;
	int  n = 5;
	std::vector<int> L;
	for (int i = 0; i < n; i++) {
		L.push_back(i + 1);
	}

	do {
		cout << n << endl;
		for (int x : L)cout << x << " ";
		cout << endl;
	} while (next_permutation(L.begin(), L.end()));
	return 0;
}