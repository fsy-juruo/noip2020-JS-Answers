#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define mpr make_pair
#define pii pair<int,int>  /**/
#define fs first
#define sc second
#define vi vector<int>  /**/
#define vp vector<pii>  /**/
#define iter iterator
#define SZ(V) ((int)V.size())
#define EN(V) (V[SZ(V)-1])

template<typename T>
inline void cmax(T& x,T y)
{
	if(x<y) x=y;
}

template<typename T>
inline void cmin(T& x,T y)
{
	if(x>y) x=y;
}

char R_C; int R_RES; int R_F;
inline int read()
{
	R_C='!'; R_RES=0; R_F=0;
	while(R_C<'0' || R_C>'9')
	{
		R_C=getchar();
		if(R_C=='-') R_F=1;
	}
	while(R_C>='0' && R_C<='9')
	{
		R_RES=(R_RES<<1)+(R_RES<<3)+(R_C^48);
		R_C=getchar();
	}
	return R_F?(-R_RES):R_RES;
}

const int maxn=10000000;

bool usp[maxn];
signed P[maxn],pcnt;

void init_p()
{
	usp[1]=true;
	for(int i=2;i<maxn;i++)
	{
		if(!usp[i]) P[++pcnt]=i;
		for(int j=1;j<=pcnt && i*P[j]<maxn;j++)
		{
			usp[i*P[j]]=true;
			if(i%P[j]==0) break;
		}
	}
}

int N,M;
vi e[100010];
vi fr[100010];

bool vis[100010];
pii dp[100010];

inline void nm(pii& x)
{
	if(!x.fs)
	{
		x=mpr(0,1);
		return;
	}
	pii t=mpr(1,1);
	for(int i=1;i<=pcnt;i++)
	{
		while(x.fs%P[i]==0 && x.sc%P[i]==0)
		{
			x.fs/=P[i]; x.sc/=P[i];
		}
		while(x.fs%P[i]==0)
		{
			t.fs*=P[i];
			x.fs/=P[i];
		}
		while(x.sc%P[i]==0)
		{
			t.sc*=P[i];
			x.sc/=P[i];
		}
		if(P[i]>x.fs || P[i]>x.sc) break;
	}
	x.fs*=t.fs;
	x.sc*=t.sc;
}

inline void add(pii& x,pii y)
{
	x=mpr(x.fs*y.sc+x.sc*y.fs , x.sc*y.sc);
	nm(x);
}

void DFS(int u)
{
	if(u<=M)
	{
		dp[u]=mpr(1,1);
	}
	for(int i=0;i<SZ(fr[u]);i++)
	{
		int& f=fr[u][i];
		if(!vis[f]) DFS(f);
	}
	if(!dp[u].fs) return;
	int t=SZ(e[u]);
	pii k=mpr(dp[u].fs,dp[u].sc*t);
	for(int i=2;i<=t;i++)
	{
		while(k.fs%i==0 && k.sc%i==0)
		{
			k.fs/=i; k.sc/=i;
		}
	}
	for(int i=0;i<SZ(e[u]);i++)
	{
		int& to=e[u][i];
		add(dp[to],k);
	}
	vis[u]=true;
}

signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	init_p();
	N=read(); M=read();
	for(int i=1;i<=N;i++)
	{
		int d=read(),x;
		for(int j=1;j<=d;j++)
		{
			x=read();
			e[i].pb(x);
			fr[x].pb(i);
		}
	}
	for(int i=1;i<=N;i++)
	{
		dp[i]=mpr(0,1);
	}
	for(int i=1;i<=N;i++)
	{
		if(e[i].empty()) DFS(i);
	}
	for(int i=1;i<=N;i++)
	{
		if(e[i].empty())
		{
			nm(dp[i]);
			printf("%lld %lld\n",dp[i].fs,dp[i].sc);
		}
	}
	
	return 0;
}









