#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
// template<typename T>
// using ordered_set = tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>;
using ll = long long int;
// starts here
const int MAX = 1e6, MOD = 1e9 + 7;
map<ll, int> MAP;
int ID(char ch) {
	if (ch == 'X')
		return 1;
	if (ch == 'O')
		return 2;
	return 0;
}
char rev_ID(int id) {
	if (id == 0)
		return 'X';
	return 'O';
}
ll hash_val(std::vector<string> table) {
	ll pw = 1, num = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			num += pw * ID(table[i][j]);
			pw *= 3;
		}
	}
	return num;
}
int is_win(std::vector<string> table) {
	//cout << "w\n";
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << table[i][j];
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 1; j < 3; j++) {
			if (table[i][j] == '_')continue;
			if (table[i][j - 1] == table[i][j])
				cnt++;
		}
		if (cnt == 2)
			return true;
	}
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 1; j < 3; j++) {

			if (table[j][i] == '_')continue;
			if (table[j][i] == table[j - 1][i])
				cnt++;
		}
		if (cnt == 2)
			return true;
	}
	return (table[0][0] == table[1][1] and table[2][2] == table[1][1] and table[1][1] != '_') or
	       (table[2][0] == table[1][1] and table[0][2] == table[1][1] and table[1][1] != '_');
}
int is_draw(std::vector<string> table) {
	//cout << "d\n";
	for (int i = 0; i < 3; i++) {
		//int cnt = 0;
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == '_')
				return 0;
		}
	}
	return is_win(table) == false;
}
ll do_hash(std::vector<string> table) {
	int score = 0;
	if (is_win(table)) {
		score = 1; //cout << "win\n";
	}
	else if (is_draw(table)) {
		score = 1; //cout << "draw\n";
	}
	//else score = 2;
	MAP[hash_val(table)] = score;

	return score;
}
void solve() {
	vector<string> s;
	for (int i = 0; i < 3; i++) {
		string temp;
		cin >> temp;
		s.push_back(temp);
	}
	ll hash = hash_val(s);
	if (MAP[hash] == 0) {
		cout << "3\n";
		return;
	}
	cout << MAP[hash] << endl;
}
void gen(std::vector<string> table, int turn) {
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << table[i][j];
	// 	}
	// 	cout << endl;
	// }
	ll hash = hash_val(table);
	if (is_draw(table)) {
		MAP[hash] = 1;
		return;
	}
	else if (is_win(table)) {
		MAP[hash] = 1;
		return;
	}
	MAP[hash] = 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (table[i][j] == '_') {
				table[i][j] = rev_ID(turn);
				gen(table, turn ^ 1);
				table[i][j] = '_';
			}
		}
	}
}
int main () {
	// std::vector<string> table = {
	// 	"XXX",
	// 	"OO_",
	// 	"___"
	// };
	// cout << is_draw(table) << endl;
	// cout << is_win(table) << endl;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	std::vector<string> table;
	for (int i = 0; i < 3; i++) {
		table.push_back("___");
	}
	gen(table, 0);
	int t = 1; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		//cout << "Case #" << tc << ": ";
		//cout << "Case " << tc << ": ";
		solve();
	}
	return 0;
}