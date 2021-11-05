#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5 + 7;
int a[MAX],b[MAX],c[MAX],res[MAX];
vector<int>g[MAX];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(a[i]!=b[i]){
                g[b[i]].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    int last_plank=-1;
    if(g[c[m]].size()>0){
        last_plank=g[c[m]].back();
        g[c[m]].pop_back();
    }
    else{
        for(int i=1;i<=n;i++){
            if(b[i]==c[m]){
                last_plank = i;
                break;
            }
        }
    }
    if(last_plank==-1){
        cout<<"NO\n";
        return;
    }
    res[m] = last_plank;
    for(int i=1;i<m;i++){

        if(g[c[i]].size()>0){
            res[i] = g[c[i]].back();
            g[c[i]].pop_back();
        }
        else{
            res[i] = last_plank;
        }
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()){
            cout<<"NO\n";return;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=m;i++){
        cout<<res[i]<<' ';
    }
    cout<<endl;
}
int main (){

//    priority_queue< pair<int,int> > pq;
//    pq.push({2,9});
//    pq.push({1,7});
//    pq.push({1,3});
//    while(!pq.empty()){
//        cout<<pq.top().first<<" "<<pq.top().second<<endl;
//        pq.pop();
//    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
/*
4
4 1
4 1 2 3
4 2
4 1 2 3
4 3
4 1 2 3
4 4
4 1 2 3
*/

