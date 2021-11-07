class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size(),last_pos=0,current_element=nums[0],sz=1,mx=0,res=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==current_element){
                sz=i-last_pos+1;
                if(mx<sz){
                    mx = sz;
                    res = current_element;
                }
            }
            else{
                if(mx<sz){
                    mx = sz;
                    res = current_element;
                }
                sz=1;
                last_pos=i;
                current_element=nums[i];
            }
        }
        return res;
    }
};