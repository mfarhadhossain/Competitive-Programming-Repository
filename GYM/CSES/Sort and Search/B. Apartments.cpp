#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;cin>>n>>m>>k;

    multiset<int>a;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    int res=0;
    vector<int>b(m);


    for(int i=0;i<m;i++)cin>>b[i];

    sort(b.begin(),b.end());


    for(int i=0;i<m;i++){
        int sz=b[i];

        auto it = a.lower_bound(sz-k);

        if(*it >= sz-k && *it<=sz+k){
            res++;
            a.erase(it);
        }
    }
    cout<<res<<endl;


    return 0;
}
