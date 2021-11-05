#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define ss second
#define ff first
const int MAX = 1e3 + 7,MOD= 998244353;
ll m,x,y,k,m_;
std::vector<ll> ar;
pair<ll,ll> go(int idx,int rem,int last,int i){
    if(rem==0)
        return {0,last};
    if(idx>=i)
        return {-1e18,0};
    auto yy = go(idx+1,rem,0,i);
    ll ret=yy.ff;
    ll last_ =yy.ss;
    if(last<k){
        auto xx = go(idx+1,rem-1,last+1,i);
        if(ar[idx]+xx.ff > ret){
            ret = ar[idx]+xx.ff;
            last_=xx.ss;
        }
    }
    return {ret,last_};
}
int main() {
    //memset(dp,-1,sizeof dp);
    int t;cin>>t;
    while(t--){
    cin >> m>>x>>y>>k;

    for(int i=0;i<m;i++){
        for(int j=0;j<x;j++){
            
        int xx;cin>>xx;
        ar.push_back(xx);
        }
    }
    int res=0,la=0;
    for(int i=0;i<m;i++){
        auto xx = go(i*x,y,la,i*x+x);
        res+=xx.ff;
        la=xx.ss;
    }
    if(res<0){
        cout<<"IMPOSSIBLE\n";
    }
    else cout<<res<<endl;
    ar.clear();
}
    return 0;
}