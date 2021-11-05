#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    vector<string>s(n),t(m);

    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
    }

    int q;cin>>q;

    while(q--){

        int idx;cin>>idx;

        cout<<s[(idx-1)%n]+t[(idx-1)%m]<<endl;
    }
    return 0;
}

