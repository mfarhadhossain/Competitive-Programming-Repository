#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 2e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(0);

    int n,x;cin>>n>>x;

    vector<ll>ar(n);

    for(int i=0;i<n;i++)cin>>ar[i];

    ll res=0,sum=0;

    for(int r=0,l=0;r<n;r++){
            sum+=ar[r];
            while(sum>x){
                sum-=ar[l];
                l++;
            }
            if(sum==x)res++;
    }
    cout<<res<<endl;
    return 0;
}



