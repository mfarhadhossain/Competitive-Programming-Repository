//TLE
class Solution {
public:
    const int MOD = 1e9+7,base=786433;
    vector< pair<int,int> > pos[200005],neg[200005];
    int fun(vector<int>a){
        long long x = a[0];
        x*= base;
        x*=base;
        long long y = a[1];
        y*= base;
        return (x+y+a[2])%MOD;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        //ios_base::sync_with_stdio(false);cin.tie(0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int s = nums[i]+nums[j];
                if(s>=0)pos[s].push_back({i,j});
                else neg[-s].push_back({i,j});
            }
        }
        vector<vector<int>>res;
        unordered_map<int,int>map_i,map_v;
        for(int i=0;i<n;i++){
            if(map_i[nums[i]])continue;
            map_i[nums[i]]=1;
            int need=-nums[i];
            if(nums[i]==0)
                need=0;
            
            if(need>=0){
                for(auto &x:pos[need]){
                    if(x.first!=i && x.second!=i){
                        vector<int>tmp={nums[i],nums[x.first],nums[x.second]};
                        //vector<int>tmp2={i+1,x.first+1,1+x.second};
                        sort(tmp.begin(),tmp.end());
                        int y = fun(tmp);
                        if(map_v[y])continue;
                            map_v[y]=1;
                        
                        res.push_back(tmp);
                        
                    }
                }
            }
            else{
                need*=-1;
                for(auto &x:neg[need]){
                        if(x.first!=i && x.second!=i){
                            vector<int>tmp={nums[i],nums[x.first],nums[x.second]};
                            //vector<int>tmp2={i+1,x.first+1,1+x.second};
                            sort(tmp.begin(),tmp.end());
                            int y = fun(tmp);
                            if(map_v[y])continue;
                                map_v[y]=1;
                                res.push_back(tmp);
                        }
                }
            }
        }
        return res;
    }
};