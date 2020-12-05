#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
void read(int &x)
{
	char c;int s=0,f=1;
	while((c=getchar())<'0'||c>'9')if(c=='-')f*=-1;
	s=(c&15);while((c=getchar())>='0'&&c<='9')s=s*10+(c&15);
	x=s*f;
}
unsigned long long gcd(unsigned long long x,unsigned long long y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
unsigned long long lcm(unsigned long long x,unsigned long long y)
{
	return x/gcd(x,y)*y;
}
struct fenshu
{
	unsigned long long x,y;
	fenshu ys()
	{
		unsigned long long g=gcd(x,y);
		return (fenshu){x/g,y/g};
	}
};
fenshu operator +(fenshu x,fenshu y)
{
	fenshu ans;
	unsigned long long t=lcm(x.y,y.y);
	ans.y=t;
	ans.x=t/x.y*x.x+t/y.y*y.x;
	return ans.ys();
}
fenshu operator /(fenshu x,int y)
{
	x.y*=y;return x.ys();
}
fenshu dp[100005];
int vis[100005],rd[100005];
vector<int> bi[100005];
int n,m,i,j;
void dfs(int x)
{
	if(vis[x]) return;vis[x]=1;
	if(bi[x].empty()){
		dp[x].x=dp[x].y=1;
		return;
	}
	dp[x].x=0;dp[x].y=1;
	int i;
	fz0k(i,bi[x].size()){
		dfs(bi[x][i]);
		dp[x]=dp[x]+(dp[bi[x][i]]/rd[bi[x][i]]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	fz1(i,n){
		read(rd[i]);
		fz1(j,rd[i]){
			int x;
			read(x);
			bi[x].push_back(i);
		}
	}
	fz1(i,n)if(!rd[i]){
		dfs(i);
		printf("%llu %llu\n",dp[i].x,dp[i].y);
	}
	return 0;
}
