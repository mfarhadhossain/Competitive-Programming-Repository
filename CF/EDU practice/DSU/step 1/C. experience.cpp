#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 2e5 + 7;
int par[MAX],sz[MAX],points[MAX];
multiset<int> disjoint[MAX];
void init(int n){
    for(int i=1;i<=n;i++)par[i]=i,sz[i]=1,points[i]=0;
}
int find_par(int x){
    if(par[x]==x)return x;
    return par[x]=find_par(par[x]);
}
void add(int x,int v){
    points[find_par(x)]+=v;
}
int get(int x){
    if(x==par[x]){
        return points[x];
    }
    return points[x]+get(par[x]);
}
void Union(int u,int v){
    int par_u = find_par(u);
    int par_v = find_par(v);
    if(par_u!=par_v){


            if(sz[par_u]>sz[par_v]){
                sz[par_u]+=sz[par_v];
                points[par_v]-=points[par_u];
                par[par_v] = par_u;
            }
            else{
                sz[par_v]+=sz[par_u];
                points[par_u]-=points[par_v];
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
        if(type=="add"){
            int x,v;cin>>x>>v;
            add(x,v);
        }
        else if(type=="join"){
            int u,v;cin>>u>>v;
            Union(u,v);
        }
        else{
            int x;cin>>x;
            //int par_u = find_par(x);
            cout<<get(x)<<endl;
        }

    }
    return 0;
}

