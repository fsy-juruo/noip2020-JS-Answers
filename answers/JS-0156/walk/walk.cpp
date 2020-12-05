#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
int qr()
{
	int f=1,r=0;
	char ch;
	do
		ch=getchar();
	while (!isdigit(ch)&&ch!='-');
	if (ch=='-')
		f=-1;
	else
		r=ch-48;
	ch=getchar();
	while (isdigit(ch))
	{
		r=r*10+ch-48;
		ch=getchar();
	}
	return f*r;
}
int n,ans,k,w[13],p[13],start[13],cur[13];
const int P=1000000007;
struct node
{
	int x,y;
};
node a[500005];
bool check()
{
	int i;
	for (i=1;i<=k;i++)
		if (cur[i]<1||cur[i]>w[i])
			return false;
	return true;
}
void dfs(int dep)
{
	int i;
	bool fg;
	if (dep>k)
	{
		for (i=1;i<=k;i++)
			cur[i]=start[i];
		while (2020)
		{
			fg=false;
			for (i=1;i<=n;i++)
			{
				cur[a[i].x]+=a[i].y;
				ans=(ans+1)%P;
				if (!check())
				{
					fg=true;
					break;
				}
			}
			if (fg)
				break;
		}
		return;
	}
	for (i=1;i<=w[dep];i++)
	{
		start[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i;
	bool fg=true;
	n=qr();
	k=qr();
	for (i=1;i<=k;i++)
		w[i]=qr();
	for (i=1;i<=n;i++)
	{
		a[i].x=qr();
		a[i].y=qr();
		p[a[i].x]+=a[i].y;
	}
	for (i=1;i<=k;i++)
		if (p[i])
			fg=false;
	if (fg)
	{
		printf("-1\n");
		return 0;
	}
	dfs(1);
	printf("%d\n",ans%P);
	return 0;
}
