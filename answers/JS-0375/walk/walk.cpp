#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
long long ans=0;
bool flag;
int n,k,a[105],a1[105],w[105],c[500005],d[500005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&w[i]);
		a[i]=1;
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&d[i]);
	do{
		flag=false;
		for(int i=1;i<=k;i++)
			a1[i]=a[i];
		while(!flag)
		{
			for(int i=1;i<=n;i++)
			{
				a1[c[i]]+=d[i];
				ans++;
				if(a1[c[i]]<1||a1[c[i]]>w[c[i]])
				{
					flag=true;
					break;
				}
			}
		}
		a[k]+=1;
		for(int i=k;i>=1;i--)
		{
			if(a[i]>w[i])
			{
				a[i]=1;
				a[i-1]+=1;
			}
			else
				break;
		}
	}while(a[0]==0);
	printf("%lld\n",ans%INF);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
