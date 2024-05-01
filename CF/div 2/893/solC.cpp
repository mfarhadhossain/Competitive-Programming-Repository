#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5+7, MOD = 1e9+7;
void solve() {
    int n;cin>>n;
    vector<int>res;
    vector<bool>taken(n+5);
    for(int i=1;i<=n;i++){
        int j = i;
        while(j<=n && taken[j]==0){
            res.push_back(j);
            taken[j]=1;
            j=j*2;
        }
    }
    for (int i=0;i<n;i++) {
        if(i)cout<<" ";
        cout << res[i];
    }
    cout << endl;
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

