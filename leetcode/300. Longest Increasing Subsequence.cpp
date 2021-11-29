class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        vector<int>B;
        B.push_back(A[0]);
        for (int i = 1; i < A.size(); i++) {
            auto it = lower_bound(B.begin(), B.end(), A[i]) - B.begin(); // increasing
            //auto it = upper_bound(B.begin(),B.end(),A[i])-B.begin(); // Non-Decresing
            if (it >= B.size()) {
                B.push_back(A[i]);
            }
            else B[it] = A[i];
        }
        return B.size();
    }
};