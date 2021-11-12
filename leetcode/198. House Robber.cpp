//recursive
class Solution {
public:
    int dp[111][3];
    int go(int idx,int pr,vector<int>& nums){
        if(idx==nums.size())return 0;
        int ret=0;
        if(dp[idx][pr]!=-1)
            return dp[idx][pr];
        if(pr==0)ret=go(idx+1,1,nums)+nums[idx];
        ret=max(ret,go(idx+1,0,nums));
        return dp[idx][pr]=ret;
            
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return go(0,0,nums);
    }
};
//iterative
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int dp[n+5];
        memset(dp,0,sizeof dp);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};