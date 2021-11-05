#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e6+7;
int cnt[MAX],prefix[MAX];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);

    vector< pair<int,int> > ar;

    int n;cin>>n;
    vector<int>s;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        ar.push_back({l,r});
        s.push_back(l);
        s.push_back(r);
    }
    sort(s.begin(),s.end());
    unordered_map<int,int>M;
    int c=1;
    for(int x:s){
        if(M[x]==0){
            M[x]=c;
            c++;
        }
    }

    int res=0;

    for(int i=0;i<n;i++){
            cnt[M[ar[i].first]]++;
            cnt[M[ar[i].second]+1]--;
    }

    for(int i=1;i<MAX;i++){
        prefix[i]=prefix[i-1]+cnt[i];
        res=max(res,prefix[i]);
    }
    cout<<res<<endl;
    return 0;
}

