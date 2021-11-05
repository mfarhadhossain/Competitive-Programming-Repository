#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
ll fun(ll y,vector<ll>&a){
    ll ret=0;
    for(auto x:a)ret+=abs(x-y);
    return ret;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    vector<ll>a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    if(n==1){
        cout<<"0\n";
        return 0;
    }
    sort(a.begin(),a.end());
    int mid = n/2;
    cout<<min(fun(a[mid],a),fun(a[mid-1],a))<<endl;
    return 0;
}



