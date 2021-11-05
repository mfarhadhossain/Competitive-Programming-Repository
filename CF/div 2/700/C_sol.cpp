#include<bits/stdc++.h>
using namespace std;
int get(int idx){
    cout<<"? "<<idx<<endl;
    int x;cin>>x;
    return x;
}
void print(int x){
    cout<<"! "<<x<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;

    vector<int>ar(n+2);
    ar[0] = 1e9;
    ar[n+1] = 1e9;

    int l = 1 , r = n;

    while(l<r){

        int mid = (l+r)/2;
        ar[mid] = get(mid);
        ar[mid + 1] = get(mid+1);

        if(ar[mid] < ar[mid + 1]){
                r = mid;
        }
        else{
                l = mid+1;
        }
    }
    for(int i=max(l-10,1);i<=min(r+10,n);i++){
        if(ar[i]==0)ar[i]=get(i);
        if(ar[i-1]==0)ar[i-1]=get(i-1);
        if(ar[i+1]==0)ar[i+1]=get(i+1);
        if(ar[i]<min(ar[i-1],ar[i+1])){
            print(i);
            return 0;
        }
    }
    return 0;
}
