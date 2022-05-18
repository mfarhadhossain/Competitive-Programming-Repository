#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	string s[n+5],t[n+5];
	int bad=0;
	map<string,int>mp;
	for(int i=0;i<n;i++){
		cin>>s[i]>>t[i];
		mp[s[i]]++;
		mp[t[i]]++;
	}
	for(int i=0;i<n;i++){
		if(mp[s[i]]==1){
			mp[s[i]]++;
		}
		else if(mp[t[i]]==1){
			mp[t[i]]++;
		}
		else if(s[i]==t[i] &&mp[s[i]]==2){
			mp[s[i]]++;
		}
		else{
			bad=1;
			break;
		}
	}
	if(bad==0)cout<<"Yes\n";
	else cout<<"No\n";
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