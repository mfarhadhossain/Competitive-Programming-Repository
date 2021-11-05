#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5+7;
const ll MAX2 = 1e18;
struct node{
    int destination, time, when;
    node(int v,int t,int k){
        destination=v;
        time=t;
        when=k;
    }
};
vector<node>g[MAX];
int n,m,x,y;
ll fun(ll ready,ll train){ // calculates the waiting time
//    ll quo = ready/train;
//    if(ready%train)quo++;
//    ll start = train*quo;
//    ll w = start - ready;
//    return w;
    if(ready%train==0)return 0;
    return train - (ready%train);
}
int main (){
    cin >> n >> m >> x >> y;

    for(int i=0;i<m;i++){
        int u,v,t,k;
        cin>>u>>v>>t>>k;

        node obj1(u,t,k);
        node obj2(v,t,k);

        g[u].push_back(obj2);
        g[v].push_back(obj1);

    }
    vector<bool>vis(n+1);

    vector<ll>dist(n+1,MAX2);
    dist[x]=0;
    priority_queue<pair<ll,ll>> PQ;

    PQ.push({0,x});


    while(!PQ.empty()){
        auto X = PQ.top();
        ll curr_time= -X.first;
        ll u = X.second;


        PQ.pop();

        if(vis[u]==1)continue;
        vis[u]=1;

        for(int i=0;i<g[u].size();i++){
            node obj = g[u][i];


            int v = obj.destination;
            int t = obj.time;
            int k = obj.when;
            ll cost = t + fun(dist[u],k);
            if(dist[v]>curr_time+cost){
                dist[v]=curr_time+cost;
                PQ.push({-dist[v],v});
            }
        }
    }
    if(dist[y]==MAX2)dist[y]=-1;
    cout<<dist[y]<<endl;
    return 0;
}
