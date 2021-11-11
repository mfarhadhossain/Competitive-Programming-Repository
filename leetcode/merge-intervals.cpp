class Solution {
public:
    bool overlaps(vector<int>&tmp,vector<int>&interval){
        if(tmp[1]<interval[0] or interval[1]<tmp[0])return 0;
        return 1;
    }
    vector<int> overlapped(vector<int>&tmp,vector<int>&interval){
        vector<int>ret;
        ret.push_back(min(tmp[0],interval[0]));
        ret.push_back(max(tmp[1],interval[1]));
        return ret;
    }
    static bool sortfun(vector<int>&v1,vector<int>&v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),sortfun);
        int n = intervals.size();
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            vector<int>tmp = res.back();
            if(overlaps(tmp,intervals[i])){
                res.pop_back();
                res.push_back(overlapped(tmp,intervals[i]));
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};