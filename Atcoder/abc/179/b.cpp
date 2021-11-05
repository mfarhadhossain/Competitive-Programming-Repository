// TLE
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;
const int MAX = 2e5+7;
ll n,k,l,r;
vector<ll>v;
ll dp[MAX];
ll solve(int idx){
    if(idx==n)return 1LL;
    if(idx>n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    ll ret=0;
    for(int i=0;i<v.size();i++){
        if(v[i] + idx > n)break;
        ret=ret%MOD + solve(idx+v[i])%MOD;
        ret%=MOD;
    }
    return dp[idx] = ret%MOD;
}
int main (){
  memset(dp,-1,sizeof dp);
  cin >> n >> k;
  set<int>S;
  for(int i=0;i<k;i++){
    cin >> l >> r;
//    S.insert(l);
//    S.insert(r);
    for(int j=l;j<=r;j++)S.insert(j);
  }
  for(int x:S)v.push_back(x);//cout<<x<<" ";}
  //cout<<endl;
  cout<<solve(1)<<endl;
  return 0;
}
