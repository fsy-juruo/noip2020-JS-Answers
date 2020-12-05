#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
int n,k,w[15];
int step[500010][2];
int rct[12][12][12][12][12],lne[100010],p[10];
long long ans;
bool flag;
int stt,sttp[6];
long long dfs1(int p,int s)
{
	if(p<1||p>w[1]) return 0;
	if(s==n+1)
	{
		if(p==stt)
		{
			flag=1;
			return 0;
		}
		s=1;
	}
//	if(lne[p]==0) lne[p]=dfs1(p+step[s][1],s+1)+1;
//	return lne[p];
	return dfs1(p+step[s][1],s+1)+1;
}
bool check()
{
	for(int i=1;i<=k;++i)
	{
		if(p[i]<1||p[i]>w[i]) return 0;
	}
	return 1;
}
long long dfs2(int s)
{
	if(!check()) return 0;
	if(s==n+1)
	{
		s=1;	
	}
//	int t[10];
//	for(int i=1;i<=5;++i) t[i]=p[i];	
//	if(rct[p[1]][p[2]][p[3]][p[4]][p[5]]==0)
//	{
//		p[step[s][0]]+=step[s][1];
//		rct[t[1]][t[2]][t[3]][t[4]][t[5]]=dfs2(s+1)+1;
//		p[step[s][0]]-=step[s][1];
//	}
//	return rct[t[1]][t[2]][t[3]][t[4]][t[5]];
	p[step[s][0]]+=step[s][1];
	return dfs2(s+1)+1;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i) scanf("%d",w+i);
	for(int i=1;i<=5;++i) if(w[i]==0) w[i]=1;
	for(int i=1;i<=n;++i) scanf("%d%d",&step[i][0],&step[i][1]);
	if(k==1)
	{
		for(int i=1;i<=w[1];++i)
		{
			stt=i;
			ans=(ans+dfs1(i,1))%mod;
			if(flag)
			{
				printf("-1\n");
				return 0;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	else if(k<=5&&n<=100)
	{
		int i[6];
		for(i[1]=1;i[1]<=w[1];++i[1])
		{
			for(i[2]=1;i[2]<=w[2];++i[2])
			{
				for(i[3]=1;i[3]<=w[3];++i[3])
				{
					for(i[4]=1;i[4]<=w[4];++i[4])
					{
						for(i[5]=1;i[5]<=w[5];++i[5])
						{
							for(int ttt=1;ttt<=k;++ttt)
							{
								p[ttt]=i[ttt];
								sttp[ttt]=p[ttt];
							}
							ans=(ans+dfs2(1))%mod;							
						}						
					}			
				}				
			}			
		}
		printf("%d\n",ans);		
		return 0;
	}
	printf("-1\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
