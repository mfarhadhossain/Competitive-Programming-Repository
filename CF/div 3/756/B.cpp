#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5 + 10;
pair<deque<int>,deque<int>> f(deque<int>a){
	deque<int> res;

	while(a.size()>1){
		if(a.front()<a.back()){
			res.push_front(a.front());
			a.pop_front();
		}
		else{

			res.push_back(a.back());
			a.pop_back();
		}
	}
	deque<int>res2;

	res.push_back(a.back());
	res2=res;

	res2.push_front(a.back());

	return {res,res2};
}
pair<deque<int>,deque<int>> g(deque<int>a){
	deque<int> res;

	while(a.size()>1){
		if(a.front()>a.back()){
			res.push_front(a.front());
			a.pop_front();
		}
		else{

			res.push_back(a.back());
			a.pop_back();
		}
	}
	deque<int>res2;

	res.push_back(a.back());
	res2=res;

	res2.push_front(a.back());

	return {res,res2};
}
void print(deque<int>&t){
	while(!t.empty()){
		cout<<t.front()<<" ";
		t.pop_front();
	}
	cout<<endl;
	return;
}
void solve() {
	int n,x;cin>>n;
	deque<int>a;
	for(int i=0;i<n;i++){
		cin>> x;
		a.push_back(x);
	}

	pair<deque<int>,deque<int>> G = g(a);	
		print(G.first);

		print(G.second);
	if(G.first == a){

		//pair<deque<int>,deque<int>> F = f(F.first);
		//if(F.first==)	
	}
	else if(G.second == a){
	}
	else{

	}
}
int  main ()
{
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}