#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;	
int n,k;
long long ans;
int w[11];
int now[11];
int c[500010],d[500010],jzx2[11],maxt[11],mint[11];
void work(int pos)
{
	for(int i=1;i<=w[pos];i++)
	{
		now[pos]=i;
		if(pos==k)
		{
			int tmp[11];
			for(int j=1;j<=k;j++)
			{
				tmp[j]=now[j];
			}
			while(1)
			{
				for(int j=1;j<=n;j++)
				{
					tmp[c[j]]+=d[j];
					ans++;
					if(tmp[c[j]]>w[c[j]]||tmp[c[j]]<1)
					{
						goto A;
					}				
				}
			}
			A:
			//cout<<tmp[1]<<" "<<tmp[2]<<" "<<ans<<endl;
			continue;
		}
		else
		{
			work(pos+1);
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
	for(int i=1;i<=n;i++)
	{
		jzx2[c[i]]+=d[i];
		maxt[c[i]]=max(maxt[c[i]],jzx2[c[i]]);
		mint[c[i]]=min(mint[c[i]],jzx2[c[i]]);
	}
	for(int i=1;i<11;i++)
	{
		if(jzx2[i]!=0||maxt[i]-mint[i]>=w[i])
		{
			goto A;
		}
	}
	cout<<-1;
	return 0;
	A:
	if(n>10000&&k==1)
	{
		int jzx=0,bst=0,sst=0,jyh[100001];
		for(int i=1;i<=n;i++)
		{
			jzx+=d[i];
			bst=max(bst,jzx);
			sst=min(bst,jzx);
		}
		for(int i=1;i<=w[1];i++)
		{
			jyh[i]=0;
		}
		for(int i=1;i<=w[1];i++)
		{
			int dd=i;
			B:
			if(dd+bst>w[1]||dd+sst<1)
			{
				if(jyh[dd])
				{
					ans+=jyh[dd];
					goto C;
				}
				while(1)
				{
					for(int j=1;j<=n;j++)
					{
						dd+=d[j];
						ans++;
						jyh[i]++;
						if(dd>w[1]||dd<1)
						{
							goto C;
						}				
					}
				}				
			}
			else
			{
				dd+=jzx;
				ans+=n;
				goto B;
			}
			C:
			continue;
		}
	}
	else
	{
		work(1);		
	}
	cout<<ans;
}
//Â·ÉÏ¼ÇÂ¼max? 
