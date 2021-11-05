#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int MAX = 1e5+7;
void solve(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;cin>>n;
    vector<ll>c(n),a(n),b(n),dp(n+1);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    dp[0]=0;
    ll ret=0,res=0;
    for(int i=1;i<n;i++){

        if(a[i]==b[i]){

            dp[i] = c[i]+1;
        }
        else{
            dp[i] = max(dp[i-1]-abs(a[i]-b[i]) + c[i] + 1, c[i]+1+abs(a[i]-b[i]));
        }
        res=max(res,dp[i]);
        //cout<<dp[i]<<" ";
    }
    //cout<<endl;
    cout<<res<<endl;
}
int main (){
    //gen(7,100);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
/*
10
3
3 5 2
-1 1 3
-1 3 2
3
3 5 2
-1 1 3
-1 3 3
3
3 5 2
-1 1 5
-1 3 1

4
1  3 1 5
-1 1 1 1
-1 1 3 1

5
1  3 1 5 1
-1 1 1 1 1
-1 1 3 1 5
5
1  3 1 5 1
-1 1 1 1 2
-1 1 3 1 3
*/

