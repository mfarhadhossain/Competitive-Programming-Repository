#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
#define m_p make_pair
typedef long long int ll;
int nb,nr,k,par[3015];
int find_parent(int x){
	if(par[x]==x)
		return x;
	return find_parent(par[x]);
}
int go(int u,int v){
	int d = 0,g=0;
	int xx = u;
	std::vector<bool> vis(3010);
	while(true){
		//cout<<xx<<endl;
		if(vis[xx])break;
		vis[xx]=1;
		if(xx == par[xx]){
		    if(xx == v){
		        g=1;
		        break;
		    }
		    else{
		        g=0;
		        break;
		    }
		}
		xx=par[xx];
		d++;
		/*if(d>10000){
		    break;
		}*/
	}
	if(g)return d;
	return INT_MAX;
}
void Union(int u,int v){
	par[u]=v;
}
// R1 = 1
// B1 = 1002
void solve(){
	cin>>nr>>nb>>k;
	for(int i=1;i<=nr;i++)
		par[i]=i;
	for(int i=1;i<=nb;i++)
		par[i+1005]=i+1005;
	for(int i=1;i<=nr-1;i++){
		int x;
		char ch;
		//scanf("%c%d",&ch,&x);
		cin>>ch>>x;
		if(ch=='R'){
			par[i+1]=x;
		}
	}
	for(int i=1;i<=nb-1;i++){
		int x;
		char ch;
		//scanf("%c%d",&ch,&x);
		cin>>ch>>x;
		if(ch=='B'){
			par[i+1005]=x+1005;
		}
	}
	//cout<<"looper por!\n";
	//getchar();
	for(int i=0;i<k;i++){
		char ch,ch2,ch3;
		int d2,d3;
		//scanf("%c %c%d %c%d",&ch,&ch2,&d2,&ch3,&d3);
		cin>>ch>>ch2>>d2>>ch3>>d3;
		//getchar();
		if(ch2=='B')
			d2+=1005;
		if(ch3=='B')
			d3+=1005;

		//cout<<ch<<" "<<ch2<<d2<<" "<<ch3<<d3<<endl;
		if(ch=='w'){
			int s1,t1,s2,t2;
			s1=d2;
			s2=d3;
			if(ch2=='R'){
				t1=1;
			}
			else{
				t1=1006;
			}
			if(ch3=='R'){
				t2=1;
			}
			else{
				t2=1006;
			}
			int dist1 = go(s1,t1);
			int dist2 = go(s2,t2);
			//cout<<endl;
			//cout<<ch2<<d2<<" to "<<ch2<<t1<<" = "<<dist1<<endl;
			//cout<<ch3<<d3<<" to "<<ch3<<t2<<" = "<<dist2<<endl;
			if(dist1==dist2 && dist1==INT_MAX){
				cout<<"NONE\n";
			}
			else if(dist1==dist2 && dist1!=INT_MAX){
				cout<<"TIE "<<dist1<<endl;
			}
			else if(dist1<dist2){
				if(ch2=='R')
				cout<<"RED "<<dist1<<endl;
				if(ch2=='B')
				cout<<"BLUE "<<dist1<<endl;
			}
			else{
				if(ch3=='R')
				cout<<"RED "<<dist2<<endl;
				if(ch3=='B')
				cout<<"BLUE "<<dist2<<endl;
			}
		}
		else{ // union
			Union(d2,d3);
		}
	}
}
int main (){
	//ios_base::sync_with_stdio(false);cin.tie(0);
	
	int t=1;cin>>t;
	//scanf("%d",&t);
	while(t--)solve();
	return 0;
}