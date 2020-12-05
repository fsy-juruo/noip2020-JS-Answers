#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int inf=0x3f3f3f3f;
int n,m,d[maxn],pos[maxn];
long long fm[maxn],fz[maxn];
vector<int> v[maxn];
long long mygcd(long long x,long long y)
{
	if(x==0||y==0)
		return 1;
	if(x==y)
		return x;
	if(x<y)
		swap(x,y);
	int tmp=y;
	y=x-y;
	x=tmp;
	return mygcd(x,y);
}
void dfs(int x)
{
	int gs=v[x].size();
	if(gs==0)
		return;
	for(int i=0;i<=v[x].size()-1;i++)
	{
		long long y=v[x][i];
		long long tfm=fm[x]*gs,tfz=fz[x];
		long long ggcd=mygcd(tfm,tfz);
		tfm=tfm/ggcd;
		tfz=tfz/ggcd;
		if(pos[y]==0||fz[y]==0)
		{
			fz[y]=tfz;
			fm[y]=tfm;
			dfs(y);
			continue;
		}
		long long lcm=tfm*fm[y]/mygcd(tfm,fm[y]);
		long long bs=lcm/tfm;
		tfz*=bs;
		bs=lcm/fm[y];
		fz[y]*=bs;
		long long xx=tfz+fz[y];
		ggcd=mygcd(lcm,xx);
		lcm/=ggcd;
		xx/=ggcd;
		fm[y]=lcm;
		fz[y]=xx;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i]==0)
			pos[i]=1;
		for(int j=1;j<=d[i];j++)
		{
			int x;
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=m;i++)
		fm[i]=fz[i]=1;
	for(int i=1;i<=m;i++)
		dfs(i);
	for(int i=1;i<=n;i++)
	{
		if(pos[i]==1)
		{
			int ggccd=mygcd(fz[i],fm[i]);
			fz[i]/=ggccd;
			fm[i]/=ggccd;
			printf("%lld %lld\n",fz[i],fm[i]);
		}
	}
	return 0;
}
/*
in
5 1
3 2 3 5
2 4 5
2 5 4
0
0
out
1 3
2 3
*/
