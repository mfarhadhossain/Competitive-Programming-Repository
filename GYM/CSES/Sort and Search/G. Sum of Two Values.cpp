#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,x;cin>>n>>x;

    vector< pair<int,int> > ar(n);
    for(int i=0;i<n;i++){
            cin>>ar[i].first;
            ar[i].second=i;
    }

    sort(ar.begin(),ar.end());

    for(int i=0;i<n;i++){
        int need = x-ar[i].first;

        if(need<=0)continue;
        //cout<<"searching "<<need<<" pos found: ";
        int pos = lower_bound(ar.begin(),ar.end(),make_pair(need,0))-ar.begin();
        //cout<<pos<<endl;

        if(pos==n || ar[i].second==ar[pos].second)continue;

        if(ar[pos].first==need){
            cout<<ar[i].second+1<<" "<<ar[pos].second+1<<endl;
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}


