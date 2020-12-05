#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e5+5,KS=15;
struct step
{
	int esh;
	int id;
}A[N],B[N],C[N];
int w[KS],c[N],d[N];
int go[N],sta[N],co[N],cango[N];
int n,k,wmax,all0;
long long ans;
bool flag;
void work()
{
	for (int i=1;i<=k;i++) sta[i]=co[i];
//	for (int i=1;i<=k;i++) cout<<sta[i]<<" ";
//	cout<<endl;
	bool ex=false;
	while (1)
	{
		for (int j=1;j<=n;j++)
		{
			sta[c[j]]+=d[j];
			ans++;
			if (sta[c[j]]<=0||sta[c[j]]>w[c[j]]) {ex=true;break;}
		}
//		for (int i=1;i<=k;i++) cout<<sta[i]<<" ";
//		cout<<endl;
		if (ex) break;
		if (all0) {flag=false;break;}
	}
//	cout<<ans<<endl;
}
void dfs(int dep)
{
	if (dep==k+1) {work();return;}
	for (co[dep]=1;co[dep]<=w[dep];co[dep]++) dfs(dep+1);
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++) scanf("%d",&w[i]),wmax=max(wmax,w[i]);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",&c[i],&d[i]);
		go[c[i]]+=d[i];
	}
	all0=true;
	for (int i=1;i<=k;i++)
		if (go[i]!=0) all0=false;
	if (n<=100&&k<=5&&wmax<=10)
	{
		flag=true;
		dfs(1);
		printf("%lld\n",(flag?ans:-1));
	}
	
	else if (k==1)
	{
		for (int i=1;i<=n;i++) A[i].esh=A[i-1].esh+d[i],A[i].id=i;
		for (int i=1;i<=n;i++) B[i].esh=max(0,A[i].esh),B[i].id=i;
		for (int i=1;i<=n;i++) C[i].esh=min(0,A[i].esh),C[i].id=i;
		int pos=0,max=0,minx=1e9;
		for (int i=1;i<=w[1];i++)
		{
			if (B[i].esh<=max) continue;
			else cango[B[i].esh]=i,max=B[i].esh;
		}
		for (int i=1;i<=n;i--)
		{
			if (C[i].esh>=minx) continue; 
			else cango[w[1]+1-C[i].esh]=min(cango[w[1]+1-C[i].esh],i),minx=C[i].esh;
		}
		for (int i=1;i<=w[1];i++)
		{
			while (cango[i]==0) i+=A[n].esh,ans+=n;
			ans+=cango[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

