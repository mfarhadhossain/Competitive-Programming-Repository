#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	map<int,int> mp;
	while(true){
		for(int i=1;i<=2*n+1;i++){
			if(mp[i]==0){
				cout<<i<<endl;
				mp[i] = 1;
				break;
			}
		}
		int y;cin>>y;
		if(y==0)break;
		mp[y] = 1;
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