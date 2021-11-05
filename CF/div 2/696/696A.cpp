#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
const int MAX = 1e5+7;
void solve(){
    ll n;cin>>n;
    vector<ll>c(n),a(n),b(n),middle_nodes(n),outer_nodes(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    ll res = 0,ret=0,cycle=0;
//    cout<<"for : ";
//    for(int i=1;i<n;i++)cout<<i<<" ";
//    puts("");
//    cout<<"ret : ";

    for(int i=1;i<n;i++){
        middle_nodes[i] = max(0LL,abs(a[i]-b[i])-1);
        outer_nodes[i] = c[i-1] - middle_nodes[i];
        //cout<<middle_nodes[i]<<" "<<outer_nodes[i]<<endl;
    }

    for(int i=1;i<n;i++){
        if(i==1){
            ret = abs(a[i]-b[i]) + 1;
            ret = ret + c[i];
        }
        else{
            if(a[i]==b[i]){
                ret=1;
                ret=ret+c[i];
            }
            else ret = ret + c[i] - middle_nodes[i];
        }

        res = max(res,ret);
    }
    //cout<<endl;
    cout<<res<<endl;
}
int main (){
    //gen(7,100);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}
/*
10
3
3 5 2
-1 1 3
-1 3 2
3
3 5 2
-1 1 3
-1 3 3
3
3 5 2
-1 1 5
-1 3 1

4
1  3 1 5
-1 1 1 1
-1 1 3 1

5
1  3 1 5 1
-1 1 1 1 1
-1 1 3 1 5
5
1  3 1 5 1
-1 1 1 1 2
-1 1 3 1 3
*/

