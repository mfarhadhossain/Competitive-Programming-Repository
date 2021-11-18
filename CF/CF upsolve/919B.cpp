// tle
#include<bits/stdc++.h>
using namespace std;

int  main ()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int k; cin >> k;
	vector<int>res;
	int cnt = 0;
	for (int i = 19; i <= 1e8; i++) {
		int s = 0, tmp = i;
		while (tmp > 0) {
			s += tmp % 10;
			tmp /= 10;
		}
		if (s == 10) {
			res.push_back(i);
		}
		if (res.size() == k)break;
	}
	cout << res[k - 1] << '\n';
	return 0;
}