#include<bits/stdc++.h>
#define re register
#define x a[cnt].s[i]
using namespace std;
inline int read(){
	char c=getchar();bool fu=0;int a=0;
	while(c<'0'||c>'9'){if(c=='-')fu=1;else fu=0;c=getchar();}
	while(c>='0'&&c<='9')
	{
		a=(a<<3)+(a<<1)+(c^48);
		c=getchar();
	}
	return fu?(-a):a;
}
int n,m;
bool flag[100005];
long long gcd(long long a,long long b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
struct node{
	vector<int>s;
	int v;
	long long f1,f2;
}a[100005];
void ch(int cnt,long long o,long long p)
{
	o*=a[cnt].f2;a[cnt].f2*=p;
	a[cnt].f1=a[cnt].f1*p+o;
	long long gc=gcd(a[cnt].f1,a[cnt].f2);
	a[cnt].f1/=gc;a[cnt].f2/=gc;
	return;
}
void dfs(int cnt)
{
	a[cnt].v--;
	if(a[cnt].v)return;
	int si=a[cnt].s.size();
	if(si)
	for(re int i=0;i<si;++i)
	{
		ch(x,a[cnt].f1,a[cnt].f2*si);
		dfs(x);
	}
	else flag[cnt]=1;
	return;
}
void dfs2(int cnt)
{
	a[cnt].v++;
	if(a[cnt].v-1)return;
	for(re int i=0;i<a[cnt].s.size();++i)dfs2(x);
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(re int i=1;i<=n;++i)
	{
		a[i].f2=1;
		int k=read();
		while(k--)a[i].s.push_back(read());
	}
	for(re int i=1;i<=m;++i)a[i].f1++;
	for(re int i=1;i<=m;++i)if(!a[i].v)dfs2(i);
	for(re int i=1;i<=m;++i)if(a[i].v)dfs(i);
	for(re int i=1;i<=n;++i)if(flag[i])printf("%lld %lld\n",a[i].f1,a[i].f2);
	return 0;
}
