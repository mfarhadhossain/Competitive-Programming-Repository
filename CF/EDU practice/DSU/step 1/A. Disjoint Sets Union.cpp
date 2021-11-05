#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;
int par[MAX],sz[MAX];
void init(int n){
    for(int i=1;i<=n;i++)par[i]=i,sz[i]=1;
}
int find_par(int x){
    if(par[x]==x)return x;
    return par[x] = find_par(par[x]);
}
void Union(int u,int v){
    int par_u = find_par(u);
    int par_v = find_par(v);
    if(par_u!=par_v){
            if(sz[par_u]>sz[par_v]){
                sz[par_u]+=sz[par_v];

                par[par_v] = par_u;
            }
            else{
                sz[par_v]+=sz[par_u];

                par[par_u] = par_v;
            }
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;

    init(n);

    for(int i=0;i<m;i++){
        string type;cin>>type;
        if(type=="union"){
            int u,v;cin>>u>>v;
            Union(u,v);
        }
        else{
            int u,v;cin>>u>>v;
            if(find_par(u)==find_par(v)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }
    return 0;
}
