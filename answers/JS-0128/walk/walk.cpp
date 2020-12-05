#include <stdio.h>

struct pos{
	int x[12];
};
int ans;
int n,k,w;
int lim[12];
struct step{
	int c,d;
};
step way[500010];
void run(pos from)
{
	bool flag=true,flagt=false;
	pos now=from;
	while(flag)
	{
		int i;
		for(i=0;i<n;i++)
		{
			ans++;
			if(now.x[way[i].c]+way[i].d>0&&now.x[way[i].c]+way[i].d<=lim[way[i].c])
			{
				if(ans>=1000000007)
					ans-=1000000007;
				now.x[way[i].c]+=way[i].d;
			}
			else
			{
				flag=false;
				flagt=true;
				break;
			}
		}
		bool flag2=false;
		for(int i=1;i<=k;i++)
			if(now.x[i]!=from.x[i])
			{
				flag2=true;
				break;
			}
		if(flag2==false&&!flagt)
		{
			ans=-1;
			return;
		}
	}
}
void init()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",lim+i);
	for(int i=0;i<n;i++)
		scanf("%d%d",&way[i].c,&way[i].d);
	return;
}
pos nps;
void search(int deepth)
{
	if(deepth>k)
	{
		run(nps);
		return;
	}
	for(int i=1;i<=lim[deepth];i++)
	{
		nps.x[deepth]=i;
		search(deepth+1);
		if(ans==-1)
			return;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	init();
	search(1);
	printf("%d\n",ans);
	return 0;
}
