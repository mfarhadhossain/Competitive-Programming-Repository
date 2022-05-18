#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
const int MAX = 1e5 + 10, MOD = 1e9 + 7;
int LIS(vector<int>A) {
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
vector<int> fun(vector<int>&ar) {
    vector<int>temp;
    for (int i = 0; i < ar.size() - 1; i++) {
        temp.push_back(abs(ar[i] - ar[i + 1]));
    }
    return temp;
}
void solve() {
    int n, x; cin >> n >> x;

    vector<int>p, id;
    p.push_back(x);
    for (int i = 1; i <= n - 1; i++)
        id.push_back(i);
    for (int i = 1; i <= n; i++) {
        if (i == x)continue;

        p.push_back(i);
    }
    do {
        vector<int>temp=p;
        for (int i = 1; i < n; i++) {
            //if (i == x)continue;

            temp[i]=p[id[i-1]];
        }
        cout<<"perm: ";
        for(auto x:temp)
            cout<<x<<" ";
        cout<<endl;
        auto rt = fun(temp);
        cout<<"A: ";
        for(auto x:rt)
            cout<<x<<" ";
        cout<<"LIS: "<<LIS(rt)<<endl;
    } while (next_permutation(id.begin(), id.end()));
}
int  main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; //cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve();
    return 0;
}