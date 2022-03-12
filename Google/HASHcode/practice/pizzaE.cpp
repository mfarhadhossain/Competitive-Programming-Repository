#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int  main ()
{
	//freopen("a_an_example.in","r",stdin);

	freopen("d_difficult.txt","r",stdin);
	
	freopen("outputD.txt","w",stdout);
	int n;cin>>n;
	set<string> res;
	map<string,bool> dis;
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
			dis[s]= true;
		}
	}

	for(auto x:res){
		if(dis[x]){
			res.erase(x);
		}
	}
	cout<<(int)res.size();
	for(auto x:res)
		cout<<" "<<x;
	cout<<endl;
	return 0;
}