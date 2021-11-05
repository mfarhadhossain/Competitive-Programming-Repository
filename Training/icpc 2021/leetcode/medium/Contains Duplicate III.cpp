#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset< int > mul;

        for(int i=0;i<nums.size();i++){
                int key = nums[i];
                int pos = i+1;
                if(mul.size()==0){
                    mul.insert(key);
                }
                else{
                    if(mul.size()==k+1){

                            int lo = key-t;
                            int hi = key+t;

                            auto it = mul.lower_bound(lo);
                            if(it!=mul.end()){

                            }
                    }
                    else{

                    }
                }
        }
    }
};
int main (){
//    multiset< int > mul;
//    mul.insert(1);
//    mul.insert(2);
//    mul.insert(1);
//    mul.insert(6);
//    int key;cin>>key;
//    auto pos= mul.lower_bound(key);
//    if(pos==mul.end())cout<<"bad";
//    else cout<<*pos;
//    main();
//    vector<int>V;
//    int k,t,n;cin>>n>>k>>t;
//    for(int i=0;i<n;i++)cin>>V[i];
//    Solution obj;
//    cout<<obj.containsNearbyAlmostDuplicate(V,k,t)<<endl;
    return 0;
}
