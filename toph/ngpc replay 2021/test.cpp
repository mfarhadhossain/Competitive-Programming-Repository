#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX = 1e5 + 10;
bool possible(ll num, ll base) {
	ll curr = 0, r = 1;

	while (true) {
		curr += r;
		r = r * base;
		if (curr >= num)break;
	}
	return curr == num;
}
int  main ()
{
	ll sum = 1;
	//cout << "sum = " << sum << endl;
	for (int num = 2; num <= 1000; num++) {
		int cnt = 0;
		vector<int>b;
		//cout<<"for "<<num<<":\n";
		for (int base = 2; base <= 1000; base++) {

			if (possible(num, base)) {
				//cout<<base<<" base is sol!\n";
				cnt++;
				b.push_back(base);
			}
		}
		if (cnt >= 2) {
			cout << num << " " << cnt << ": ";
			for (auto x : b)cout << x << " ";
			cout << endl;
			sum += num;
			//cout << "sum = " << sum << endl;
		}
	}
	return 0;
}