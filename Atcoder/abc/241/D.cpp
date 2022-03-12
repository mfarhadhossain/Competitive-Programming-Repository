#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int q;cin>>q;
	multiset<ll> small;
	while(q--){
		ll xx;
		int t;cin>>t>>xx;


		if(t==1){
			small.insert(xx);
		}
		else if(t==2){
			int k;cin>>k;
			auto it = small.lower_bound(xx);

			vector<ll>res;
			cout<<"for "<<xx<<": ";
			for(auto x = it;;x--){
				//if(*x <= xx)
				res.push_back(*x);
				cout<<res.back()<<"\n";
				if(/*res.size()==k or*/ x==small.begin())break;
			}
			sort(res.rbegin(),res.rend());
			for(auto x:res)
				cout<<x<<" ";
			cout<<endl;
			if(res.size()<k){
				cout<<"-1\n";
			}
			else{
				cout<<res[k-1]<<endl;
			}

		}
		else{

			int k;cin>>k;

			auto it = small.lower_bound(xx);
			vector<ll>res;
			cout<<"for "<<xx<<": ";
			for(auto x = it;x!=small.end();x++){
				//if(*x >= xx)
				res.push_back(*x);
				cout<<res.back()<<" ";
				if(res.size()==k)break;
			}
			cout<<endl;
			if(res.size()<k){
				cout<<"-1\n";
			}
			else{
				cout<<res[k-1]<<endl;
			}
		}
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