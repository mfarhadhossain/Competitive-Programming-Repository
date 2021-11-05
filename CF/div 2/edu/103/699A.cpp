#include<bits/stdc++.h>
using namespace std;
void solve(){
    int px,py,l=0,r=0,u=0,d=0;cin>>px>>py;

    string s;cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L')l++;
        if(s[i]=='R')r++;
        if(s[i]=='U')u++;
        if(s[i]=='D')d++;
    }
   //cout<<l<<" "<<r<<" "<<u<<" "<<d<<endl;
    int mn_x = min(0,l*(-1));
    int mx_x = max(0,r);
    int mn_y = min(0,d*(-1));
    int mx_y = max(0,u);
    //cout<<mn_x<<" "<<mx_x<<endl;
    //cout<<mn_y<<" "<<mx_y<<endl;
    if(px>=mn_x && px<=mx_x && py>=mn_y&&py<=mx_y)cout<<"YES\n";
    else cout<<"NO\n";
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
