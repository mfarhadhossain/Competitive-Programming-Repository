// i guess this needs some matrix expo solution
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;
const int MAX = 2e5+7;
ll n,m,x,a;
int main (){
    cin>>n>>x>>m;
    a = x;
    ll res = 0,no=1;
    while(a!=0){
            //cout<<a<<" ";
        res = res + a;
        a = a%m;
        a = (a*a);
        a = a%m;
        if(no==n)break;
        no++;
    }
    cout<<res<<endl;
    //main();
    return 0;
}

