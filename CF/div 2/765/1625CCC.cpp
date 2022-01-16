#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 500 + 10, MOD = 1e9 + 7;
// dp gets MLE
// int dp[MAX][MAX][MAX];
// int go(int idx,int last, int rem){
// 	if(idx == n){
// 		return (l- cordinates[last])*a[last];
// 	}
// 	if(dp[idx][last][rem]!=-1)
// 		return dp[idx][last][rem];
// 	int ret = (cordinates[idx]-cordinates[last])*a[last] + go(idx+1,idx,rem);
// 	if(rem>=1){
// 		ret=min(ret,go(idx+1,last,rem-1));
// 	}
// 	//cout<<idx<<" "<<last<<" "<<rem<<endl;
// 	//cout<<ret<<endl;
// 	return dp[idx][last][rem] = ret;
// }
void solve() {
	//memset(dp,-1,sizeof dp);

	int n, l, k;
	cin >> n >> l >> k;

	vector<ll>a(n), cordinates(n);

	for (int i = 0; i < n; i++)
		cin >> cordinates[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//cout<<go(1,0,k)<<endl;
	ll res = 1e18;

	ll ret = 0;
	for (int i = 0; i < cordinates.size(); i++) {

		if (i == cordinates.size() - 1) {
			ret += a[i] * (l - cordinates[i]);
		}
		else ret += a[i] * (cordinates[i + 1] - cordinates[i]);
	}
	res = min(res, ret);

	while (k > 0) {


		int m = a.size();
		vector<ll> lagbe(m), bad(m);
		//cout << "lagbe: ";
		for (int i = 0; i < cordinates.size(); i++) {

			if (i == cordinates.size() - 1) {
				lagbe[i] += a[i] * (l - cordinates[i]);
			}
			else lagbe[i] += a[i] * (cordinates[i + 1] - cordinates[i]);
			//ret+=lagbe[i];
			//cout << lagbe[i] << ' ';
		}
		//cout << endl;

		ll worst = INT_MAX;
		int worst_id = 0;
		//cout << "bad: ";
		for (int i = 1; i < m; i++) { // skipping ith signs
			if (i == m - 1) {
				bad[i] = a[i - 1] * (l - cordinates[i - 1]);
			}
			else bad[i] = a[i - 1] * (cordinates[i + 1] - cordinates[i - 1]);
			//cout << bad[i] << ' ';

			if (bad[i] - lagbe[i] - lagbe[i - 1] < worst) {
				worst = bad[i] - lagbe[i] - lagbe[i - 1];
				worst_id = i;
			}
		}
		//cout << endl;

		//cout << a[worst_id] << " deleted!\n";
		vector<ll>temp_co, temp_a;
		temp_a.push_back(a[0]);
		temp_co.push_back(cordinates[0]);
		for (int i = 1; i < m; i++) {
			if (i == worst_id)continue;
			temp_co.push_back(cordinates[i]);
			temp_a.push_back(a[i]);
		}
		a = temp_a;
		cordinates = temp_co;
		k--;
	}
	// for (int i = 0; i < cordinates.size(); i++) {
	// 	cout << cordinates[i] << ' ';
	// }
	// cout << endl;
	// for (int i = 0; i < a.size(); i++) {
	// 	cout << a[i] << ' ';
	// }
	// cout << endl;
	res=0;
	for (int i = 0; i < cordinates.size(); i++) {
		if (i == cordinates.size() - 1) {
			res += a[i] * (l - cordinates[i]);
		}
		else res += a[i] * (cordinates[i + 1] - cordinates[i]);
	}
	cout << res << endl;
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}