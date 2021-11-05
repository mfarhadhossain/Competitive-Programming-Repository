#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e7+7;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n,m;cin>>n>>m;

    vector<int>bread(n),oven(m);


    for(int i=0;i<n;i++)cin>>bread[i];
    for(int i=0;i<m;i++)cin>>oven[i];


    int i=0,j=0,waste=0;

    while(i<n){
        if(oven[j]>=bread[i]){
            oven[j]-=bread[i];
            i++;
        }
        else{
            j++;
        }
    }
    for(int x:oven)waste+=x;

    cout<<waste<<endl;

    return 0;
}




