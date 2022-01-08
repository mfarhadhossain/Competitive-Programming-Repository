#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
bool overlaps(pair<int, int> a, pair<int, int> b) {
	if (a.second < b.first) return false;
	if (a.second > b.first) return false;
	return true;
}
void solve() {
	ll c, n; cin >> n;
	vector<int>l(n), r(n);

	ll max_integers = 0, curr_integer = 0, prev_cost=0, curr_cost=0;

	// minimum_l with minimum c
	pair<int, int> min_L = {MOD, 0}; ll minL_cost = MOD;
	// maximum_r with minimum c
	pair<int, int> max_R = {0, MOD}; ll maxR_cost = MOD;

	//single segment
	ll max_segment_size=0;ll max_segment_cost = MOD;
	for (int i = 0; i < n; i++) {
		curr_cost=0;
		cin >> l[i] >> r[i] >> c;
		if (i == 0) {
			min_L = {l[i], r[i]};
			minL_cost = c;
			maxR_cost = c;
			max_R = {l[i], r[i]};

			cout << c << endl;
			prev_cost=c;
			max_integers = r[i] - l[i] + 1;
		}
		else {
			// disjoint minimum left, maximum right, total integers = max_r-min_l+1;

			if(l[i]<=min_L.first){


				if(l[i] == min_L.first){

					if(c < minL_cost){
						minL_cost=c;
						min_L={l[i],r[i]};
					}
				}
				else{
					minL_cost=c;
				}
				min_L={l[i],r[i]};
			}
			if(r[i]>=max_R.second){
				if(r[i] == max_R.second){
					if(c < maxR_cost){
						maxR_cost=c;
						max_R={l[i],r[i]};
					}
				}
				else{
					maxR_cost=c;
					max_R={l[i],r[i]};
				}
			}
			//cout<<"min left: ";
			//cout<<min_L.first<<" "<<min_L.second<<endl;
			////cout<<"minL_cost : "<<minL_cost<<endl;
			//cout<<"max right: ";
			//cout<<max_R.first<<" "<<max_R.second<<endl;

			//cout<<"maxR_cost : "<<maxR_cost<<endl;
			curr_integer = max_R.second-min_L.first+1;
			//cout<<"curr integers: "<<curr_integer<<endl;
			//cout<<"max integers: "<<max_integers<<endl;
			
			if(curr_integer >= max_integers){
				if(min_L==max_R){
					curr_cost = maxR_cost;
				}
				else{
					curr_cost = minL_cost+maxR_cost;
				}
				max_integers = curr_integer;
			}
			else if(curr_integer == max_integers){
				curr_cost = min(curr_cost,prev_cost);
			}
			else{
				curr_cost = prev_cost;
			}
			max_integers = max(max_integers,curr_integer);
			// single maximum segment, total integers = r[i]-l[i]+1;

			ll cc = r[i]-l[i]+1;
			if(cc>max_segment_size){
				max_segment_size = cc;
				max_segment_cost = c;
			}
			else if(cc == max_segment_size){
				max_segment_cost = min(max_segment_cost,c);
			}
			if(max_segment_size > max_integers){
				max_integers = cc;
				curr_cost = max_segment_cost;
			}
			else if(max_segment_size == max_integers){
				curr_cost = min(curr_cost,max_segment_cost);
			}
			cout<<curr_cost<<endl;
			prev_cost = curr_cost;
			max_integers = max(max_integers,curr_integer);
		}
	}
}
int  main ()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}