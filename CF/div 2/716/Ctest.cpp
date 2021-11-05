#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
void print(std::vector<ll> v) {
	for (auto x : v) {
		cout << x << " ";
	}
	cout << endl;
}
int main () {
	int n, mx = 0; cin >> n;
	int N = (1LL << n);
	std::vector<ll> res;
	for (int mask = 0; mask < N; mask++) {
		std::vector<ll> v;
		for (int j = 0; j < n; j++) {
			if ((1LL << j)&mask) {
				v.push_back(j + 1);
			}
		}
		if (v.size()) {
			ll product = v[0];
			for (int j = 1; j < v.size(); j++) {
				product *= v[j];
				product %= n;
			}
			if (product == 1 && v.size() > mx) {
				mx = v.size();
				res = v;
			}
		}
	}
	print(res);
	return 0;
}