//TLE
class Solution {
public:
    int bruteforce(vector<int>& values){
        int res=0,n = values.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=max(res,values[i]+values[j]+i-j);
            }
        }
        return res;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        return bruteforce(values);
    }
};