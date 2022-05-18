#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int n;cin>>n;
	deque< pair<ll,ll> > ar;
	while(n--){
		int type;cin>>type;
		if(type==1){
			int x,c;cin>>x>>c;
			ar.push_back({x,c});
		}
		else{
			int c;cin>>c;
			ll sum=0;

			while(!ar.empty()&&c){
				auto curr = ar.front();
				ll curr_element = curr.first;
				ll curr_element_count = curr.second;
				//cout<<curr_element<<","<<curr_element_count<<endl;
				if(c > curr_element_count){
					sum+=curr_element_count*curr_element;
					c-=curr_element_count;
					ar.pop_front();
				}
				else{
					sum+=c*curr_element;
					ar.pop_front();
					if(c!=curr_element_count)
					ar.push_front({curr_element,curr_element_count-c});
					c=0;
				}
			}
			cout<<sum<<endl;
		}
		//print(ar);
	}
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; //cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}