class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int tot=n*m;
        int cnt=0,l=0,r=m-1,t=0,b=n-1,direction=0;
        vector<int>res;
        while(l<=r and b>=t){
                if(direction==0){// left to right
                        for(int i=l;i<=r;i++){
                                res.push_back(matrix[t][i]);
                                cnt++;
                        }
                }
                else if(direction==1){ // top to bottom
                        for(int i=t+1;i<=b;i++){
                                res.push_back(matrix[i][r]);
                                cnt++;
                        }
                        r--;
                        t++;
                }
                else if(direction==2){//right to left
                        for(int i=r;i>=l;i--){
                                res.push_back(matrix[b][i]);
                                cnt++;
                        }
                }
                else{// bottom to top
                        for(int i=b-1;i>=t;i--){
                                res.push_back(matrix[i][l]);
                                cnt++;
                        }
                        l++;
                        b--;
                }
                direction=(direction+1)%4;
        }
        return res;
}
};