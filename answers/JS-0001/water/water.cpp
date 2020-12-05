#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef unsigned long long ull;
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
int n,m,k,s;
int in[maxn],out[maxn];bool vis[maxn];
vector <int> ver[maxn];
//vector <int> rel[maxn];
struct node{
	ull p,q;
}ans[maxn];
void add(int x,ull dep)
{
	//ans[x]/p/ans[x].q+dep/1;
	ull fm=ans[x].q*dep/(__gcd(ans[x].q,dep));
	ull fz=ans[x].p*(fm/ans[x].q)+fm/dep;
	ull d=__gcd(fm,fz);
	ans[x].p=fz/d;ans[x].q=fm/d;
}
void dfs(int x,ull dep)
{
	if(out[x]==0) 
	{
		//rel[x].push_back(dep);
		add(x,dep);
		return;
	}
	for(int i=0;i<ver[x].size();i++)
	{
		int y=ver[x][i];
		dfs(y,(ull)dep*out[x]);
	}
}
int main()
{
	//freopen("water.in","r",stdin);
	//freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			s=read();
			ver[i].push_back(s);
			out[i]++;in[s]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(out[i]==0) ans[i].q=1;
	}
	for(int i=1;i<=m;i++)
	{
		dfs(i,1);
	}
	/*for(int i=1;i<=n;i++)
	{
		cout<<i<<endl;
		for(int j=0;j<rel[i].size();j++) cout<<rel[i][j]<<' ';
		cout<<endl<<"2333"<<ans[i].p<<' '<<ans[i].q;
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		if(out[i]==0)
		{
			printf("%lld %lld\n",ans[i].p,ans[i].q);
		}
	}
	return 0;
}
