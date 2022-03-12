#include<bits/stdc++.h>
using namespace std;
int  main ()
{
	string s;

	cin >> s;

	int a,b;

	cin>>a>>b;

	//swap(s[a-1],s[b-1]);

	char tmp = s[a-1];

	s[a-1] = s[b-1];

	s[b-1] = tmp;
	
	cout<<s<<endl;


	return 0;
}