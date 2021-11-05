#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;

    multiset<int>a;


    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.insert(x);
    }
    for(int i=0;i<m;i++){
        int sz;cin>>sz;
        if(a.size()==0){
            cout<<"-1\n";
            continue;
        }
        auto it = a.lower_bound(sz);

        if(it==a.end())it=prev(it);
            int bad=0;
            while(true){
                if(*it<=sz){
                    bad=1;
                    break;
                }
                if(it==a.begin()){
                    break;
                }
                it--;

            }
            if(bad==1){
                cout<<*it<<"\n";
                a.erase(it);
            }
            else{
                cout<<"-1\n";
            }
    }


    return 0;
}

