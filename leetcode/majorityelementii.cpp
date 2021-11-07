class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size(),last_pos=0,current_element=nums[0],sz=1;
        vector<int>ret;
        for(int i=1;i<n;i++){
            if(nums[i]==current_element){
                sz=i-last_pos+1;
            }
            else{
                if(sz>n/3){
                    ret.push_back(current_element);
                }
                sz=1;
                last_pos=i;
                current_element=nums[i];
            }
        }
        if(sz>n/3){
            ret.push_back(current_element);
        }
        return ret;
    }
};