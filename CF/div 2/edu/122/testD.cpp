#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MX = 1e5 + 10, MOD = 1e9 + 7;
// double fun(ll df) {
// 	double x = -1 + sqrt(1.0 + 8.0 * df);
// 	x = x / 2.0;

// 	//cout<<df<<" "<<fixed<<setprecision(5)<<x<<endl;

// 	return ceil(x);
// }
unordered_map<ll,ll>mp;
ll fun(ll df) {
	return mp[df];
}
ll dp[1005][1005];
vector<int>divisors[1105];
ll go(int idx, ll rem_k, vector<int>&b, vector<int>&c) {
	if (idx == b.size()) {
		//if(rem_k>=0) return 0;
		return 0;
	}
	if(dp[idx][rem_k]!=-1)
		return dp[idx][rem_k];
	ll ret = go(idx + 1, rem_k, b, c);
	if (rem_k - b[idx] >= 0)
		ret = max(ret , c[idx] + go(idx + 1, rem_k - b[idx], b, c));
	return dp[idx][rem_k] = ret;
}
void solve() {
	memset(dp,-1,sizeof dp);
	
	ll n, k; cin >> n >> k;

	vector<int> b(n), c(n);

	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];

	ll res = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		ll df = b[i];
		b[i] = fun(df);
		sum += b[i];
	}
	cout << go(0, (ll)min(k, sum), b, c) << endl;
}
int  main ()
{
	for(int i=1;i<=20;i++){
		cout<<i<<": ";
		int mid = i/2;
		if(i&1)mid++;
		vector<bool>vs(1007);
		for(int j=1;j<=mid;j++){
			int x = i/j;
			if(vs[x])continue;
			vs[x]=1;
			divisors[i].push_back(x);
			cout<<j<<endl;
		}
		//sort(divisors[i].rbegin(),divisors[i].rend());
		
		for(int x:divisors[i])cout<<x<<" ";
			cout<<endl;
	}
	cout<<"en\n";
	//ll mx=0;
	for(int i=1;i<=20;i++){
		ll curr = 1,step=0;
		while(curr <i){
			int need = i -curr;
			// int mid = curr/2;
			// if(curr&1)mid++;

			// if(need >= curr){
			// 	step++;
			// 	curr+=curr;
			// }
			// else if(need>=1 && need<=mid){ // need 1 to n/2
			// 	step++;
			// 	curr+=need;
			// }
			// else{
			// 	step++;
			// 	curr+=mid;
			// }
			for(int x:divisors[curr]){
				if(need>=x){
					curr+=x;
					step++;
					break;
				}
			}
		}
		mp[i] = step;
		cout<<i<<" "<<step<<endl;
		//mx = max(mx,step);
	}
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	// int t = 1; cin >> t;
	// for (int tc = 1; tc <= t; tc++)
	// 	solve();
	return 0;
}