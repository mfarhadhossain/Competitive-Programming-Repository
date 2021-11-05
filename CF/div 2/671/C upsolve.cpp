#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int eq = 0,df=0;
    for(int i=0;i<n;i++){
            if(a[i]==x){
                eq++;
            }
            df+=a[i]-x;
    }
    if(eq==n){
        cout<<"0\n";
        return;
    }
    if(eq||df==0){
        cout<<"1\n";
        return;
    }
    cout<<"2\n";

}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
