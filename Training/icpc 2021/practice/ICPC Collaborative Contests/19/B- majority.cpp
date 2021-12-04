#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n,mx=0,res=0;cin>>n;
	vector<int>cnt(1001);
	for(int i=0;i<n;i++){
		int x;cin>>x;
		cnt[x]++;
		if(cnt[x]>mx){
			mx = cnt[x];
			res = x;
		}
		if(cnt[x]==mx){
			mx = cnt[x];
			res = min(x,res);
		}
	}
	cout<<res<<endl;
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}
3
2
1.0 1.0
1.5 0.0
3
1.0 1.0
1.0 1.0
1.0 1.0
6
1.5 9.0
2.0 2.0
2.5 6.0
3.0 5.0
4.0 2.0
10.0 5.5
