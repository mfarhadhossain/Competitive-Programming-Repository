#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 998244353;
string s;
ll md[5555],fac[5555];
vector<int>cnt(30), ar;
ll go(int idx, int tot) {
	if(tot==0)return 1;
	if(tot<0)return 0;
	if (idx == ar.size()) {
		if (tot == 0)return 1;
		return 0;
	}
	ll res = 1;
	for (int i = 0; i <= ar[idx]; i++) {
		if(tot-i>=0)
		res *= go(idx + 1, tot - i) % MOD;
		//if(i>=2) res *= md[i];
		res %=MOD;
	}
	cout<<idx<<" "<<tot<<" "<<res<<endl;
	return res;
}
inline ll BigMod(ll a,ll e,ll mod)
{
    ll num=1;
    while(e)
    {
        if(e%2)
        {
            a%=mod;
            num%=mod;
            num=num * a;
            num%=mod;
        }
        e/=2;
        a%=mod;
        a=a * a;
        a%=mod;
    }
    return num%mod;
}
inline ll modInverse(ll A,ll P)
{
    return BigMod(A,P-2,P);
}
int  main ()
{
	fac[0]=1;
	fac[1]=1;
	md[0]=modInverse(fac[0],MOD);
	md[1]=modInverse(fac[1],MOD);

	for(int i=2;i<=5005;i++){

		fac[i] = (fac[i-1]*i)%MOD;
		md[i] = modInverse(fac[i],MOD);
	}
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		cnt[s[i] - 'a']++;

	ll res = 0;
	ll nfac=1;
	for(int i=1;i<=s.size();i++){
		nfac = nfac * i;
		nfac%=MOD;
	}
	// for (int i = 1; i <= s.;size(); i++) {
	// 	res += go(0, i);
	// 	res %= MOD;
	// }
	//cout << res << endl;

	for(int a=0;a<=cnt[0];a++)
		for(int b=0;b<=cnt[1];b++)
	for(int c=0;c<=cnt[2];c++)
	for(int d=0;d<=cnt[3];d++)
	for(int e=0;e<=cnt[4];e++)
	for(int f=0;f<=cnt[5];f++)
	for(int g=0;g<=cnt[6];g++)
	for(int h=0;h<=cnt[7];h++)
	for(int i=0;i<=cnt[8];i++)
	for(int j=0;j<=cnt[9];j++)
	for(int k=0;k<=cnt[10];k++)
	for(int l=0;l<=cnt[11];l++)
	for(int m=0;m<=cnt[12];m++)
	for(int n=0;n<=cnt[13];n++)
	for(int o=0;o<=cnt[14];o++)
	for(int p=0;p<=cnt[15];p++)
	for(int q=0;q<=cnt[16];q++)
	for(int r=0;r<=cnt[17];r++)
	for(int s=0;s<=cnt[18];s++)
	for(int t=0;t<=cnt[19];t++)
	for(int u=0;u<=cnt[20];u++)
	for(int v=0;v<=cnt[21];v++)
	for(int w=0;w<=cnt[22];w++)
	for(int x=0;x<=cnt[23];x++)
	for(int y=0;y<=cnt[24];y++)
	for(int z=0;z<=cnt[25];z++){
		int tt = a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z;
		if(tt){
			ll ret=nfac;
			ret=(ret*md[a])%MOD;
			ret=(ret*md[b])%MOD;
			ret=(ret*md[c])%MOD;
			ret=(ret*md[d])%MOD;
			ret=(ret*md[e])%MOD;
			ret=(ret*md[f])%MOD;
			ret=(ret*md[g])%MOD;
			ret=(ret*md[h])%MOD;
			ret=(ret*md[i])%MOD;
			ret=(ret*md[j])%MOD;
			ret=(ret*md[k])%MOD;
			ret=(ret*md[l])%MOD;
			ret=(ret*md[m])%MOD;
			ret=(ret*md[n])%MOD;
			ret=(ret*md[o])%MOD;
			ret=(ret*md[p])%MOD;
			ret=(ret*md[q])%MOD;
			ret=(ret*md[r])%MOD;
			ret=(ret*md[s])%MOD;
			ret=(ret*md[t])%MOD;
			ret=(ret*md[u])%MOD;
			ret=(ret*md[v])%MOD;
			ret=(ret*md[w])%MOD;
			ret=(ret*md[x])%MOD;
			ret=(ret*md[y])%MOD;
			ret=(ret*md[z])%MOD;
			res = (res + ret)%MOD;
		}
	}
	cout<<res/3<<endl;
	return 0;
}