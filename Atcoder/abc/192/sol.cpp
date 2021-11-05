#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int MOD= 1e9 +7,MAX = 1e7+5;
ll res[MAX],fac[MAX*2];
void solve(){

    ll n;cin>>n;

    cout<<res[n]<<endl;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    res[1] = 2;
    res[2] = 24;
    fac[1]=1;
    fac[2]=2;
    for(int i=3;i<2*MAX;i++){
        fac[i]=(fac[i-1]*i)%MOD;
        fac[i]%=MOD;
    }
    for(int i=3;i<MAX;i++){
        res[i]=fac[i*3-i]%MOD;
    }
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
