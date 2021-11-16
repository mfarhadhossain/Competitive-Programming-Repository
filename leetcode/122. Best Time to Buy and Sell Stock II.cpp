class Solution {
public:
    static const int MAX = 30005;
    int dp[MAX][5];
    int go(int idx,int stock,vector<int>& prices){
        if(idx==prices.size())return 0;
        int ret=0;
        if(dp[idx][stock]!=-1)
            return dp[idx][stock];
        if(stock==0){//have to buy
            ret= -prices[idx]+go(idx+1,1,prices);
            ret=max(ret,go(idx+1,0,prices));
        }
        else{
            
            ret= prices[idx]+go(idx+1,0,prices);
            ret=max(ret,go(idx+1,1,prices));
        }
        return dp[idx][stock]=ret;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return go(0,0,prices);
    }
};