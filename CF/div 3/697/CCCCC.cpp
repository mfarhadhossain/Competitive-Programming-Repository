#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int MAX = 1e5+7;
void solve(){
    int n;cin>>n;
    vector<ll>v(n*2);
    set<ll>s;
    map<ll,int>cnt;
    ll sum=0;
    for(int i=1;i<=2*n;i++){
            cin>>v[i-1];
            //sum+=v[i-1];
            cnt[v[i-1]]++;
            s.insert(v[i-1]);
    }
    //cout<<"sum = "<<sum<<endl;
    ll pf=0,pr=0;
    for(ll x:s){
        ll df = x-pr;
        if(cnt[x]!=2 || df==pf){
            cout<<"NO\n";
            return;
        }
        pf=df;
    pr=x;
    }
    cout<<"YES\n";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
/*
worst case
1
5
1 2 3 4 5 6 7 14 3 11
*/


