#include<bits/stdc++.h>
using namespace std;
int rd[100001]={0},cd[100001],n,m,fz[100001],fm[100001],h[100001],cnt;
struct Edge
{
	int nxt,to;
};
Edge d[500001];
void adde(int a,int b)
{
	cnt++;
	d[cnt].nxt=h[b];
	d[cnt].to=a;
	h[b]=cnt;
	rd[b]++;
}
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int lcm(int a,int b)
{
	int gc=gcd(a,b);
	return a/gc*b;
}
void addf(int a,int b)
{
	if(fz[b]==0)
	{
		fz[b]=fz[a],fm[b]=fm[a];
		return;
	}
	int fza=fz[a],fzb=fz[b],fma=fm[a],fmb=fm[b];
	int f=lcm(fma,fmb);
	fza*=(f/fma),fzb*=(f/fmb);
	fzb+=fza;
	fmb=f;
	int dd=gcd(fmb,fzb);
	fmb/=dd,fzb/=dd;
	fm[b]=fmb,fz[b]=fzb;
}
void dfs(int x)
{
	if(fz[x]!=0)return;
	for(int i=h[x];i;i=d[i].nxt)
	{
		int j=d[i].to;
		int s=cd[j];
		dfs(j);
		if(s!=0)fm[j]*=s;
		addf(j,x);
		if(s!=0)fm[j]/=s;
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cd[i];
		for(int j=1;j<=cd[i];j++)
		{
			int r;
			cin>>r;
			adde(i,r);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==0)
		{
			fm[i]=1,fz[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(cd[i]==0)
		{
			dfs(i);
			int dd=gcd(fz[i],fm[i]);
			cout<<fz[i]/dd<<' '<<fm[i]/dd<<endl;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

