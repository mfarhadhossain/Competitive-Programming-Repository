#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pi;

ll fx(ll x){
    ll s=0;
    while(x){
        s+=x%10;
        x/=10;
    }
    return s;
}
ll gx(ll x){
    ll m=1;
    while(x){
        m*=((x%10)+1);
        x/=10;
    }
    return m;
}

int main()
{
    multiset<int> mul;
    mul.insert(2);
    mul.insert(2);
    mul.insert(1);
    for(auto x:mul)
        cout<<x<<" ";
    cout<<endl;
    mul.erase(1);
    for(auto x:mul)
        cout<<x<<" ";
    cout<<endl;
    // int t,q,qu;
    // ll a;
    // cin>>t;
    // for(int cs=1; cs<=t; cs++)
    // {
    //     scanf("%d",&q);
    //     printf("Case %d:\n",cs);
    //     set<ll>speed,pnt;
    //     map<ll,priority_queue<ll> > price;
    //     map<ll,int>cnt;
    //     while(q--)
    //     {
    //         scanf("%d",&qu);
    //         if(qu==1)
    //         {
    //             scanf("%lld",&a);
    //             ll point=fx(a)*gx(a);
    //             cnt[point]++;
    //             speed.insert(a);
    //             if(pnt.empty())price[a].push(-point);
    //             else
    //             {
    //                 auto it=pnt.lower_bound(point);
    //                 if(it==pnt.end())it--;
    //                 ll mn=abs(*it-point);
    //                 if(it!=pnt.begin())
    //                 {
    //                     it--;
    //                     mn=min(mn,abs(*it-point));
    //                 }
    //                 price[a].push(-mn);
    //             }
    //             pnt.insert(point);
    //         }
    //         else if(qu==2)
    //         {
    //             if(speed.empty())printf("-1\n");
    //             else
    //             {
    //                 auto it=speed.end();
    //                 it--;
    //                 a=-price[*it].top();
    //                 price[*it].pop();
    //                 ll point=fx(*it)*gx(*it);
    //                 cnt[point]--;
    //                 if(cnt[point]==0)pnt.erase(point);
    //                 if(price[*it].empty())speed.erase(*it);
    //                 printf("%lld\n",a);

    //             }
    //         }
    //         else
    //         {
    //             if(speed.empty())printf("-1\n");
    //             else
    //             {
    //                 auto it=speed.begin();
    //                 a=-price[*it].top();
    //                 price[*it].pop();
    //                 ll point=fx(*it)*gx(*it);
    //                 cnt[point]--;\
    //                 if(cnt[point]==0)pnt.erase(point);
    //                 if(price[*it].empty())speed.erase(*it);
    //                 printf("%lld\n",a);
    //             }
    //         }

    //     }
    // }
    return 0;
}