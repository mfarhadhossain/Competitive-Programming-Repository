#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	ll m,x;cin>>m>>x;


	ll d = m-x;
	vector<ll>divisors;
	for(ll i=1;i*i<=d;i++){
		if(d%i==0){
			if(i>x)
			divisors.push_back(i);
			if(i*i==d)continue;
			if(d/i > x)
			divisors.push_back(d/i);
		}
	}
	sort(divisors.begin(),divisors.end());
	ll res=LLONG_MAX;
	for(int i=0;i<divisors.size();i++){
		int lo = 0,hi=divisors.size()-1;

		while(lo<=hi){
			int mid = (lo+hi)/2;

			if(divisors[mid]*divisors[i] >= m){
				res=min(res,divisors[mid]*divisors[i]);
				lo=mid+1;
			}
			else{
				hi=mid-1;
			}
		}
	}
	if(res==LLONG_MAX)res=-1;
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