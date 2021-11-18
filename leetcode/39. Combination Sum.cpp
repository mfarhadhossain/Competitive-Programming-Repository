class Solution {
public:
    vector<vector<int>>res;
    map<vector<int>,int>map;
    void go(int idx,int rem,vector<int>& candidates,vector<int>&ret){
        if(idx>=candidates.size())
            return;
        if(rem==0){
            if(map[ret]==0){
                res.push_back(ret);
                return;
            }
            return;
        }
        if(rem-candidates[idx]>=0){
            ret.push_back(candidates[idx]);
            go(idx,rem-candidates[idx],candidates,ret);
            ret.pop_back();
        }
        go(idx+1,rem,candidates,ret);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ret;
        sort(candidates.begin(),candidates.end());
        go(0,target,candidates,ret);
        return res;
    }
};