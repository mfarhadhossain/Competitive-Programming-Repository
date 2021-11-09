// bruteforce
class Solution {
public:
    bool increasing(vector<int>&x){
        int mx=0;
        for(int i=0;i<x.size();i++){
            if(x[i]<=mx)return 0;
            mx=max(mx,x[i]);
        }
        return 1;
    }
    bool canBeIncreasing(vector<int>& nums) {
        if(increasing(nums))return 1;
        
        for(int i=0;i<nums.size();i++){
            vector<int>tmp;
            for(int j=0;j<nums.size();j++){
                if(j==i)continue;
                tmp.push_back(nums[j]);
            }
            if(increasing(tmp))return 1;
        }
        return 0;
    }
};