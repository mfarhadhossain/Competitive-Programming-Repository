#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 200005;
multiset<int> possible[MAX+1];
int a[MAX];
void solve(){
    int n,k;cin>>n>>k;

    map<int,int> cnt, cost;

    for(int i=0;i<n;i++)cin>>a[i];
    //cout<<"loop2\n";
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        possible[a[i]].insert(0);
        int temp=a[i],step=0;
        while(temp>=0){
                step++;
                temp/=2;
                cnt[temp]++;
                if(possible[temp].size()>=k){
                    auto it = prev(possible[temp].end());
                    if(*it>step){

                        possible[temp].erase(step);
                    }
                }
                possible[temp].insert(step);
                if(temp==0)break;
        }
        //cout<<i<<endl;
    }
//    cout<<"insert sesh!";
//    for(int i=0;i<=MAX;i++){
//
//        multiset<int> :: iterator it;
//        if(possible[i].size()){
//            it = possible[i].end();
//            while(possible[i].size()>k){
//                it--;
//                possible[i].erase(it);
//                if(it==possible[i].begin())break;
//            }
//        }
//
//    }
    ll res=1e9;
    for(int i=0;i<=MAX;i++){

//        for(int it:possible[i])
//            cout<<it<<" ";
//        cout<<endl;
        ll ret=0;
        if(possible[i].size()>=k){
            int cnt=1;
            for(int it:possible[i]){

                ret+=it;
                if(cnt==k)break;
                cnt++;
            }
            res=min(res,ret);
        }

    }
    cout<<res<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
