#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5+7, MOD = 1e9+7;
ll dp[MAX];
ll solve(ll points){
    if(points==0)return 1LL;
    if(points<0)return 0LL;
    if(dp[points]!=-1)return dp[points];
    ll res=0;
    for(ll i=1,k=2;i<=20;i++,k<<=1LL){
        ll m = k-1;
        res=res%MOD + solve(points - m)%MOD;
        res%=MOD;
    }
    return dp[points]= res%MOD;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof dp);

    solve(MAX-1);
    for(int i=1;i<MAX;i++)dp[i]=(dp[i]*2LL)%MOD;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        if(b==0)cout<<"1\n";
        else cout<<dp[b]<<endl;
    }
    return 0;
}
