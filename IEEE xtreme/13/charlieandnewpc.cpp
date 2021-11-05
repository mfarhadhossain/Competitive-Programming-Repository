#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5+7, MOD = 1e9+7;
int n,sz[11],ar[11][101],B,sz_a,sz_b;
vector<ll>possiblesums1;
vector<ll>possiblesums2;
void recurr(int idx,int cnt,ll sum){
    if(sum>B)return;
    if(idx>=sz_a){
        if(cnt==sz_a){
            possiblesums1.push_back(sum);
            return;
        }
        return;
    }
    ll res = 0;
    for(int i=0;i<sz[idx];i++){
        recurr(idx+1,cnt+1,sum+ar[idx][i]);
    }
}
void recurr2(int idx,int cnt,ll sum){
    if(sum>B)return;
    if(idx>=n){
        if(cnt==sz_b){
            possiblesums2.push_back(sum);
            return;
        }
        return;
    }
    ll res = 0;
    for(int i=0;i<sz[idx];i++){
        recurr2(idx+1,cnt+1,sum+ar[idx][i]);
    }
}
void solve(){
    possiblesums1.clear();
    possiblesums2.clear();
    cin>>B;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>sz[i];
    }
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<sz[i];j++){
                cin>>ar[i][j];
                if(ar[i][j]<=B){
                    res=max(res,1LL*ar[i][j]);
                }
        }
    }
    if(n==1){
        cout<<res<<endl;
        return;
    }
    sz_a = n/2;
    sz_b = n - sz_a;
    recurr(0,0,0);
    recurr2(sz_a,0,0);
    sort(possiblesums2.begin(),possiblesums2.end());
    ll ret = 0;
    int q = possiblesums2.size();
    int p = possiblesums1.size();
    for(auto x:possiblesums1){
            ll need = B - x;
            int pos = lower_bound(possiblesums2.begin(),possiblesums2.end(),need)-possiblesums2.begin();

            for(int l = max(0,pos-10);l<=min(p,pos+10);l++){
                if(possiblesums2[l] + x <=B){
                    ret=max(ret,x+possiblesums2[l]);
                }
            }
    }
    cout<<ret<<endl;
}
int main() {
//    vector<int>a={1,3,4,5,7,100};
//    cout<< lower_bound(a.begin(),a.end(),0)-a.begin()<<endl;
//    cout<< lower_bound(a.begin(),a.end(),1)-a.begin()<<endl;
//    cout<< lower_bound(a.begin(),a.end(),2)-a.begin()<<endl;
//    cout<< lower_bound(a.begin(),a.end(),3)-a.begin()<<endl;
//    cout<< lower_bound(a.begin(),a.end(),99)-a.begin()<<endl;
//    cout<< lower_bound(a.begin(),a.end(),200)-a.begin()<<endl;
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

