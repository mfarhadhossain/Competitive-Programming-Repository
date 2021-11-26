#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5 + 10;
int n,b[MAX],p[MAX],q[MAX],root,sub[MAX],dist[MAX],sub_dist[MAX],bad=0;
vector<int>g[MAX];
int dfs(int u,int par){
	int mn=1e9;
	for(auto v:g[u]){
		if(par!=v)
			mn=min(mn,dfs(v,u));
	}
	if(q[u]>mn){
		bad = 1;
	}
	//cout<<u<<" "<<q[u]<<endl;
	return sub[u] = min(q[u],mn);
}
int dfs2(int u,int par,int lvl){
	int ret=0;
	for(auto v:g[u]){
		if(par!=v)
			ret+=dfs2(v,u,lvl+1);
	}
	//cout<<u<<" "<<q[u]<<endl;
	return sub_dist[u]=dist[u]*q[u] + ret;
}
int dfs3(int u,int par,int lvl){
	int ret=0;
	for(auto v:g[u]){
		if(par!=v)
			ret+=dfs3(v,u,lvl+1);
	}
	//cout<<u<<" "<<q[u]<<endl;
	return sub_dist[u]= sub_dist[root] - sub_dist[u];
}
void f(){
	bad=0;
	for(int i=1;i<=n;i++){
		p[i]=0,q[i]=0,sub[i]=0;
		
		g[i].clear();
		dist[i]=0;
	}
}
void solve() {
	bad=0;
	cin>> n;
	for(int i=1;i<=n;i++){

		cin >> b[i];

		if(b[i]==i){
			root = i;
		}

		g[i].push_back(b[i]);
		g[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		q[p[i]]=i;
	}
	dfs(root,0);

	if(bad){
		cout<<"-1\n";
		f();
		return;
	}
	// write sol

	for(int i=1;i<=n;i++){
		dist[i]=q[i];
	}
	dfs2(root,0,1);
	dfs3(root,0,1);
	sub_dist[root]=0;
	for(int i=1;i<=n;i++){
		cout<<sub_dist[i]<<" ";
	}
	cout<<endl;
	f();
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}