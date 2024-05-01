#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5+7, MOD = 1e9+7;
void solve() {
    int n;cin>>n;
    int m = n*(n-1)/2, x;
    map<int,int> cnt;
    for(int i=0;i<m;i++){
        cin>>x;
        cnt[x]++;
    }
    n--;
    vector<int> res;
    for(auto y:cnt){
            while(cnt[y.first]){
                res.push_back(y.first);
                cnt[y.first]-=n;
                n--;
            }
    }
    res.push_back(res.back());
    for(int i=0;i<res.size();i++){
        if(i)cout<<" ";
        cout<<res[i];
    }
    cout<<endl;

}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    //cout<<"case "<<tc<<": ";
    solve();
  }
  return 0;
}
