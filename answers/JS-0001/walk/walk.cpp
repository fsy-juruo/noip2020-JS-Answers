#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
const int p=1e9+7;
typedef long long ll;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9' || ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,k;
ll ans=0,m;
int w[15],qd[15],st[15],znb[maxn],c[maxn],d[maxn];
int alr[maxn][15];
bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(znb[i]<=0 || znb[i]>w[i]) return 0;
	}
	return 1;
}
void zou()
{
	memcpy(znb,st,sizeof(st));
	ll j=0;
	//for(int i=1;i<=k;i++) znb[i]=st[i]+alr[j][i];
	while(check() && j<n)
	{
		j++;
		for(int i=1;i<=k;i++) znb[i]=st[i]+alr[j][i];
		if(j==n)
		{
			for(int i=1;i<=k;i++) st[i]=znb[i];
			m+=n;
			j=0;
		}
		//printf("%d %d %d %d %d\n",st[1],st[2],znb[1],znb[2],check);
	}
	m=(m+j)%p;
}
void scqd(int x)
{
	if(x==k+1)
	{
		//cout<<endl;
		//for(int i=1;i<=k;i++) printf("%d ",qd[i]);
		//printf("\n");
		m=0;memcpy(st,qd,sizeof(qd));
		zou();
		//cout<<m<<endl<<endl;
		ans=(ans+m)%p;
		return;
	}
	for(int i=1;i<=w[x];i++)
	{
		qd[x]=i;
		scqd(x+1);
	}
}
int main()
{
	//double st,ed;
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	st=clock();
	n=read();k=read();
	for(int i=1;i<=k;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++) 
	{
		c[i]=read();d[i]=read();
		for(int j=1;j<=k;j++) alr[i][j]=alr[i-1][j];
		alr[i][c[i]]+=d[i];
	}
	scqd(1);
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		  cout<<alr[i][j]<<' ';
		cout<<endl<<i<<endl;
	}*/
	printf("%lld\n",ans);
	//ed=clock();
	//printf("%.0lfms",ed-st);
	return 0;
}
