#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 7,MOD= 998244353;
int N,K,a[MAX],b[MAX];
int dp[1005][1005];
int go(int idx,int rem){
    if(rem==0)return 1;
    if(idx==N or rem<0)return 0;
    if(dp[idx][rem]!=-1)
        return dp[idx][rem];
    int ret=0;
    for(int i=0;i<=a[idx];i++){

        ret+=go(idx+1,rem-b[idx]*i);
        ret%=MOD;

    }
    return dp[idx][rem] = ret;
}
int main() {
    memset(dp,-1,sizeof dp);
    cin >> N  >> K;

    for(int i=0;i<N;i++){
        cin >> a[i] >> b[i];
    }
    cout<<go(0,K)<<endl;
    return 0;
}