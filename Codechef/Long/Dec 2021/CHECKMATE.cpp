#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
void solve() {
	int row_king, col_king, row_rook1, row_rook2, col_rook1, col_rook2;
	cin >> col_king >> row_king;
	cin >> col_rook1 >> row_rook1;
	cin >> col_rook2 >> row_rook2;

	if(row_king == 1){
		if(row_rook1 == 2 and abs(col_king-col_rook1)>1){
			if(col_rook1!=col_rook2 and abs(col_king-col_rook2)>1){
				cout<<"Yes\n";
				return;
			}
		}
		if(row_rook2 == 2 and abs(col_king-col_rook2)>1){
			if(col_rook1!=col_rook2 and abs(col_king-col_rook1)>1){
				cout<<"Yes\n";
				return;
			}
		}
	}
	else if(row_king==8){
		if(row_rook1 == 7 and abs(col_king-col_rook1)>1){
			if(col_rook1!=col_rook2 and abs(col_king-col_rook2)>1){
				cout<<"Yes\n";
				return;
			}
		}
		if(row_rook2 == 7 and abs(col_king-col_rook2)>1){
			if(col_rook1!=col_rook2 and abs(col_king-col_rook1)>1){
				cout<<"Yes\n";
				return;
			}
		}
	}
	else if(col_king==1){
		if(col_rook1 == 2 and abs(row_king-row_rook1)>1){
			if(row_rook1!=row_rook2 and abs(row_king-row_rook2)>1){
				cout<<"Yes\n";
				return;
			}
		}
		if(col_rook2 == 2 and abs(row_king-row_rook2)>1){
			if(row_rook1!=row_rook2 and abs(row_king-row_rook1)>1){
				cout<<"Yes\n";
				return;
			}
		}
	}
	else if(col_king==8){
		
		if(col_rook1 == 7 and abs(row_king-row_rook1)>1){
			if(row_rook1!=row_rook2 and abs(row_king-row_rook2)>1){
				cout<<"Yes\n";
				return;
			}
		}
		if(col_rook2 == 7 and abs(row_king-row_rook2)>1){
			if(row_rook1!=row_rook2 and abs(row_king-row_rook1)>1){
				cout<<"Yes\n";
				return;
			}
		}
	}
	cout<<"No\n";
}
int  main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve();
	return 0;
}