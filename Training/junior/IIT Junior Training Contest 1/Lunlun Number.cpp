#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 100000;
vector<ll>res;
void gen(){


    queue<ll>q;
    for(ll i=1;i<=9;i++)q.push(i);
    map<ll,int>mp;
    while(!q.empty()){
        ll u = q.front();
        q.pop();

        res.push_back(u);
        if(res.size()>MAX)return;
        if(u>3234566667 || mp[u])continue;
        mp[u]=1;

        int r = u%10;

        for(int i=0;i<=9;i++){

            int d = abs(r-i);
            if(d<=1){
                q.push(u*10 + i);
            }
        }
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    gen();

    sort(res.begin(),res.end());

    int k;cin>>k;

    cout<<res[k-1]<<endl;
    return 0;
}



