#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5+7,MOD=1e9+7;
inline ll BigMod(ll a,ll e,ll mod)
{
    ll num=1;
    while(e)
    {
        if(e%2)
        {
            a%=mod;
            num%=mod;
            num=num * a;
            num%=mod;
        }
        e/=2;
        a%=mod;
        a=a * a;
        a%=mod;
    }
    return num%mod;
}
inline ll modInverse(ll A,ll P)
{
    return BigMod(A,P-2,P);
}
ll fac[MAX];
inline void factorial(int mod)
{
    fac[0]=1;
    fac[1]=1;
    for(int i=2;i<=MAX;i++) fac[i]=( (fac[i-1]%mod)*i)%mod;
}
inline ll nCr(ll n,ll r,ll mod) // ncr with mod
{
    return ((fac[n] * modInverse(fac[r],mod)%mod)%mod * (modInverse(fac[n-r],mod)%mod) ) %mod;
}
int main (){
    factorial(MOD);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;

    while(t--){
        ll n;cin>>n;
        cout<<nCr(2*n - 1 , n, MOD)<<endl;
    }
    return 0;
}



