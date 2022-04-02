#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		mp[x]=1;
	}
	for(int i=0;i<=2005;i++){
		if(mp[i]==0){
			cout<<i<<endl;return;
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