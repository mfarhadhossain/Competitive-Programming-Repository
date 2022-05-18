#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n; cin >> n;
	int s = 0;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s+=(v[i]-1);
	}
	if(s%2==0){
		cout<<"maomao90\n";
	}
	else{
		cout<<"errorgorn\n";
	}
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