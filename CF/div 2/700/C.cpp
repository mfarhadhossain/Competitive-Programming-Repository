// WA
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//#define endl "\n"
void print(int x){
    cout<<"! "<<x<<endl;
}
int main (){
    int n;
    cin>>n;
    if(n==1){
            print(1);
            return 0;
    }
    vector<int>ar(n+2,1e9);
    ar[0]=1e9;
    ar[n+1]=1e9;

    int t = 100,l=1,r=n;
    int m = (1+n)/2;
    int ml = m-15;
    int mr = m+15;

    for(int i=1;i<=min(n,30);i++){
        cout<<"? "<<i<<endl;
        cin>>ar[i];
    }
    for(int i=n;i>=max(1,n-30);i--){
        cout<<"? "<<i<<endl;
        cin>>ar[i];
    }
    for(int i=max(1,ml);i<=min(n,mr);i++){
        cout<<"? "<<i<<endl;
        cin>>ar[i];
    }

    for(int i=1;i<=n;i++){
        if(ar[i]<min(ar[i+1],ar[i-1])){
            print(i);
            return 0;
        }
    }

    return 0;
}


