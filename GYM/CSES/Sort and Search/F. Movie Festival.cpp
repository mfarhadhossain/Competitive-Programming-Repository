#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.second > b.second)return 0;
    if(a.second < b.second)return 1;
    return a.first < b.first;
}
int main (){
    vector< pair<int,int> > ar;

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        ar.push_back({l,r});
    }
    sort(ar.begin(),ar.end(),cmp);

    int res=1,last= ar[0].second;

//    for(int i=0;i<n;i++){
//        cout<<ar[i].first<<" "<<ar[i].second<<endl;
//    }
    for(int i=1;i<n;i++){
            if(ar[i].first>=last){
                res++;
                last=ar[i].second;
            }
            //last=ar[i].first;

    }
    cout<<res<<endl;
    //main();

    return 0;
}

