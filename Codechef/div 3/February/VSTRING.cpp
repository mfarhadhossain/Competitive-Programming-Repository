#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
typedef long long int ll;
const int MAX = 2e5+7;
void solve(){
    string s;
    int n,c;cin>>n>>c>>s;

    s = s + s;

    vector<int>adj;

    int last = -1;

    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
                if(last==-1){
                    last = i;
                }
                else{
                    adj.push_back(i-last-1);
                    last=i;
                }
        }
    }

    if(adj.size()<=0)cout<<"YES\n";
    else{

        //sort(all(adj));

        for(int x:adj)cout<<x<<" ";
        cout<<endl;

        int s_max = adj[n-2];
        if(s_max <= c)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int main (){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}



