class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>v;
        for(int i=0;i<=rowIndex;i++){
            vector<int>curr;
            for(int j=0;j<=i;j++){
                if(j==0){
                    curr.push_back(1);
                }
                else{
                    int s = v[j-1];
                    if(j<v.size())s+=v[j];
                    curr.push_back(s);
                }
            }
            v=curr;
        }
        return v;
    }
};