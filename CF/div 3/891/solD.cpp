#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 2e5+7, MOD = 1e9+7;
int a[MAX],b[MAX],pr[MAX],su[MAX];
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    vector<int>res;
    for(int i=1; i<=n; i++)
    {

        cin>>a[i];
        v.push_back({a[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=1; i<=n; i++)
        cin>>b[i];

    map<int,int>vs;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=1; j<=n; j++)
        {

            if(i==j)continue;
            if(a[i]-a[j] < b[i]-b[j])
            {
                break;
            }
            cnt++;
        }
        if(cnt==n-1){
            res.push_back(i);
            vs[i]=1;
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(vs[i])continue;

        int pos_i,pos_j;
        pos_i = i,pos_j = res[0];

        if(a[pos_i]-a[pos_j] >= b[pos_i]-b[pos_j])
        {
            res.push_back(pos_i);
        }
    }
    cout<<res.size()<<endl;
    sort(res.begin(),res.end());
    for(int i=0; i<res.size(); i++)
    {
        if(i)cout<<" ";
        cout<<res[i];
    }
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        //cout<<"case "<<tc<<": ";
        solve();
    }
    return 0;
}
