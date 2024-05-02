#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;

const int MAX = 1e5 + 7, MOD = 1e9 + 7;

string amOrPm(int h) {
  if (h >= 0 and h <= 11) return "AM";
  else return "PM";
}

int convertHour(int h) {
  if (h % 12 == 0) return 12;
  else return h % 12;
}

string print(int x) {
  if (x < 10)return "0" + to_string(x);
  return "" + to_string(x);
}
void solve() {
  int h, m;
  scanf("%d:%d", &h, &m);

  cout << print(convertHour(h)) << ":" << print(m) << " " << amOrPm(h) << endl;
}
int main() {
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