/*
ID: iamforu1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	int n;
	fin >> n;
	string s;
	fin >> s;
	int res = 0, ret = 0;
	for (int i = 1; i < n - 1; i++) {
		ret=0;
		if (s[i] == 'w') {
			
			s[i]='b';
			int j = i;
			while (j >= 0 && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i + 1;
			while (j < n && (s[j] == s[i + 1] or s[j] == 'w')) {
				ret++;
				j++;
			}
			res = max(res, ret);
			ret = 0;
			j = i - 1;
			while (j >= 0 && (s[j] == s[i - 1] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i;
			while (j < n && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j++;
			}

			res = max(res, ret);


			s[i]='r';

			j = i;
			while (j >= 0 && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i + 1;
			while (j < n && (s[j] == s[i + 1] or s[j] == 'w')) {
				ret++;
				j++;
			}
			res = max(res, ret);
			ret = 0;
			j = i - 1;
			while (j >= 0 && (s[j] == s[i - 1] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i;
			while (j < n && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j++;
			}

			res = max(res, ret);
			s[i]='w';
		}
		else {
			int j = i;
			while (j >= 0 && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i + 1;
			while (j < n && (s[j] == s[i + 1] or s[j] == 'w')) {
				ret++;
				j++;
			}
			res = max(res, ret);
			ret = 0;
			j = i - 1;
			while (j >= 0 && (s[j] == s[i - 1] or s[j] == 'w')) {
				ret++;
				j--;
			}
			j = i;
			while (j < n && (s[j] == s[i] or s[j] == 'w')) {
				ret++;
				j++;
			}
			res = max(res, ret);
		}
		fout<<i<<" "<<res<<endl;
		ret=0;
	}
	fout << res << endl;
	return 0;
}