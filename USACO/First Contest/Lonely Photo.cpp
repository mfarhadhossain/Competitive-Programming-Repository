/*
ID: iamforu1
TASK: Lonely Photo
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cal_subarray(ll x){
	if(x<=0)return 0;
	return x*(x+1)/2;
}
int main() {

	int n;cin>>n;
	string s;cin>>s;

	vector<int> pos_g , pos_h;

	pos_g.push_back(0);
	pos_h.push_back(0);

	//int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='G'){
			pos_g.push_back(i+1);
		}
		else{
			pos_h.push_back(i+1);
		}
	}
	pos_h.push_back(n+1);
	pos_g.push_back(n+1);
	ll res = 0;
	for(int i=1;i<pos_g.size()-1;i++){
		// cout<<"curr pos "<<pos_g[i]<<": ";
		int prev_pos = pos_g[i-1];
		int next_pos = pos_g[i+1];
		// cout<<"prev pos "<<pos_g[i-1]<<": ";
		// cout<<"nxt pos "<<pos_g[i+1]<<": ";
		ll tot =cal_subarray(next_pos-prev_pos-1);
		//cout<<"tot "<<tot<<"\n";
		int lft = pos_g[i]-prev_pos-1;
		int rgt = next_pos-pos_g[i]-1;
		//cout<<"lft "<<lft<<endl;
		//cout<<"rgt "<<rgt<<endl;
		tot-=cal_subarray(lft);
		tot-=cal_subarray(rgt);
		if(lft>0)tot--;
		if(rgt>0)tot--;
		tot--;
		if(tot>0)
		res+=tot;
		//cout<<"tot "<<tot<<endl;
	}
	for(int i=1;i<pos_h.size()-1;i++){
		// cout<<"curr pos "<<pos_g[i]<<": ";
		int prev_pos = pos_h[i-1];
		int next_pos = pos_h[i+1];
		// cout<<"prev pos "<<pos_g[i-1]<<": ";
		// cout<<"nxt pos "<<pos_g[i+1]<<": ";
		ll tot =cal_subarray(next_pos-prev_pos-1);
		//cout<<"tot "<<tot<<"\n";
		int lft = pos_h[i]-prev_pos-1;
		int rgt = next_pos-pos_h[i]-1;
		//cout<<"lft "<<lft<<endl;
		//cout<<"rgt "<<rgt<<endl;
		tot-=cal_subarray(lft);
		tot-=cal_subarray(rgt);
		if(lft>0)tot--;
		if(rgt>0)tot--;
		tot--;
		if(tot>0)
		res+=tot;
		//cout<<"tot "<<tot<<endl;
	}
	cout<<res<<endl;
    return 0;
}