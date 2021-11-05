#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
typedef long long int ll;
typedef pair<ll,ll> pll;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<ll>prefix_maxL(n+1),prefix_minR(n+1);
    vector<ll>suffix_maxL(n+1),suffix_minR(n+1);
    vector<ll>l(n+1),r(n+1);
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    prefix_maxL[0] = suffix_maxL[n] = 0;
    prefix_minR[0] = suffix_minR[n] = 1e9+7;
    for(int i=0;i<n;i++){
        prefix_maxL[i+1] = max(prefix_maxL[i],l[i]);
        prefix_minR[i+1] = min(prefix_minR[i],r[i]);
    }
    for(int i=n-1;i>=0;i--){

        suffix_maxL[i] = max(suffix_maxL[i+1],l[i]);
        suffix_minR[i] = min(suffix_minR[i+1],r[i]);
    }
    int res = 0,ret=0;

    for(int i=0;i<n;i++){
        int a = min(prefix_minR[i],suffix_minR[i+1]);
        int b = max(prefix_maxL[i],suffix_maxL[i+1]);
        ret = a-b;
        if(ret<0){
            cout<<"0\n";
            return 0;
        }
        res=max(res,ret);
    }
    cout<<res<<endl;
    return 0;
}

