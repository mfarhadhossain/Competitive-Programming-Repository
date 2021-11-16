class Solution {
public:
    static const int MAX = 1001;
    int dp[MAX][101][2];
    int go(int idx,int stock,int k,vector<int>& prices){
        if(idx==prices.size())return 0;
        if(k==0)return 0;
        int ret=0;
        if(dp[idx][k][stock]!=-1)
            return dp[idx][k][stock];
        if(stock==0){//have to buy
            ret= -prices[idx]+go(idx+1,1,k,prices);
            ret=max(ret,go(idx+1,0,k,prices));
        }
        else{
            
            ret= prices[idx]+go(idx+1,0,k-1,prices);
            ret=max(ret,go(idx+1,1,k,prices));
        }
        return dp[idx][k][stock]=ret;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        memset(dp,-1,sizeof dp);
        return go(0,0,k,prices);
    }
};