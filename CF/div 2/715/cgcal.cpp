#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define endl "\n"
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
int main () {
	cout << "number of semester passed: ";
	int n; cin >> n;
	std::vector<double> v;
	cout << "enter gpas: ";
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		double x;
		cin >> x;
		v.push_back(x);
		sum += x * 1.0;
	}
	double target;
	int rem_s = 8 - n;
	while (1) {
		cout << "enter target cgpa: ";
		cin >> target;

		double rem = target * 8.0 - sum;

		double per_sem = rem / (rem_s);

		cout << "you need to get " << setprecision(5) << per_sem << " gpa per semester!\n";

		int x;
		cout << "press 0 to break!\n";
		cout << "press 1 to continue!\n";
		cin >> x;
		if (x == 0)break;
	}

	return 0;
}