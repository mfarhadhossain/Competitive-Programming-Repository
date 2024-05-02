#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5 + 7, MOD = 1e9 + 7;
void solve() {
  int a, b, c; cin >> a >> b >> c;

  if (a != c - 1) {
    cout << "-1\n";
    return;
  }

  if (!a) {
    cout << b + c - 1 << '\n';
    return;
  }
  vector<int> ar(1, 2);
  --a;
  int height = 0;
  while (a + b + c) {
    ++height;
    vector<int> tree;
    for (int i = 0; i < ar.size(); i++) {
      for (int j = 0; j < ar[i]; j++) {
        if (a) {
          tree.push_back(2);
          --a;
        } else if (b) {
          tree.push_back(1);
          --b;
        } else if (c) {
          tree.push_back(0);
          --c;
        } else {
          break;
        }
      }
      if (!(a + b + c)) {
        break;
      }
    }
    ar = tree;
  }
  cout << height << '\n';
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