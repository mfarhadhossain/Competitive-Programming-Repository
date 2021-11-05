
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
typedef    pair<ll,ll> pll;
typedef    vector<pll> VI;
typedef    vector<VI> VVI;// 2D
const int MAX = 2e5+7;
void solve(){
    int n=1,W;cin>>n>>W;
    vector<ll>w(n);
    //priority_queue<pll,VI,greater<pll> > pq_min;
    //priority_queue<pll> pq_max;
    for(int i=0;i<n;i++){
        cin >> w[i];
       // pq_min({w[i],i});
        //pq_max({w[i],i});
    }

    ll res=1,sum=0,r=n-1,l=0;

    while(l<=r){
        if(sum+w[l] > W){
            ll rem = W-sum;
            while(r>l && rem-w[r]>=0){
                rem-=w[r];
                r--;
            }
            res++;
            if(l == r)
                break;
            l++;
        }
        else{
            sum+=w[l];
            l++;
        }

    }
    //if(l != r)res++;
    cout<<res<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
