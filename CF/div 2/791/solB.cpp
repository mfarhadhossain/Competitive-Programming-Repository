#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,q;cin>>n>>q;
	vector<ll>ar(n),last(n);
	ll s=0, applied = 0;
	for(int i=0;i<n;i++){
		cin >> ar[i];
		s+=ar[i];
	}
	//cout<<s<<endl;
	while(q--){
		// for(auto x:ar)
		// 	cout<<x<<" ";
		// cout<<endl;
		
		ll type;cin>>type;
		if(type == 1){
			ll pos,val;cin>>pos>>val;
			ll rem=0;

			if(applied){
				rem=(n-1);
			}
			else{

			}
		}
		else{
			ll x;
			cin>>x;
			cout<< n*x <<endl;
			applied = x;
		}
	}
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