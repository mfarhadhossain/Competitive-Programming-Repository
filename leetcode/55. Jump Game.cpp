class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pos=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(pos<i)return false;
            pos=max(pos,i+nums[i]);
        }
        return pos>=n-1;
    }
};