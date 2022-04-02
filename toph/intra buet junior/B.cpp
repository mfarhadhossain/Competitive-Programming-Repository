#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	ll n,m,mx=0,mn=0;cin>>n>>m;
	vector<ll>l(m),r(m),rs(m);

	for(int i=0;i<m;i++){
		cin>>l[i]>>r[i];
		mx+=r[i];
		mn+=l[i];

	}
	if(n>mx or n<mn){
		cout<<"-1\n";
	}
	else{
		n-=mn;

		for(int i=0;i<m;i++){

			rs[i]=l[i];
			r[i]-=l[i];
		}

		for(int i=0;i<m;i++){
			if(n>0){
				ll can = min(r[i],n);
				rs[i]+=can;
				n-=can;
			}
		}
		for(int i=0;i<m;i++){
			if(i)cout<<" ";
			cout<<rs[i];
		}
		cout<<endl;
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