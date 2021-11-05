#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main () {
	freopen("outF.txt", "w", stdout);
	int a, b, m, res = 0; //cin >> a >> b >> m;
	//cout << 50 * 50 * 50 << endl;
	for (a = 1 ; a <= 50; a++) {
		for (b = 1; b <= 50; b++) {
			for (int m = 0; m <= 50; m++) {
				res = 0;
				//cout << a << " " << b << " " << m << endl;
				for (int i = 0; i <= m; i++) {
					if (gcd(a + i, b + i) == 1) {
						res++;
						//cout << a + i << " " << b + i << endl;
					}
				}
				cout << res << endl;
			}

		}
	}
	//main();
	return 0;
}