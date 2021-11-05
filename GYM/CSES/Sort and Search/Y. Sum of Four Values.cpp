#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n,x;cin>>n>>x;

    vector< ll > ar(n);
    vector< pair<ll,pair<ll,ll> >> br;
    for(int i=0;i<n;i++){
            cin>>ar[i];
    }

    //sort(ar.begin(),ar.end());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(i>j)br.push_back({ar[i]+ar[j],{j,i}});
            else br.push_back({ar[i]+ar[j],{i,j}});
        }
    }
    sort(br.begin(),br.end());
    for(int i=0;i<br.size();i++){
        ll need = x-br[i].first;

        if(need<=0)continue;
        //cout<<"searching "<<need<<" pos found: ";
        pair< ll , pair<ll,ll> > xx;
        xx = make_pair(need,make_pair(0,0));
        int pos = lower_bound(br.begin(),br.end(),xx)-br.begin();
        //cout<<pos<<endl;

        if(pos==n)continue;

        for(int j = max(0,pos-10);j<min( (int)br.size(),pos+10);j++){
            if(br[j].first==need && (br[j].second.first!=br[i].second.first && br[j].second.second!=br[i].second.second
                                     && (br[j].second.first!=br[i].second.second && br[j].second.second!=br[i].second.first))){
                cout<<br[i].second.first+1<<" ";
                cout<<br[i].second.second+1<<" ";
                cout<<br[j].second.first+1<<" ";
                cout<<br[j].second.second+1<<"\n";
                return 0;
            }
        }

    }
    cout<<"-1\n";
    //cout<<"IMPOSSIBLE\n";
    return 0;
}



