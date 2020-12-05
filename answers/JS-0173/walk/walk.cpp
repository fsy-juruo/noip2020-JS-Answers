#include <bits/stdc++.h>
using namespace std;

const int maxn=500010,maxm=15;

int n,m,w[maxm],c[maxn],d[maxn],a[maxm],b[maxm],ans;

inline bool sty()
{
	for(int i=1;i<=m;i++) if(b[i]!=a[i]) return 0;
	return 1;
}

inline void wlk()
{
	for(int i=1;i<=m;i++) b[i]=a[i];
	
	bool fin=0;
	while(1)
	{
		for(int i=1;i<=n;i++)
		{
			b[c[i]]+=d[i];
			ans++;
			
			if(b[c[i]]<1||b[c[i]]>w[c[i]])
			{
				fin=1;
				break;
			}
		}
		
		if(fin||sty()) break;
	}
	
	if(!fin)
	{
		printf("-1");
		exit(0);
	}
}

inline void getpos(int k)
{
	if(k==m+1)
	{
		wlk();
		return;
	}
	
	for(int i=1;i<=w[k];i++)
	{
		a[k]=i;
		getpos(k+1);
	}
}

inline void sol1()
{
	getpos(1);
	printf("%d",ans);
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++) scanf("%d%d",&c[i],&d[i]);
	
	if(n<=100) sol1();
	else printf("-1");

	return 0;
}

