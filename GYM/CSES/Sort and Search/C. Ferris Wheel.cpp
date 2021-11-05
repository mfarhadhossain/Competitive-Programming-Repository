#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int MAX = 1e5+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,x,sum=0;cin>>n>>x;

    vector<long long>b(n);


    for(int i=0;i<n;i++)cin>>b[i];

    sort(b.begin(),b.end());
    int l=0,r=n-1,res=0;
    while(r>=l){
        if(b[r]+b[l]<=x){
            res++;
            r--;
            l++;
        }
        else{
            res++;
            r--;
        }
    }
    cout<<res<<endl;


    return 0;
}
