#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
#define m_p make_pair
typedef long long int ll;

#define pii pair<ll,ll>
const int MAX = 3e5+7;
int n,m,s,t;
std::vector<pii> g[MAX];
ll dijsktra(int bad){
	vector<bool>vis(n+1);
	vector<ll>dist(n+1);
	dist[s]=0;

	for(int i=0;i<=n;i++) dist[i]=INT_MAX;
    for(int i=0;i<=n;i++) vis[i]=0;
    dist[s]=0;
    vis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> > PQ;
    PQ.push(m_p(0,s));

    while(!PQ.empty())
    {
        pii u = PQ.top();
        PQ.pop();
        if(vis[u.ss] or u.ss==bad) continue;
        vis[u.ss]=1;
        int sz = g[u.ss].size();
        for(int i=0;i<sz;i++)
        {
            pii A=g[u.ss][i];
            int v=A.ff;
            if(v==bad)continue;

            if(dist[v]>max(dist[u.ss],A.ss) && vis[v]==0)
            {
                dist[v] = max(dist[u.ss],A.ss);
                PQ.push(m_p(dist[v],v));
            }
        }
        if(dist[t]!=INT_MAX)
        	break;
    }
    return dist[t];
}
ll dist[MAX];
void dfs(int u,int p,int x){
	if(u==x)continue;
	//if(vs[u])return;
	//vs[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v = g[u][i].ff;
		int w = g[u][i].ss;
		//if(vs)
		if(v!=p && v!=x){
			dist[v]=dist[u]+w;
			dfs(v,u,x);	
		}
	}
}
void solve(){
	cin >> n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v,d;cin>>u>>v>>d;
		g[u].push_back({v,d});
		g[v].push_back({u,d});
	}
	ll res=-1,mx=-INT_MAX;
	for(int i=1;i<=n;i++){
		if(i==s or i==t){
			continue;
		}
		for(int i=0;i<n;i++)
			dist[i]=INT_MAX;
		dist[s]=0;
		dfs(s,s,i);
		ll ret = dist[t];
		//cout<<i<<" bondho korle "<<ret<<"\n";
		if(ret == INT_MAX)continue;
		
		if(ret>mx){
			mx = ret;
			res=i;
		}

	}
	cout<<res<<endl;
}
int main (){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}