#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX=1e5+10;
void solve(){
	int n,m;cin>>n>>m;
	vector<ll>buy(n),sell(m);
	for(int i=0;i<n;i++)
		cin>>buy[i];
	for(int i=0;i<m;i++)
		cin>>sell[i];
	sort(buy.begin(),buy.end());
	sort(sell.rbegin(),sell.rend());
	ll res=0,tot=0;
	for(int i=0;i<min(n,m);i++){
		tot+=sell[i]-buy[i];
		res=max(res,tot);
	}
	cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t=1;cin>>t;
	for(int tc=1;tc<=t;tc++)
		solve();
    return 0;
}