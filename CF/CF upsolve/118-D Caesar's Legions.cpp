#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 101, MOD = 100000000;
int n1, n2, k1, k2;
int dp[MAX][MAX][11][11];
int go(int footmen, int armymen, int fo, int ar) {
	if (!footmen && !armymen)
		return 1;
	if (dp[footmen][armymen][fo][ar] != -1)
		return dp[footmen][armymen][fo][ar];
	int ret = 0;
	if (fo < k1 && footmen) { //another footman
		ret = go(footmen - 1, armymen, fo + 1, 0)%MOD;
	}
	if (ar < k2 && armymen) { //now an armyman

		ret += go(footmen, armymen - 1, 0, ar + 1)%MOD;
	}
	return dp[footmen][armymen][fo][ar] = ret%MOD;
}
void solve() {
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, -1, sizeof dp);
	cout << go(n1, n2, 0, 0) << endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin>>t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}