#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main (){
    int n;cin >> n;
    int A[n+1];
    ll sum=0,res=-1e18;
    for(int i=1;i<=n;i++){
        cin >> A[i];
    }
    for(int i=1;i<=n;i++){
        sum+=A[i];
        if(sum>res)res=sum;
        if(sum<0){
            sum=0;
        }
    }
    cout<<res<<endl;
    return 0;
}
