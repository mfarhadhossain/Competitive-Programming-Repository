#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bsearch(vector<int>& nums, int lo,int hi, int target) {
        //int lo = 0,hi=nums.size()-1;
        while(lo<=hi){
            int md = (lo+hi)/2;
            if(nums[md]==target)
                return md;
            if(nums[md]>target)
                hi=md-1;
            else lo=md+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0,hi=n-1;
        while(lo<=hi){
            int md = (lo+hi)/2;
            if(nums[md]<nums[0])
                hi=md-1;
            else lo=md+1;
        }
        int pivot;
        for(int idx=max(0,lo-5);idx<min(hi+5,n);idx++){
            if(nums[idx]<nums[0]){
                pivot=idx;
                break;
            }
        }
        int res = bsearch(nums,0,pivot-1,target);
        if(res!=-1) return res;
        return bsearch(nums,pivot,nums.size()-1,target);
    }
};
int main (){
	Solution obj;
	vector<int>v={1,2,3,4,5,6,7,8,0};

	cout<<obj.search(v,0)<<endl;
	return 0;
}