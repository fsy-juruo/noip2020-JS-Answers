#include<bits/stdc++.h>
using namespace std;
int n,k,bs,ans;
int wd[20],d[20],wz[20],way1[5*100010],way2[5*100010],wzc[20],wzcc[20];
bool flag;
int js()
{
	int cs=INT_MAX;
	for(int i=1;i<=k;i++)
		wzc[i]=wz[i];
	for(int i=1;i<=k;i++)
	{	
		for(int j=1;j<=k;j++)
			wzcc[j]=wzc[j];
		for(int j=1;j<=n;j++)
		{
			if(way1[j]==i)
			{
				wzcc[i]+=way2[j];
				if(wzcc[i]<1||wzcc[i]>wd[i])
				{
					cs=0;
					break;
				}
			}	
		}
		if(d[i]==0)	
			continue;
		else if(d[i]<0)
		{
			if((1-wzc[i])==0)
			{
				cs=0;
				break;
			}
			else	
				cs=min(cs,(1-wzc[i])/d[i]);
		}	
		else
		{
			if((wd[i]-wzc[i])==0)
			{
				cs=0;
				break;
			}
			else
				cs=min(cs,(wd[i]-wzc[i])/d[i]);
		}
	}	
	if(cs==INT_MAX)
	{
		flag=true;
		return -1;
	}
	for(int i=1;i<=k;i++)
		wzc[i]=wzc[i]+d[i]*cs;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		int v=way1[i];
		wzc[v]+=way2[i];
		if(wzc[v]>=1&&wzc[v]<=wd[v])
			tot++;
		else
		{
			tot++;
			break;
		}
			
	}		
	return bs*cs+tot;
}
void dfs(int u)
{
	if(flag)
		return;
	if(u>k)
		ans+=js();
	for(int i=1;i<=wd[u];i++)
	{
		wz[u]=i;
		dfs(u+1);
	}
		
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&wd[i]);
		int c,e;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c,&e);
		way1[i]=c;
		way2[i]=e;
		d[c]+=e;
	}
	bs=n;
	dfs(1);
	if(flag)
		cout<<"-1"<<endl;
	else
		cout<<ans<<endl;	
	return 0;
}
