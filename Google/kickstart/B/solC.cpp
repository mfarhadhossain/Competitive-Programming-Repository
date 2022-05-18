#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
#define PI acos(-1.0)
void solve() {
	ll N,D;cin>>N>>D;

	vector<ll> v(N),temp(N,0);

	for(int i=0;i<N;i++)
		cin>>v[i];

	ll res=0,l=0,r=N-1,step=1;

	while(v!=temp){
		
		for(int i=l;i<=r;i++){
			if(temp[i]!=v[i]){
				l=i;
				break;
			}
		}
		for(int i=r;i>=l;i--){
			if(temp[i]!=v[i]){
				r=i;
				break;
			}
		}
		ll cost1 = min(max(temp[l],v[l]) - min(temp[l],v[l]),
						min(temp[l],v[l]) + D-max(temp[l],v[l]));
		ll cost2 = min(max(temp[r],v[r]) - min(temp[r],v[r]),
						min(temp[r],v[r]) + D-max(temp[r],v[r]));
		ll xxx = 0;

		if(cost2 < cost1){
			xxx = v[r];
			res+=cost2;
			cout<<"cost "<<cost2<<" ";
		}
		else{

			xxx = v[l];
			res+= cost1;

			cout<<"cost "<<cost1<<" ";
		}
		for(int i=l;i<=r;i++){
			temp[i]=xxx;
		}
		cout<<"changing to "<<xxx<<"\n";
		//res+=min(cost1,cost2);
		//cout<<min(cost1,cost2)<<"\n";
		step++;
		for(auto x:temp)
			cout<<x<<" ";
		cout<<endl;
	}
	cout<<res<<endl;
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++){
		cout<<"Case #"<<tc<<":\n";
		solve();
	}
	return 0;
}