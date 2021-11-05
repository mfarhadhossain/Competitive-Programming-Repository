#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int a[MAX],b[MAX];//res[MAX];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int i=0,j=0,prev=0,curr=0;
    while(j<m){
        while(i<n&&a[i]<b[j]){
            curr++;
            i++;
        }
        cout<<curr<<" ";
        j++;
    }
    cout<<endl;
    return 0;
}

