class Solution {
public:
    int go(int idx,vector<int>& nums,vector<int>& dp){
        if(idx==nums.size()-1)
            return 0;
        if(idx>=nums.size())
            return 1e9;
        if(dp[idx]!=1e9)
            return dp[idx];
        int ret=1e9;
        for(int i=1;i<=nums[idx];i++){
            ret=min(ret,1+go(idx+i,nums,dp));
        }
        return dp[idx]=ret;
    }
    int iterative(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=1000&&i-j>=0;j++){
                if(nums[i-j]>=j)
                dp[i]=min(dp[i],1+dp[i-j]);
            }
        }
        return dp[n-1];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+5,1e9);
        return go(0,nums,dp);
    }
};