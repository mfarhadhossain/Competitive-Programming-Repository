#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mx=1e5;

int main()
{
    ll i,j,k,n;
    ll t,ans;
    cin>>n>>t;
    ans=t;
    ll a[n];
    for(i=0; i<n; i++)
        cin>>a[i];
    //ll dist[mx];
    //memset(dist,0,sizeof dist);
    map<ll,ll> dist;
    vector<ll> cnt;
    dist[t-a[n-1]+a[0]]++;
    cnt.push_back(t-a[n-1]+a[0]);
    for(i=1; i<n; i++)
    {
        dist[a[i]-a[i-1]]++;
        if(dist[a[i]-a[i-1]]==1)
            cnt.push_back(a[i]-a[i-1]);
    }
    ll div=dist[cnt[0]];
    for(i=1; i<cnt.size(); i++)
        if(div!=dist[cnt[i]])
        {
            div=1;
            break;
        }
    ans/=div;
    //cout<<div<<endl;
    cout<<ans-1<<endl;
    return 0;
}

