#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int a[MAX];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n,s;cin>>n>>s;
    for(int i=0;i<n;i++)cin>>a[i];
    long long curr=0,res=0;

    for(int r=0,l=0;r<n;r++){
        curr+=a[r];
        while(curr>=s){
            curr-=a[l];
            l++;
        }
        res+= l;
    }
    cout<<res<<endl;

    return 0;
}

