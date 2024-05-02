#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5 + 7, MOD = 1e9 + 7;

std::vector<int> alreadyBinaryDecimal;

void generateAlreadyBinaryDecimal(int x) {
  if (x > 100000)return;
  if (x != 1) alreadyBinaryDecimal.push_back(x);
  generateAlreadyBinaryDecimal(x * 10);
  generateAlreadyBinaryDecimal(x * 10 + 1);
}
bool isBinaryDecimal(int x) {
  while (x) {
    if (x % 10 > 1) return false;
    x /= 10;
  }
  return true;
}
void solve() {
  int n;
  cin >> n;
  if (isBinaryDecimal(n)) {
    cout << "YES\n";
    return;
  }
  while (n > 1) {
    int f = 0;
    for (auto x : alreadyBinaryDecimal) {
      if (n % x == 0) {
        n /= x;
        f = 1;
      }
    }
    if (f == 0)break;
  }
  if (isBinaryDecimal(n)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {

  generateAlreadyBinaryDecimal(1);

  // ios_base::sync_with_stdio(false);
  // cin.tie(0);

  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    //cout<<"case "<<tc<<": ";
    solve();
  }
  return 0;
}