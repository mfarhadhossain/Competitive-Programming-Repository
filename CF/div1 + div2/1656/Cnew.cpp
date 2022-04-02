#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n, z = 0, even = 0, odd = 0; cin >> n;

	vector<int>ar(n);

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		int x = ar[i];
		if (x % 2 == 0) {
			even++;
		}
		if (x % 2) {
			odd++;
		}
	}
	if (even == n or odd == n) {
		cout << "YES\n";
		return;
	}
	int equal = true;

	for (int i = 1; i < n; i++) {
		if (ar[i] != ar[0])
		{
			equal = false;
			break;
		}
	}
	if (equal == true) {
		cout << "YES\n";
		return;
	}

	// all elements >=2

	int good = true;

	for (int i = 0; i < n; i++) {
		if (ar[i] == 1)
		{
			good = false;
			break;
		}
	}
	if (good == true) {
		cout << "YES\n";
		return;
	}
	// 1 ase and even ase
	sort(ar.begin(),ar.end());
	for(int i=1;i<n;i++){
		if(ar[i]-1 == ar[i-1]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}