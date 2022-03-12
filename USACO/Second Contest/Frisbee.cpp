#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,res=0;cin>>n;
	vector<int>h(n+5);
	for(int i=1;i<=n;i++){
		cin >> h[i];
	}
	for(int i=1;i<=n;i++){
		int mx = -1;
		for(int j=i+1;j<=n;j++){
			if(min(h[i],h[j]) > mx){
				res+=j-i+1;
			}
			mx=max(mx,h[j]);
		}
	}
	cout<<res<<endl;
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