// bruteforce
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX = 1e5+7;
ll order[MAX],cooking[MAX];
int main() {
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>order[i]>>cooking[i];
    }
    ll time = 0,wait=0;
    vector<bool> delivered(n+5);
    for(int i=0;i<n;i++){
        if(i==0){
            wait+=time-order[i];
            time+=cooking[i];
            wait+=cooking[i];
            delivered[i]=true;
        }
        else{
            vector< pair<ll, int> > help;
            //cout<<"at "<<i<<":\n";
            for(int j=0;j<n;j++){
                if(delivered[j])continue;

                help.push_back({time-order[j]+cooking[j],j});
                //cout<<"wait time of "<<j+1<<" "<<time-order[j]+cooking[j]<<endl;
            }
            sort(help.begin(),help.end());

            delivered[help[0].second]=true;
            wait+=help[0].first;
            time+=cooking[help[0].second];
        }
        //cout<<wait<<endl;
    }
    wait/=n;
    cout<<wait<<endl;
    return 0;
}
