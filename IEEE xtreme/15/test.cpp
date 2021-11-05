/*

    author : s@if

*/

#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define 		NIL 			-1
#define			INF 			1e18
#define         EPS             1e-9
#define         SAIF            main
#define		 	fi	 		    first
#define 		sec 			second
#define 		MAX 			INT_MAX
#define 		ll 			    long long
#define 		PI 			    acos(-1.0)
#define			MOD 			1000000007
#define 		PLL 			pair<ll,ll>
#define 		PII			    pair<int,int>
#define 		ull 			unsigned long long
#define 		For(i,a,b) 		for(int i=a;i<=(int)b;i++)
//typedef tree<int, null_type, less<int>, rb_tree_tag,
           // tree_order_statistics_node_update> new_data_set;

//*find_by_order(k)  gives the kth element;
//order_of_key(item)   gives the index(number of element strictly less than item) of item;

inline int in() {int x; scanf("%d", &x); return x; }
bool Check(int N , int pos)	{	return (bool) (N & (1<<pos));}
int Set(int N, int pos) {	return N = N | (1<<pos);}

int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};    // King's move
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
int hx[]={-2,-2,-1,+1,+2,+2,-1,+1};    // Knight's move
int hy[]={+1,-1,+2,+2,-1,+1,-2,-2};
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

const int MAXN = (int)1e3+9;

vector<vector<vector<vector<ll> > > >dp;
vector<vector<vector<vector<int> > > >mark;
ll m, x, y, k;
ll a[MAXN][MAXN];

ll solve(int M, int X, int Y, int K)
{
    //cout<<M<<" "<<X<<" "<<Y<<" "<<K<<endl;
    if(M==m){return 0;}

    if(mark[M][X][Y][K]!=-1)
    {
        return dp[M][X][Y][K];
    }

    ll ret = -INF;
    if(X==x-1){
        if(Y+1==y && K<k) ret = max(ret,a[M][X]+solve(M+1,0, 0, K+1));
        if(Y==y) ret = max(ret, solve(M+1, 0, 0, 0));
    }
    else{
    if(Y<y && K<k)
        ret = max(ret,a[M][X]+solve(M, X+1, Y+1, K+1));
    ret = max(ret, solve(M, X+1, Y, 0));
    }

    //cout<<ret<<endl;
    mark[M][X][Y][K] = 1;
    return dp[M][X][Y][K] = ret;
}

void solve(void)
{
    int i,j,l,n,p,q,u,v,w,r,tc,t;

    cin>>m>>x>>y>>k;
    dp.resize(m);
    mark.resize(m);
    for(i=0; i<m; i++)
    {
        dp[i].resize(x);
        mark[i].resize(x);
        for(j=0; j<x; j++)
        {
            dp[i][j].resize(y+9);
            mark[i][j].resize(y+9);
            for(l=0; l<y+9; l++){
                dp[i][j][l].resize(k);
                mark[i][j][l].resize(k);
            }
        }
    }
    for(i=0; i<m; i++)
    {
        for(j=0; j<x; j++)
        {
            for(l=0; l<y+9; l++)
            {
                for(p=0; p<k; p++){
                    mark[i][j][l][p] = -1;
                }
            }
        }
    }

    for(i=0; i<m; i++)
    {
        for(j=0; j<x; j++)
            cin>>a[i][j];
    }

    ll ans = solve(0,0,0,0);
    if(ans<0) cout<<"IMPOSSIBLE\n";
    else cout<<ans<<endl;


    return;
}

int SAIF()
{
    int tc = 1, t = 0;

    cin>>tc;

    while(tc--) solve();

    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
