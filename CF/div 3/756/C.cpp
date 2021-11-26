#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;

void print(deque<int>t) {
	while (!t.empty()) {
		cout << t.front() << " ";
		t.pop_front();
	}
	cout << endl;
	return;
}

pair<deque<int>, deque<int>> f(deque<int>a) {
	deque<int> res;
	int cnt=0;
	while (a.size() > 1) {
		//if (cnt %2==0) {
			if (a.front() < a.back()) {
				res.push_front(a.front());
				a.pop_front();
			}
			else { // a.back() < a.front()

				res.push_back(a.back());
				a.pop_back();
			}
		// }
		// else {
		// 	if (a.front() > a.back()) {
		// 		res.push_front(a.front());
		// 		a.pop_front();
		// 	}
		// 	else {

		// 		res.push_back(a.back());
		// 		a.pop_back();
		// 	}
		// }
		cnt++;
	}
	deque<int>res2;
	res2 = res;
	res.push_back(a.back());


	res2.push_front(a.back());

	return {res, res2};
}
pair<deque<int>, deque<int>> g(deque<int>a) {
	deque<int> res;
	int cnt = 0;
	while (a.size() > 1) {
		if (cnt & 1) {
			if (a.front() < a.back()) {
				res.push_front(a.front());
				a.pop_front();
			}
			else { // a.back() < a.front()

				res.push_back(a.back());
				a.pop_back();
			}
		}
		else {
			if (a.front() > a.back()) {
				res.push_front(a.front());
				a.pop_front();
			}
			else {

				res.push_back(a.back());
				a.pop_back();
			}
		}
		//print(res);
		cnt++;
	}
	deque<int>res2;

	res2 = res;
	res.push_back(a.back());

	res2.push_front(a.back());

	return {res, res2};
}
void solve() {
	int n, x; cin >> n;
	deque<int>a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}

	pair<deque<int>, deque<int>> G = g(a);
	// cout<<"one possible: "; print(G.first);

	// cout<<"its reverse: ";
	// pair<deque<int>, deque<int>> tmp = f(G.first);
	// cout<<"one possible: "; print(tmp.first);
	// cout<<"another possible: "; print(tmp.second);


	// cout<<"another possible: "; print(G.second);

	// cout<<"its reverse: ";
	// pair<deque<int>, deque<int>> tmp2 = f(G.second);
	// cout<<"one possible: "; print(tmp.first);
	// cout<<"another possible: "; print(tmp.second);
	if(f(G.first).first == a or f(G.first).second == a){
		print(G.first);
	}
	else if(f(G.second).first == a or f(G.second).second == a){
		print(G.second);
	}
	else cout<<"-1\n";
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}