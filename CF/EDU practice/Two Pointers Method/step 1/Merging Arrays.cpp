#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+7;
int a[MAX],b[MAX];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int i = 0 , j = 0;
    while(i<n || j<m){
        if(i<n&&j<m){
            if(a[i]<b[j]){
                cout<<a[i]<<' ';
                i++;
            }
            else{
                cout<<b[j]<<' ';
                j++;
            }
        }
        else if(i<n && j>=m){
            cout<<a[i]<<' ';
            i++;
        }
        else if(j<m && i>=n){
            cout<<b[j]<<' ';
            j++;
        }
    }
    cout<<endl;
    return 0;
}
