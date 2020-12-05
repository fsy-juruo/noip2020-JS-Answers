#include<bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &num)
{
	num=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		num=num*10+c-48;
		c=getchar();
	}
	num*=f;
}
const int maxn = 1e6+7;
int n,k,w[12],c[maxn],d[maxn],p=1,mov[12],ans,nw[12];
int tp[12];
void work()
{
	int lim = 0x7fffffff;
	int res=0;
	for(int i=1;i<=k;++i)
		nw[i]=tp[i];
	/*for(int i=1;i<=k;++i)
	{
		if(mov[i]==0)
			continue;
		if(mov[i]>0)
		{
			lim=min(lim,abs(w[i]-tp[i]-1)/abs(mov[i]));
		}
		else
		{
			lim=min(lim,abs(tp[i]-1)/abs(mov[i]));
		}
	}
//	lim>>=1;
//	lim=0;
//	lim-=n;
	lim=max(lim,0ll);
	res+=lim*n;
	for(int i=1;i<=k;++i)
	{
		int r=nw[i]+mov[i]*lim;
		if(r>w[i]||r<1)
			puts("adasdasdasdasd");
		nw[i]+=mov[i]*lim;
	}
	
	/*if(!chk())
	{
		ans+=res;
		
	}*/
	int i=1;
	while(1)
	{
		if(i>n)
			i=1;
		nw[c[i]]+=d[i];
		++res;
		if(nw[c[i]]>w[c[i]]||nw[c[i]]<1)
			break;
		++i;
	}
//	cout<<tp[1]<<" "<<tp[2]<<" "<<res<<endl;
	ans+=res;
}
void dfs(int x)
{
	if(x==k+1)
	{
//		cout<<"asdasdas"<<endl;
		work();
		return;
	}
	for(int i=1;i<=w[x];++i)
	{
		tp[x]=i;
		dfs(x+1);
	}
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=k;++i)
		read(w[i]),p*=w[i];
	for(int i=1;i<=n;++i)
		read(c[i]),read(d[i]),mov[c[i]]+=d[i];
	bool tp=1;
	for(int i=1;i<=k;++i)
		if(w[i]!=0)
			tp=0;
	if(tp||n>=1e5)
	{
		puts("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
//	cout<<mov[1]<<"az "<<mov[2]<<endl;
	dfs(1);
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
