#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,l;cin>>n>>l;

	vector<int>x(n),cnt(l+7);
	for(int i=0;i<n;i++){
		cin>>x[i];
		for(int j=0;j<l;j++){
			if(x[i]&(1<<j)){
				cnt[j]++;

				//cout<<j<<"th bit is ON of "<<x[i]<<endl;
			}
			// else{
			// 	cout<<j<<"th bit is off of "<<x[i]<<endl;
			// }
		}
	}
	int res=0;
	for(int i=0;i<l;i++){
		//cout<<i<<" "<<cnt[i]<<endl;
		int gd = cnt[i];
		int bad = n-gd;
		if(gd >= bad){
			res|=(1<<i);
		}
	}
	cout<<res<<endl;
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