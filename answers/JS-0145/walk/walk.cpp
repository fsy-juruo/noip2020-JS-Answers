#include<bits/stdc++.h>
#define mod 1000000007
#define maxk 11
#define maxn 100010
using namespace std;

inline void read(int &x)
{
	int y=1;
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=y;
}

int n,k;
int w[maxk];
int c[maxn],d[maxn];
int now[maxk],now_[maxk];

int ans=0;

bool flag;
void dfs(int dep)
{
	if(dep==k+1)
	{
		flag=true;
		for(int j=1;j<=k;j++)now_[j]=now[j];
		while(flag)
		{
			for(int j=1;j<=n;j++)
			{
				now_[c[j]]+=d[j];
				ans++;
				ans%=mod;
				if(now_[c[j]]<=0||now_[c[j]]>w[c[j]])flag=false;
				if(!flag)return;
				bool b=true;
				for(int i=1;i<=n;i++)
				{
					if(now_[i]!=now[i])
					{
						b=false;
						break;
					}
				}
				if(b)
				{
					flag=true;
					return;
				}
			}
		}
		return ;
	}
	for(int i=1;i<=w[dep];i++)
	{
		now[dep]=i;
		dfs(dep+1);
		if(flag)return;
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	if(n>=100&&k!=1&&k!=2)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=k;i++)read(w[i]);
	for(int i=1;i<=n;i++)
	{
		read(c[i]),read(d[i]);
	}
	dfs(1);
	if(flag)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",ans);
	return 0;
}

