#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	vector<ll>ar(n);
	double sum=0;
	for(int i=0;i<n;i++){
		cin>>ar[i];
		sum+=ar[i];
	}
	double res = sum/(n*1.0);

	sort(ar.begin(),ar.end());

	double pr=0;

	for(int i=0;i<n-1;i++){
		pr+=ar[i];
		double ret = (pr)/((i+1)*1.0);

	//cout<<fixed<<setprecision(10)<<ret<<' ';
		ret = ret + (sum-pr)/((n-i-1)*1.0);
		
	//cout<<fixed<<setprecision(10)<<(sum-pr)/((n-i-1)*1.0)<<endl;
		res = max(res,ret);
	}
	cout<<fixed<<setprecision(10)<<res<<endl;
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