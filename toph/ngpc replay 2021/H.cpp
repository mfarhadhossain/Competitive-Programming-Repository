#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10;
void solve() {
	int n;cin>>n;
	vector<ll>v(n);
	map<ll,int>map;

	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i==0){
			map[v[i]]=1;
		}
		else{
			map[v[i]-v[i-1]]=1;
		}
	}
	if(map.size()==n)cout<<"Won\n";
	else cout<<"Lost\n";
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