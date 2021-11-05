#include<bits/stdc++.h>
using namespace std;
//#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int n, a[101][101];
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= n;
}
void solve() {

	cin >> n;
	int turn = 0;
	for (int t = 1; t <= n * n; t++) {
		int alice; cin >> alice;
		int col = 0;
		int c_i = 0, c_j = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j])continue;
				if (turn == 0) {

					for (int k = 1; k <= 3; k++) {
						if (k == alice)continue;
						int gd = 1;
						for (int l = 0; l < 4; l++) {
							int xx = i + dx[l];
							int yy = j + dy[l];
							if (valid(xx, yy)) {
								if (a[xx][yy] == k) {
									gd = 0;
									break;
								}
							}
						}
						if (gd == 1) {
							col = k;
							break;
						}
					}
				}
				else {
					for (int k = 3; k >= 1; k--) {
						if (k == alice)continue;
						int gd = 1;
						for (int l = 0; l < 4; l++) {
							int xx = i + dx[l];
							int yy = j + dy[l];
							if (valid(xx, yy)) {
								if (a[xx][yy] == k) {
									gd = 0;
									break;
								}
							}
						}
						if (gd == 1) {
							col = k;
							break;
						}
					}
				}
				if (col != 0) {
					c_i = i,
					c_j = j;
					break;
				}
			}
			if (col)break;
		}

		cout << col << " " << c_i << " " << c_j << endl;
		a[c_i][c_j] = col;
		turn ^= 1;
	}

}
int main () {
// #ifndef ONLINE_JUDGE
// 	//freopen("input.txt", "r", stdin);
// 	//freopen("output.txt", "w", stdout);
// #endif
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}