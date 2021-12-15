class Solution {
public:
    bool overlaps(vector<int>&A, vector<int>&B) { // A denotates B
        double distance = sqrt( (A[0] - B[0]) * 1.0 * (A[0] - B[0]) + (A[1] - B[1]) * 1.0 * (A[1] - B[1]));
        return distance <= (1.0 * A[2]);
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), res = 0;
        vector<int>adj[n + 5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)continue;
                if (overlaps(bombs[i], bombs[j])) {
                    adj[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            queue<int>Q;
            Q.push(i);
            int sz = 0;
            vector<bool> vs(n + 5);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                if (vs[u])continue;
                vs[u] = 1;
                sz++;
                for (int j = 0; j < adj[u].size(); j++) {
                    int v = adj[u][j];
                    if (vs[v])continue;
                    Q.push(v);
                }
            }
            res = max(res, sz);
        }
        return res;
    }
};