#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int  main ()
{
	vector<double> credits = {
		19.0, 19.0, 20.5,20.5, 20.5, 22.0,19.5,19.0
	};

	int numberofsemester;
	cin>>numberofsemester;
	double tot_cre = accumulate(credits.begin(),credits.end(),0.0);
	double weighted_gpa=0.0,total_credit=0.0;
	for(int i=0;i<numberofsemester;i++){

		//cout<<"Enter gpa of "<<i+1<<"th semester: ";
		double chour,gpa;
		cin>>gpa;

		//cout<<"Enter the credit hour: ";
		//cin>>chour;
		total_credit+=credits[i];
		weighted_gpa+=gpa*credits[i];
	}
	double cgpa = weighted_gpa/total_credit;

	cout<<"your cgpa: "<<fixed<<setprecision(5)<<cgpa<<endl;

	if(numberofsemester==8)return 0;


	cout<<"Intended cgpa: ";
	double igpa;cin>>igpa;

	double s = (igpa*total_credit - weighted_gpa)/(tot_cre-total_credit);


	cout<<"your goal gpa: "<<fixed<<setprecision(5)<<s<<endl;
	return 0;
}
/*
sabbir's cgpa:
3.51
3.49
3.52
3.63
3.47
3.85
3.85
cgpa: 3.62046
farhad's cgpa:
3.61
3.61
3.47
3.22
3.28
3.71
3.58
cgpa: 3.49642
*/