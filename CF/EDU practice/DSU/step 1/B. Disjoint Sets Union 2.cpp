#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 3e5 + 7;
int par[MAX],sz[MAX];
multiset<int> disjoint[MAX];
void init(int n){
    for(int i=1;i<=n;i++)par[i]=i,sz[i]=1,disjoint[i].insert(i);
}
int find_par(int x){
    if(par[x]==x)return x;
    return par[x] = find_par(par[x]);
}
void Merge(int a, int b){
    for(int x:disjoint[b])disjoint[a].insert(x);
}
void Union(int u,int v){
    int par_u = find_par(u);
    int par_v = find_par(v);
    if(par_u!=par_v){


            if(sz[par_u]>sz[par_v]){
                sz[par_u]+=sz[par_v];
                par[par_v] = par_u;
                Merge(par_u,par_v);
            }
            else{
                sz[par_v]+=sz[par_u];

                par[par_u] = par_v;

                Merge(par_v,par_u);
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
            int x;cin>>x;
            int par_x = find_par(x);
            int mn = *disjoint[par_x].begin();
            int mx = *prev(disjoint[par_x].end());
            int sz = disjoint[par_x].size();


            cout<<mn<<" "<<mx<<" "<<sz<<endl;
        }

    }
    return 0;
}
