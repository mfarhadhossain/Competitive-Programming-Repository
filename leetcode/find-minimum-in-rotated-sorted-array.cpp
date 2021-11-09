class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0,hi=n-1;
        while(lo<=hi){
            int md = (lo+hi)/2;
            if(nums[md]<nums[0])
                hi=md-1;
            else lo=md+1;
        }
        int pivot=0;
        for(int idx=max(0,lo-5);idx<min(hi+5,n);idx++){
            if(nums[idx]<nums[0]){
                pivot=idx;
                break;
            }
        }
        return min(nums[0],nums[pivot]);
    }
};