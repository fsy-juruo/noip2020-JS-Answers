#include<bits/stdc++.h>
using namespace std;
int cnt,rudu[100005],fi[100005],ne[500005],sto[500005],n,m,jieshou[15],chudu[100005];
struct fenshu
{
	unsigned long long fenzi;
	unsigned long long fenmu;
}chuli[100005];
unsigned long long gcdd(unsigned long long a,unsigned long long b)
{
	if(b==0)
		return a;
	if(a==0)
		return b;
	return gcdd(b,a%b);
}
fenshu jia(fenshu a,fenshu b)
{
	fenshu daan;
	daan.fenzi=a.fenzi*b.fenmu+b.fenzi*a.fenmu;
	daan.fenmu=a.fenmu*b.fenmu;
	unsigned long long gcddd=gcdd(daan.fenzi,daan.fenmu);
	daan.fenzi/=gcddd,daan.fenmu/=gcddd;
	return daan;
}
fenshu yuefen(fenshu a)
{
	unsigned long long gcddd=gcdd(a.fenzi,a.fenmu);
	a.fenzi/=gcddd,a.fenmu/=gcddd;
	return a;
}
void ae(int a,int b)
{
	sto[++cnt]=b;
	ne[cnt]=fi[a];
	fi[a]=cnt;
}
fenshu makefenshu(unsigned long long a,unsigned long long b)
{
	fenshu ans;
	ans.fenzi=a,ans.fenmu=b;
	return ans;
}
void paishui(int u,fenshu liang)
{
	if(chudu[u]==0)
		return;
	fenshu tmp;
	tmp.fenzi=liang.fenzi;
	tmp.fenmu=liang.fenmu*chudu[u];
	tmp=yuefen(tmp);
	for(int i=fi[u];i;i=ne[i])
	{
		chuli[sto[i]]=jia(tmp,chuli[sto[i]]);
		paishui(sto[i],tmp);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int d;
		scanf("%d",&d);
		chudu[i]=d;
		for(int j=1;j<=d;++j)
		{
			int b;
			scanf("%d",&b);
			ae(i,b);
			++rudu[b];
		}
		chuli[i].fenzi=0,chuli[i].fenmu=1;
	}
	cnt=0;
	for(int i=1;i<=n;++i)
		if(rudu[i]==0)
			jieshou[++cnt]=i;
	for(int i=1;i<=m;++i)
	{
		chuli[jieshou[i]].fenmu=chuli[jieshou[i]].fenzi=1;
		paishui(i,makefenshu(1,1));
	}
	for(int i=1;i<=n;++i)
	{
		if(chudu[i]==0)
			printf("%llu %llu\n",chuli[i].fenzi,chuli[i].fenmu);
	}
	return 0;
}
