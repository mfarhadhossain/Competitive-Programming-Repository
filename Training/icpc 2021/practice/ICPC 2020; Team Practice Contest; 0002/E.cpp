#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e6+7;
int n,m,q,root;
vector<int>g[MAX];
ll points[MAX],team_points[MAX],subtree[MAX];

ll dfs2(int u,int p){
    subtree[u] = points[u] + team_points[u];
    for(int v:g[u]){
        if(v!=p){
            subtree[u]+=dfs2(v,u);
        }
    }
    return subtree[u];
}
ll dfs1(int u,int p){
    for(int v:g[u]){
        if(v!=p){
            team_points[u]+=dfs1(v,u);
        }
    }
    return team_points[u];
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>> n >> m >> q;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(x==0){
            root = i;
        }
        g[i].push_back(x);
        g[x].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int t,e,v;cin>>t>>e>>v;
        if(t==1){
            points[e]+=v;
        }
        else{
            team_points[e]+=v;
        }
    }
    dfs1(root,root);
//    for(int i=1;i<=n;i++){
//        cout<<i<<" "<<team_points[i]<<endl;
//    }
    dfs2(root,root);
    while(q--){
        int t,e;cin>>t>>e;

        if(t==1){
                cout<<points[e]+team_points[e]<<endl;
        }
        else{
                cout<<subtree[e]<<endl;
        }
    }
    return 0;
}



