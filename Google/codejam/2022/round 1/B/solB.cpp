#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<vector<ll>> table[15];
ll res;
void go(int idx,vector<ll>&temp,int n){
	if(idx == n){
		ll ret=0,pr=0;
		vector<ll>temp2;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<table[i][temp[i]].size();j++){
				temp2.push_back(table[i][temp[i]][j]);
			}
		}
		for(ll x:temp2)
			ret+=abs(x-pr),pr=x;
		res=min(res,ret);
		return;
	}
	for(int i=0;i<table[idx].size();i++){
		temp.push_back(i);
		go(idx+1,temp,n);
		temp.pop_back();
	}
}
void solve() {
	res=LLONG_MAX;
	ll n, p; cin >> n>> p;
	vector<vector<ll>>ar(n,vector<ll>(p,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> ar[i][j];
		}
		sort(ar[i].begin(),ar[i].end());
	}
	for(int i=0;i<n;i++){
		vector<ll>temp;
		do{
			table[i].push_back(ar[i]);
		}while(next_permutation(ar[i].begin(),ar[i].end()));
	}
	vector<ll>t;
	go(0,t,n);
	cout<<res<<endl;
	for(int i=0;i<n;i++)
		table[i].clear();

}
int  main ()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}