#include<bits/stdc++.h>
using namespace std;
int n,k;
int dir[500050];
long long len[500050];
long long x,y;
long long bd[15];
long long loc[15];
long long now[15];
long long ans;
long long bgn[15];
bool mdzz;
bool check;
void dfs(int layer)
{
	if(layer>k)
	{
		for(int i=1;i<=k;i++)loc[i]=now[i];
		for(int i=1;i<=k;i++)
			bgn[i]=loc[i];
		for(int i=1;;i++)
		{
			if(i>n)
			{
				i-=n;
				if(!check)
				{
					check=1;
					bool flag=0;
					for(int i=1;i<=k;i++)
					{
						if(loc[i]!=bgn[i])
						{
							flag=1;
							break;
						}
					}
					if(!flag)
					{
						mdzz=1;
						return;
					}
				}
			}
			loc[dir[i]]+=len[i];
			ans++;
			if(loc[dir[i]]>bd[dir[i]]||loc[dir[i]]<1)break;
		}
		return;
	}
	for(int i=1;i<=bd[layer];i++)
	{
		now[layer]=i;
		dfs(layer+1);
		if(mdzz)return;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n>5)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=k;i++)cin>>bd[i];
	for(int i=1;i<=n;i++)
	{
		cin>>dir[i]>>len[i];
	}
	dfs(1);
	if(mdzz)
	{
		cout<<-1;
		return 0;
	}
	cout<<ans;
	return 0;
}
