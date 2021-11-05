#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int n,cnt;
vector<ll>Lx,Rx;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<bool>vis(n+1);
    vector<ll>L(n+1,1e18),R(n+1,-1e18);
    for(int i=1; i<=n; i++)
    {
        ll x,c;
        cin>>x>>c;
        L[c]=min(L[c],x);
        R[c]=max(R[c],x);
        if(vis[c]==0)
        {

            vis[c]=1;
            cnt++;
        }
    }
    ll res = 0,curr = 0;

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
            continue;
        cnt++;
        Lx.push_back(L[i]);
        Rx.push_back(R[i]);
    }

    for(int i=0;i<Lx.size();i++){
        ll mn = min(abs(Lx[i]-curr) , abs(Rx[i]-curr))+1;
        ll dl = mn + abs(Lx[i]-Rx[i])+1;
        res= res + dl;
        if(curr < Rx[i])
        curr = curr + dl;
        else curr = curr - dl;
    }
    cout<<res<<endl;
    return 0;
}



