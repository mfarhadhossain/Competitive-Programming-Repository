#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int MAX = 1e5+7;
void solve(){
    int n,mx=0;cin>>n;
    vector<int>a(2*n);
    for(int i=0;i<2*n;i++){
            cin>>a[i];
            //mx = max(mx,a[i]);
    }
    sort(a.begin(),a.end());
    vector<int>start;
    for(int i=0;i<2*n-1;i++){
            start.push_back(a.back() + a[i]);
            //cout<<start.back()<<endl;
    }
    for(int i=0;i<start.size();i++){
        set<int>st;
        for(int j=0;j<2*n;j++)st.insert(a[i]);

        int curr = start[i];
        int mx = a.back();
        while(st.size()>0){
            int need = curr - mx;


        }
    }
}
int main (){

    set<int>st;
    st.insert(1);
    st.insert(3);
    st.insert(4);
    st.insert(6);
    st.insert(100);  cout<<*prev(st.end())<<endl;
    int x;cin>>x;
    auto it = st.lower_bound(x);
    if(*it==x){
        st.erase(it);
    }
    for(int x:st)cout<<x<<" ";
    cout<<endl;
    return 0;
}
/*
aaa
bbb
*/

