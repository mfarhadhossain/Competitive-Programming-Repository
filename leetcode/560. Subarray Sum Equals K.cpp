class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,res=0,n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)res++;
            res+=map[sum-k];
            map[sum]++;
            
        }
        return res;
    }
};