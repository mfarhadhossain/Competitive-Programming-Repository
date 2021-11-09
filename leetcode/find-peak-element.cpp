// WA
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 0;
        
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        
        
        int lg=log2(n*1.0+10);
        for(int i=1;i<=lg;i++){
            int r = rand()%n;
            if(r==0){
                if(nums[0]>nums[1])
                    return r;
            }
            else if(r==n-1){
                
                if(nums[n-1]>nums[n-2])
                    return r;
            }
            else if(nums[r]>nums[r-1]&&nums[r]>nums[r+1])
                return r;
        }
        return 0;
    }
};