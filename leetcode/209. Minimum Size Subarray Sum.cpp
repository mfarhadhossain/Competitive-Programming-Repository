class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size(),s=0;
        int res=1e9;
        for(int r=0,l=0;r<n;r++){
            s+=nums[r];
            while(l<=r&&s>=target){
                res=min(res,r-l+1);
                s-=nums[l];
                l++;
            }
        }
        if(res==1e9)res=0;
        return res;
    }
};