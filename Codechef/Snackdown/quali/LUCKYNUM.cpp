#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(){
    int w=0,l=0;
    for(int i=0;i<5;i++){
        int x;cin>>x;
        if(x==1)w++;
        else if(x==2)l++;
    }
    if(w>l){
        cout<<"INDIA\n";
    }
    else if(w<l){
        cout<<"ENGLAND\n";
    }
    else cout<<"DRAW\n";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        //cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}



