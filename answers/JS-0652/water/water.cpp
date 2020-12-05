#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(ne)x=-x;
}
void prt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)prt(x/10);
	putchar(x%10^48);
}
const int N=100000;
int n,m;
vector<int> rnei[N+1];
int odeg[N+1];
bool vis[N+1];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct frac{
	int son,ma;
	frac(int _son=0,int _ma=1){son=_son,ma=_ma;}
	friend frac operator+(frac x,frac y){
		int lcm=x.ma/gcd(x.ma,y.ma)*y.ma;
		x.son*=lcm/x.ma;
		y.son*=lcm/y.ma;
		int tmp=x.son+y.son;
		return frac(tmp/gcd(tmp,lcm),lcm/gcd(tmp,lcm));
	}
	friend frac operator*(frac x,frac y){
		int tmp=gcd(x.son,y.ma);
		x.son/=tmp,y.ma/=tmp;
		tmp=gcd(y.son,x.ma);
		y.son/=tmp,x.ma/=tmp;
		return frac(x.son*y.son,x.ma*y.ma);
	}
	void prtt(){
		prt(son),putchar(' '),prt(ma),putchar('\n');
	}
}dp[N+1];
void dfs(int x){
	vis[x]=true;
	if(rnei[x].empty())return dp[x]=frac(1,1),void();
	for(int i=0;i<rnei[x].size();i++){
		int y=rnei[x][i];
		if(!vis[y])dfs(y);
		dp[x]=dp[x]+dp[y]*frac(1,odeg[y]);
	}
}
signed main(){
	freopen("water.in","r",stdin);freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		int di;
		read(di);
		odeg[i]=di;
		while(di--){
			int x;
			read(x);
			rnei[x].pb(i);
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++)if(!odeg[i])dp[i].prtt();
	return 0;
}
