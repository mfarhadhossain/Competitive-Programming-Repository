class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int tot=n*n;
        int cnt=1,l=0,r=n-1,t=0,b=n-1,direction=0;
        vector<vector<int>>res(n,vector<int>(n,0));
        while(l<=r and b>=t){
                if(direction==0){// left to right
                        for(int i=l;i<=r;i++){
                                res[t][i]=cnt;
                                cnt++;
                        }
                }
                else if(direction==1){ // top to bottom
                        for(int i=t+1;i<=b;i++){
                                res[i][r]=cnt;
                                cnt++;
                        }
                        r--;
                        t++;
                }
                else if(direction==2){//right to left
                        for(int i=r;i>=l;i--){
                                res[b][i]=cnt;
                                cnt++;
                        }
                }
                else{// bottom to top
                        for(int i=b-1;i>=t;i--){
                                res[i][l]=cnt;
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