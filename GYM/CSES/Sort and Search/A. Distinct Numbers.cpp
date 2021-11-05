#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    vector<int>a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());
    int curr=a[0],res=1;
    for(int i=1;i<n;i++){
            if(a[i]!=curr){
                curr=a[i];
                res++;
            }
    }
    cout<<res<<endl;


    return 0;
}
