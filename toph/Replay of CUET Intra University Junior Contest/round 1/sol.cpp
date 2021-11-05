#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e6+7,MOD = 1e9 +7;
void solve(){

    int n;cin>>n;

    if(n%2==0)cout<<"NO\n";
    else{
        cout<<"YES\n";
        if(n==1)return;
        for(int i=1;i<n;i+=2){
                cout<<i<<" "<<i+1<<endl;
                cout<<i<<" "<<i+2<<endl;
        }
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);

    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



