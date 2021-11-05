#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
void solve(){
    string s;cin>>s;

    for(int i=0;i<s.size();i++){

        if(i&1){
            if(s[i]=='z'){
                s[i]='y';
            }
            else{
                s[i]='z';
            }
        }
        else{
            if(s[i]=='a'){
                s[i]='b';
            }
            else{
                s[i]='a';
            }
        }
    }
    cout<<s<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}

