#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
typedef pair<int,int> pii;
string s;
bool vs[5005][5005];
bool vs_neg[5005][5005];
void dfs(int x,int y,int bad_x,int bad_y){
}
void solve(){
    cin>>s;
    vector<pii>path;
    pii curr = {0,0};
    for(int i=0;i<s.size();i++){
        if(s[i]=='R'){
            curr.first++;
        }
        else if(s[i]=='L'){
            curr.first--;
        }
        else if(s[i]=='U'){
            curr.second++;
        }
        else if(s[i]=='D'){
            curr.second--;
        }
        path.push_back(curr);
        //cout<<curr.first<<" "<<curr.second<<"\n";
    }
    bool oa=false;
    for(int i=0;i<path.size();i++){
        dfs(0,0,path[i].first,path[i].second);
        if(ok){
            cout<<path[i].first<<" "<<path[i].second<<"\n";
            return;
        }
        ok=false;
    }
    cout<<"0 0\n";
}
int main (){

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
