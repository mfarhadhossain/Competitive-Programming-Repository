#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
vector<int>g[1007];
void solve() {
	int n; cin >> n;
	vector<int>indegree(n + 1, 0), strength(n + 1);
	for (int i = 1; i <= n; i++)
		g[i].clear();


	int m = n * (n - 1) / 2;

	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;

		if (w == 0) continue;

		if (w == v) {
			g[u].push_back(v);
			indegree[v]++;
		}
		else {
			indegree[u]++;
			g[v].push_back(u);
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			strength[i] = 1;
		}
	}
	vector<int> order;
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		order.push_back(curr);
		//cout<<curr<<" ";
		for (int next : g[curr])
		{
			indegree[next]--;
			
			if (indegree[next] == 0)
			{
				q.push(next);
				strength[next] = strength[curr] + 1;
			}
		}
	}
	cout<<endl;

	for (int i = 1; i <= n; i++) {
		if (i > 1)cout << " ";
		cout << strength[i];
	}
	cout << endl;
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