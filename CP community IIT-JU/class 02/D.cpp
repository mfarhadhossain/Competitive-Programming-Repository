#include<bits/stdc++.h>
using namespace std;
int  main ()
{
	int h,w;cin>>h>>w;

	int ar[h+5][w+5];


	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin >> ar[i][j];
			//cout<<ar[i][j]<<" ";
		}

		//cout<<endl;
	}

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			//cin >> ar[i][j];
			cout<<ar[i][j]<<" ";
		}

		cout<<endl;
	}


	for(int i=1;i<=w;i++){

		for(int j=1;j<=h;j++){
			cout<<ar[j][i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}