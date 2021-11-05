#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,d,c,m,bad=0;
    cin>>n>>d>>c>>m;

    string s;cin>>s;
    int cnt_d=0,khaise=0;

    for(int i=0;i<n;i++)
        if(s[i]=='D')cnt_d++;
    for(int i=0;i<n;i++){
    //cout<<d<<" "<<c<<endl;
        if(s[i]=='C'){
            if(c)c--;
            else{
                break;
            }
        }
        if(s[i]=='D'){
            if(d){d--;c+=m;khaise++;}
            else{
                break;
            }
        }
    }
    if(khaise==cnt_d)cout<<"YES\n";
    else cout<<"NO\n";
}
int main (){
    int t;cin>>t;
    for(int tc=1;tc<=t;tc++){
        cout<<"Case #"<<tc<<": ";
        solve();
    }
    return 0;
}
