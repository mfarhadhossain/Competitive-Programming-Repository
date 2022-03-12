#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int n,q,ar[MAX],res[MAX];
vector<int>g[MAX];
vector< pair<int,int>> qu[MAX];
//vector<int>tmp;
void dfs(int u,int p,vector<int>&tmp){
	//vector<int>tmp;
	for(int v:g[u]){
		if(v==p)continue;
		//tmp.clear();
		dfs(v,u,tmp);
	}
	tmp.push_back(ar[u]);
	sort(tmp.rbegin(),tmp.rend());
	
	// cout<<"at subtree "<<u<<": \n";
	// for(int x:tmp)
	// 	cout<<x<<",";
	// cout<<endl;
	
	for(int i=0;i<qu[u].size();i++){
		int idx = qu[u][i].second;
		res[idx] = tmp[qu[u][i].first];
	}
}
void solve() {
	cin >> n >> q;

	for(int i=1;i<=n;i++)
		cin >> ar[i];
	
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=q;i++){
		int u,k;cin>>u>>k;

		qu[u].push_back({k-1,i});
	}
	vector<int>t;
	dfs(1,0,t);
	for(int i=1;i<=q;i++){
		cout<<res[i]<<endl;
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