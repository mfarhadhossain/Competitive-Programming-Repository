#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5+7, MOD = 1e9+7;
void solve() {
  int a,b,c; cin>>a>>b>>c;

  if (a < b && b < c) {
    cout<<"STAIR\n";
  }
  else if (a < b && b > c) {
    cout<<"PEAK\n";
  } else {
    cout<<"NONE\n";
  }
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