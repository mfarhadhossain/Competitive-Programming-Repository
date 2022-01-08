// bruteforce
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 107;
int n,k,res;
bool marked[MAX];
vector<int>leaves,g[MAX];
vector<int>bfs(int s){
    //cout<<"bfs s!\n";
    queue<int>q;
    q.push(s);
    vector<bool>vs(n+5,false);
    vector<int>dist(n+5 , 1e9);
    dist[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(vs[u] or marked[u])continue;
        vs[u]=1;

        for(int v:g[u]){
            if(vs[v] or marked[v])continue;

            dist[v]=min(dist[v],1+dist[u]);

            q.push(v);
        }
    }

    //cout<<"bfs e!\n";
    return dist;
}
void genleaves(){
    leaves.clear();
    for(int i=1;i<=n;i++){
            if(marked[i]){
                g[i].clear();
                continue;
            }
        vector<int>gd;
        for(int v:g[i]){
            if(marked[v]==0){
                gd.push_back(v);
            }
        }
        g[i].clear();
        for(int v:gd)g[i].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()==1&&marked[i]==false){
            leaves.push_back(i);
            //cerr<<i<<" ";
        }
    }

}
bool valid(){
    bool good=true;
    vector< pair<int,int> > ar;
    for(int x:leaves){
        //cout<<"@ "<<x<<": ";
        if(marked[x])continue;
        vector<int>dist = bfs(x);
        int ret=0;
        for(int y:leaves){
                if(x==y or marked[y])continue;
                if(dist[y]>k){
                    //marked[y]=true;
                    ret++;
                    good=false;
                }

        }
        ar.push_back({ret,x});
        //cout<<"for "<<x<<" bad "<<ret<<endl;
        //cout<<"end!\n";
    }
    if(good)return good;
    if(ar.size())
    sort(ar.rbegin(),ar.rend());
    if(ar[0].first){
        marked[ar[0].second]=true;
        res++;
    }
    return good;
}
int main() {
    cin >> n >> k;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    genleaves();
    while(valid()==false){
        genleaves();
        if(leaves.size()==0)break;
    }
    cout<<min(res,n-1)<<endl;
    return 0;
}

