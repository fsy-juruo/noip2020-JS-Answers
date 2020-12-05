#include<bits/stdc++.h>
#define M 100005
using namespace std;
struct frac
{
	int fz,fm;
};
long long gcd(long long x,long long y)
{
	if(x<y)swap(x,y);
	return (x%y==0)? y:gcd(x-y,y);
}
int n,m,point[M],rd[M],cd[M];
vector<int> a[100005];
frac p[M];
void add(int u,int fmm)
{
	//cout<<p[u].fm<<" "<<p[u].fz<<" "<<fmm<<endl;
	long long tz,tm;
	tm=(long long)p[u].fm*fmm;
	tz=(long long)p[u].fz*fmm+p[u].fm;
	//long long ggcd=1;
	long long ggcd=gcd(tm,tz);
	tm/=ggcd;
	tz/=ggcd;
	p[u].fm=tm;
	p[u].fz=tz;
	return ;
}
void dfs(int u,int fs)
{
	if(point[u]==2){
		add(u,fs);
	}
	for(int i=1;i<=cd[u];i++)
		dfs(a[u][i],fs*cd[u]);
	return ;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&cd[i]);
		if(cd[i]==0)point[i]=2;
		a[i].push_back(0);
		for(int j=1,pt;j<=cd[i];j++)
		{
			scanf("%d",&pt);
			a[i].push_back(pt);
			rd[a[i][j]]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==0)point[i]=1,p[i].fz=p[i].fm=1;
		else p[i].fz=0,p[i].fm=1;
	}
	for(int i=1;i<=n;i++)
		if(point[i]==1)dfs(i,1);
	for(int i=1;i<=n;i++)
		if(point[i]==2)printf("%d %d\n",p[i].fz,p[i].fm);
	return 0;
}
