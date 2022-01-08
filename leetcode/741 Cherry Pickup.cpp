// I coded this since last 1 hour for no reason
typedef pair<int, int> pii;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        vector<vector<pii>> path(n, vector<pii>(n, {0, 0}));

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == -1) {
                dp[0][i] = -1e9;
            }
            else {
                if (i == 0) {
                    dp[0][i] = grid[0][i];
                }
                else {
                    dp[0][i] = dp[0][i - 1] + grid[0][i];
                    //path[0][i] = {0,i-1};
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == -1) {
                dp[i][0] = -1e9;
            }
            else {
                if (i == 0) {
                    dp[i][0] = grid[i][0];
                }
                else {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                    //path[i][0] = {i-1,0};
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == -1) {
                    dp[i][j] = -1e9;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        // cout<<"path table:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<"before grid table:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        if (dp[n - 1][n - 1] <= 0)return 0;
        // cout<<"path table:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<"("<<path[i][j].first<<","<<path[i][j].second<<") ";
        //     }
        //     cout<<endl;
        // }
        int pos_i = n - 1, pos_j = n - 1;

        while (true) {
            if (pos_i == 0 && pos_j == 0)break;
            if (pos_i == 0 && pos_j) {
                path[pos_i][pos_j] = {0, pos_j - 1};
                pos_j--;
            }
            else if (pos_i && pos_j == 0) {

                path[pos_i][pos_j] = {pos_i - 1, 0};
                pos_i--;
            }
            else if (dp[pos_i - 1][pos_j] > dp[pos_i][pos_j - 1]) {
                path[pos_i][pos_j] = {pos_i - 1, pos_j};
                pos_i--;
            }
            else {
                path[pos_i][pos_j] = {pos_i, pos_j - 1};
                pos_j--;
            }

        }
        int res = dp[n - 1][n - 1];
        int i = n - 1, j = n - 1;
        while (true) {
            //cout<<i<<" "<<j<<endl;
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
            }
            if (i == 0 && j == 0)break;
            auto x = path[i][j];
            i = x.first;
            j = x.second;
        }

        // cout<<"after grid table:\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for (int i = 0; i < n; i++) {
            if (grid[0][i] == -1) {
                dp[0][i] = -1e9;
            }
            else {
                if (i == 0) {
                    dp[0][i] = grid[0][i];
                }
                else {
                    dp[0][i] = dp[0][i - 1] + grid[0][i];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == -1) {
                dp[i][0] = -1e9;
            }
            else {
                if (i == 0) {
                    dp[i][0] = grid[i][0];
                }
                else {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == -1) {
                    dp[i][j] = -1e9;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return res + dp[n - 1][n - 1];
    }
};