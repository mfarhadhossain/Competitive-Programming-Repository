#include <bits/stdc++.h>
using namespace std;
int main () {
	int n;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << i + n << endl;
	}
	return 0;
}