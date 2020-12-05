#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int s = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c))
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s * f;
}
const int maxn = 1e5 + 5;
int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b,a % b);
}
struct decimal{
	int a,b;
	decimal(int _a = 0,int _b = 1)
	{
		a = _a,b = _b;
		doit();	
	}
	void doit()
	{
		int c = gcd(a,b);
		a /= c,b /= c;
	}
	void display()
	{
		printf("%lld %lld\n",a,b);
	}
	decimal operator +(const decimal &y)const
	{
		decimal ret = decimal(a * y.b + y.a * b,b * y.b);
//		printf("%d %d\n",a,b);
//		printf("*****\n");
//		printf("%d %d\n",y.a,y.b);
//		printf("*****\n");
//		ret.display();
//		printf("****\n");
		
		ret.doit();
		return ret;
	}
	decimal operator /(const int &k)const
	{
		decimal ret = decimal(a,b);
		ret.b *= k;
		ret.doit();
		return ret;
	}
	
};
decimal dp[maxn];
int sz[maxn];

int n,m;
int head[maxn],to[maxn << 1],nxt[maxn << 1],tot;
void add(int a,int b)
{
	to[++tot] = b;
	nxt[tot] = head[a];
	head[a] = tot;
	sz[b]++;
}
decimal dfs(int x)
{
	if(dp[x].a != -1)
	{
		return dp[x];
	}
	decimal ret;
	for(int i = head[x];i;i = nxt[i])
	{
//		printf("%d += %d / %d\n",x,to[i],sz[to[i]]);
		ret = ret + (dfs(to[i]) / sz[to[i]]);
	}
	return dp[x] = ret;
}
signed main()
{
	
//	decimal now1 = decimal(5,3);
//	decimal now2 = decimal(5,3);
//	decimal ans = now1 + now2;
//	ans.display();
	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n; ++i)
	{
		int d = read(),x;
		while(d--)
		{
			x = read();
			add(x,i);
		}
		dp[i].a = -1;
	}
	for(int i = 1;i <= m; ++i)
	{
		dp[i] = decimal(1,1);
	}
	for(int i = 1;i <= n; ++i)
	{
		if(sz[i] == 0)
		{
			dfs(i);
			dp[i].display();
//			printf("%d %d\n",dp[i].a,dp[i].b);
		}
	}
	return 0;
}
