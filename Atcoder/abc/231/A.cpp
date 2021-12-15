#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n,mx=0;cin>>n;
	string res="";
	map<string,int>cnt;
	while(n--){
		string s;cin>>s;
		cnt[s]++;
		if(cnt[s]>mx){
			mx = cnt[s];
			res = s;
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