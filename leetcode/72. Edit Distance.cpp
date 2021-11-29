class Solution {
public:
    int minDistance(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        // dp[0][0]=1;
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        for (int i = 1; i <= m; i++)
            dp[0][i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        return dp[n][m];
    }
};