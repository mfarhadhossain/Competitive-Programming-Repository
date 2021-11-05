#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int inversion(vector<int>a){
    int ret=0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i]>a[j])ret++;
        }
    }
    return ret;
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=k;i++)a[i]=i;
    for(int i=k+1,j=1;i<=n;i++,j++)a[i]=k-j;
    vector<int>p,b(n+1);
    for(int i=1;i<=k;i++)p.push_back(i);

    int inv = inversion(a);
    cout<<"a = ";
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
            cout<<endl;
    cout<<"inversion of a "<<inv<<endl;

    do{


        for(int i=1;i<=n;i++)b[i] = p[a[i]-1];
        if(inversion(b)<=inv){
            cout<<"for ";
            for(int i=1;i<=k;i++)cout<<p[i-1]<<" ";
            cout<<endl;
            for(int i=1;i<=n;i++)cout<<b[i]<<" ";
            cout<<endl;
        }
    }while(next_permutation(p.begin(),p.end()));
}
void solve2(){
    int n,k;cin>>n>>k;
    if(n==k){
        for(int i=1;i<=k;i++)cout<<i<<" ";
        cout<<endl;
        return;
    }
    int df = 1 + n-k;

    vector<int>res,rev_res;
    for(int i=1;i<=k;i++)res.push_back(i);
    for(int i=k;i>=1;i--)rev_res.push_back(i);

    int rem = k - df;

    //cout<<"rem = "<<rem<<endl;
    //cout<<"df = "<<df<<endl;
    for(int i=1;i<=rem;i++)cout<<i<<" ";
    for(int i=1,j=0;i<=df;j++,i++)cout<<rev_res[j]<<" ";
    cout<<endl;
}
int main (){
    //main();
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve2();
    return 0;
}
/*
aaa
bbb
*/
