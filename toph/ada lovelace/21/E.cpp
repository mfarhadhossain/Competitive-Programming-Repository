#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX=1e5+10;
void solve(){
	int n,m;cin>>n>>m;
	vector<ll>p(m),d(n),s(m);
	for(int i=0;i<m;i++)
		cin>>p[i];
	for(int i=0;i<m;i++)
		cin>>s[i];
	ll sum=0,profit=LLONG_MIN;
	for(int i=0;i<n;i++){
		cin>>d[i];
		sum+=d[i];
	}

	for(int i=0;i<m;i++){
		ll tot=sum-(s[i]+n*p[i]);
		profit=max(profit,tot);
	}
	if(profit==0)cout<<"Neutral\n";
	if(profit>0)cout<<"Profit "<<profit<<"\n";
	if(profit<0)cout<<"Loss "<<(-1*profit)<<"\n";
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t=1;//cin>>t;
	for(int tc=1;tc<=t;tc++)
		solve();
    return 0;
}