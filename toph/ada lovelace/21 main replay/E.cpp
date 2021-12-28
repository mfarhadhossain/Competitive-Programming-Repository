#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int x,y,n,k;cin>>n>>k;
	map< pair<int,int> , int> ma;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		ma[{x,y}]=1;
	}
	for(int i=-1000;i<=1000;i++){
		for(int j=-1000;j<=1000;j++){
			if(ma[{i,j}]==0)
				continue;

			
		}
	}
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