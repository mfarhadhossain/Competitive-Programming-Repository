#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl '\n'
vector<ll>primes;
ll res[44];
bool isprime(ll x){
    for(ll i=2;i<x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
void fun(){
    for(ll i=2;i<=41;i++){
        if(isprime(i)==1){

            primes.push_back(i);
            //cout<<i<<" ";
        }
    }
    //cout<<endl;


    for(int i=1;i<=40;i++){
        ll haha=1;
        cout<<"for "<<i<<": ";
        for(ll x:primes){
            ll quo=1,i_=i;
            cout<<"prime "<<x;
            while(i_%x==0){
                i_/=x;
                quo*=x;
            }
            haha*=quo;
            cout<<" quo = "<<quo<<" haha = "<<haha<<endl;
        }
        res[i]=haha;
    }
}
void solve(){
    int N;cin>>N;
    cout<<res[N]<<endl;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fun();

    int t;cin>>t;
    while(t--)solve();
    return 0;
}
