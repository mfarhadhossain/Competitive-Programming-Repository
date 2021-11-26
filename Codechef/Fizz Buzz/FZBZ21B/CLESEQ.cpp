#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n,k;cin>>n>>k;
	vector<int>v(n+2),cnt(k+2),rcnt(k+2),ord(k+2);
	for(int i=1;i<=n;i++)
		cin>>v[i];

	int res=0;
	for(int i=2;i<=n;i++){
		if(v[i]!=v[i-1]){
			cnt[v[i-1]]++;
			rcnt[v[i]]++;
			res++;
		}
	}
	for(int i=1;i<=k;i++){
		cout<<res-(cnt[i]+rcnt[i])<<" ";
	}
	cout<<"\n";
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