#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5;
typedef long long int ll;
int ar[MAX],n,k;
int go(int idx,int pr,int rem){
    if(idx==n){
        if(rem==0)return 0;
        return 1e9;
    }
    int ret=1e9;
    if(pr<=1 && ar[idx]){
        ret = min(ret,1 + go(idx+1,1+pr,rem-ar[idx]));
    }
    else{
        ret=min(ret,go(idx+1,0,rem));
    }
    return ret;
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
            cin>>ar[i];
    }
    cout<<"res ";
    int res = go(0,0,k);
    if(res == 1e9)res=-1;
    cout<<res<<endl;
}
int main (){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}


