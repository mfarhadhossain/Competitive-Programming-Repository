#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,q;cin>>n>>q;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	while(q--){
		int x;cin>>x;
		if(v[0]>x){
			cout<<n<<"\n";
			continue;
		}
		if(v[n-1]<x){
			cout<<0<<"\n";
			continue;
		}
		//x++;
		int pos = lower_bound(v.begin(),v.end(),x)-v.begin();
		cout<<n-pos<<endl;
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}