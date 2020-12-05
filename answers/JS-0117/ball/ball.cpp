#include<bits/stdc++.h>
using namespace std;
int s[55][405],k,from[10005],to[10005],top[55],atop,n,m;
void ft(int a,int b)
{
	while((s[a][top[a]]==s[b][top[b]]||top[b]==0)&&top[b]<m)
	{
		s[b][++top[b]]=s[a][top[a]];
		s[a][top[a]]=0;
		top[a]--;
		k++;
		from[++atop]=a;
		to[atop]=b;
	}
}
bool pdo(int x)
{
	if(top[x]==0)
		return 0;
	for(int i=1;i<=n+1;++i)
	{
		if(s[x][top[x]]==s[i][top[i]]&&top[i]!=m&&i!=x||top[i]==0&&i!=x)
			return 1;
	}
	return 0;
}
bool pdf()
{
	for(int i=1;i<=n+1;++i)
	{
		for(int j=2;j<=m;++j)
		{
			if(s[i][j]!=s[i][j-1])
				return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		top[i]=m;
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&s[i][j]);
		}
	}
	while(!pdf())
	{
		while(pdo(1))
		{
			ft(1,3);
			ft(1,2);
		}
		if(pdf())
			break;
		while(pdo(2))
		{
			ft(2,3);
			ft(2,1);
		}
	}
	printf("%d\n",k);
	for(int i=1;i<=k;++i)
	{
		printf("%d %d\n",from[i],to[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
