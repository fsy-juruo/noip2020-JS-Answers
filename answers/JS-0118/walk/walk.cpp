#include<bits/stdc++.h>
using namespace std;
void read(int &x);
const int MAXN=100007;
const int MOD=1e9+7;
int n,k,w[11];
int c[MAXN],d[MAXN],r[11],rm[11];
long long ans;
int now[11],cg[11];
bool check()
{
	for(int i=1;i<=k;i++)
	{
		if(cg[i]<1||cg[i]>w[i])return 0;
	}
	return 1;
}
void work()
{
	for(int i=1;i<=k;i++)cg[i]=now[i];
	//puts("");
	int nxx=0;
	while(check())
	{
		ans++;
		if(ans>100000007)
		{
			cout<<-1<<endl;
			fclose(stdin);
			fclose(stdout);
			exit(0);
		}
		nxx=(nxx==n)?1:nxx+1;
		cg[c[nxx]]+=d[nxx];
	}
}
void dfs(int st)
{
	if(st==k+1)
	{
		work();return;
	}
	for(int i=1;i<=w[st];i++)
	{
		now[st]=i;
		dfs(st+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	if(n>100000||(n>100&&k==2))
	{
		cout<<-1<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=k;i++)read(w[i]);
	for(int i=1;i<=n;i++)
	{
		read(c[i]);read(d[i]);
	}
	dfs(1);
	cout<<ans%MOD<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	x*=f;
}

