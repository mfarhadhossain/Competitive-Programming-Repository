#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
const int MOD= 1e9+7;
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
int main (){

    ll n;cin>>n;

    ll res = BigMod(3LL,floor(n/3),MOD)/(1 - (n % 3)/4);

    cout<<res<<endl;
    res = BigMod(3LL,(floor((n - 2)/3)),MOD)*(2 + ((n - 2) % 3));
    cout<<res<<endl;
    main();
    return 0;
}



