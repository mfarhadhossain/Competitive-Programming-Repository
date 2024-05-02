#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5 + 7, MOD = 1e9 + 7;

bool isHash(int row, int col) {
  int whichRow = row / 2 + row % 2;
  int whichCol = col / 2 + col % 2;
  if (whichRow % 2) {
    if (whichCol % 2) {
      return true;
    } else {
      return false;
    }
  } else {
    if (whichCol % 2) {
      return false;
    } else {
      return true;
    }
  }
}
void solve() {
  int n; cin >> n;

  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (isHash(i, j)) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
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