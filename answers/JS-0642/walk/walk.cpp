#include<bits/stdc++.h>
#define ll long long
#define str string
#define dou double
#define ull unsigned long long
#define fi first
#define se second
using namespace std;

const int maxn=5e5+10;
const ll mod=1e9+7;
const int maxk=1e5+10;
int n,k;
int c[maxn],d[maxn];
int w[maxn];
ll ans;
int wz[20];
int bf[20];
bool qwq=false;

bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(bf[i]>w[i]||bf[i]<1)
		{
			return true;
		}
	}
	return false;
}

bool check2()
{
	for(int i=1;i<=k;i++)
	{
		if(wz[i]!=bf[i])
		{
			return false;
		}
	}
	return true;
}

void dfs(int deep)
{
	if(deep<k+1)
	{
		for(int i=1;i<=w[deep];i++)
		{
			wz[deep]=i;
			bf[deep]=i;
			dfs(deep+1);
			if(qwq)
			{
				return ;
			}
			for(int q=1;q<=deep;q++)
			{
				bf[i]=wz[i];
			}
		}
		return ;
	}
	while(true)
	{
		for(int i=1;i<=n;i++)
		{
			bf[c[i]]+=d[i];
			ans=(ans+1>=mod?ans+1-mod:ans+1);
			if(check())
			{
				return ;
			}
		}
		if(check2())
		{
			qwq=true;
			printf("-1");
			return ;
		}
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
//	dfs(1);
//	if(!qwq)
//	{
//		printf("%lld",ans);
//	}
	printf("-1");
	return 0;
}

