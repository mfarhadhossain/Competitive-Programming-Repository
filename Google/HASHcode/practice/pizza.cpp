#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int  main ()
{
	freopen("d_difficult.txt","r",stdin);
	
	freopen("outputD.txt","w",stdout);
	int n;cin>>n;
	set<string> res;
	for(int i=0;i<n;i++){
		int likes,dislikes;
		cin>>likes;
		for(int j=0;j<likes;j++){
			string s;
			cin>>s;
			res.insert(s);
		}
		cin>>dislikes;
		for(int j=0;j<dislikes;j++){
			string s;
			cin>>s;
		}
	}
	cout<<(int)res.size();
	for(auto x:res)
		cout<<" "<<x;
	cout<<endl;
	return 0;
}