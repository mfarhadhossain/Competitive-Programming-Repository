#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long int;
const int MAX = 1e6, MOD = 1e9 + 7;
int bad = 0;
void run(int a, int b) {
	if (a == b or a > 100 or b > 100 or a < -100 or b < -100) {
		//cout << "bad\n";
		bad = 1;
		return;
	}
	run(a + 1, b * 2);
	run(a * 2, b + 1);
}
int main () {
	for (int i = -5; i <= 5; i++) {
		for (int j = -5; j <= 5; j++) {
			bad = 0;
			cout << i << "," << j << ": ";
			run(i, j);
			if (bad == 0) {
				cout << "good\n";
				return 0;
			}
		}
	}
}