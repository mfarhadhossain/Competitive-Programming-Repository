#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,x;cin>>n;
	vector< pair<int,int> > ar(n);
	for(int i=0;i<n;i++){
		cin>>ar[i].first;
		ar[i].second = i+1;
	}
	sort(ar.begin(),ar.end());
	cout<<ar[0].second<<" "<<ar[n-1].second<<"\n";
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