#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 2e5+7,MOD = 1e9+7;
ll f(int k,int n)
{
    if(k == 0)
        return 0;
    if(k==1)
    {
        return 1;
    }
    return (1+ (n-1)*f(k-2,n-1))%MOD;
}
void solve()
{
    ll n,k;
    cin>>n>>k;
    cout<<f(k,n)<<endl;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
/*
7
2 3
2 2
3 1
1 3
1 1
1 500
500 250
*/


