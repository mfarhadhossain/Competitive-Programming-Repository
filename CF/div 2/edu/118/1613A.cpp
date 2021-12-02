#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
int numberofdigit(int x) {
	int ret = 0;
	//cout<<"x = "<<x<<": ";
	while (x) {
		ret++;
		x /= 10;
	}
	//cout<<" nod "<<ret<<endl;
	return ret;
}
vector<int> numbtovector(int x) {
	vector<int>res;
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int comp(int x1, int x2) {
	vector<int> v1, v2;
	v1 = numbtovector(x1);
	v2 = numbtovector(x2);

	int i=0,j=0;
	while(i<v1.size() and j<v2.size()){

	}	
}

void solve() {
	int x1, p1, x2, p2;
	cin >> x1 >> p1 >> x2 >> p2;

	int d1 = numberofdigit(x1) + p1;
	int d2 = numberofdigit(x2) + p2;

	//cout<<"d1 = "<<d1<<" "<<" d2 = "<<d2<<endl;
	if (d1 < d2) {
		cout << "<\n";
	}
	else if (d1 > d2) {
		cout << ">\n";
	}
	else {
		int xx = comp(x1, x2);
		if (xx == -1) {
			cout << "<\n";
		}
		else if (xx == 0) {
			cout << ">\n";
		}
		else {
			cout << "=\n";
		}
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}