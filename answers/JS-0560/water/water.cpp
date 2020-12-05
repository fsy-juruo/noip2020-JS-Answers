#include<cstdio>
#define ll long long
using namespace std;
int n,m,i,j,k,x,y,z,d[100008],p[1000008],t[100008],fc[100008],tot,w[100008],qu[100008],Q,l,r;
long long fz[100008],fm[100008];
long long gcd(long long a,long long b)
{
	while(a^=b^=a^=b%=a);return b;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);fc[i]=tot+1;
		if(t[i]==0)qu[++Q]=i;
		for(j=1;j<=t[i];j++)
		{
		  scanf("%d",&p[++tot]);
		  d[p[tot]]++;
		}
		fm[i]=1;
	}
	for(i=1;i<=m;i++)w[++r]=i,fz[i]=1;
	while(l<r)
	{
		l++;
		for(i=fc[w[l]];i<=fc[w[l]]+t[w[l]]-1;i++)
		{
			fz[p[i]]=fm[w[l]]*t[w[l]]*fz[p[i]]+fm[p[i]]*fz[w[l]];
			fm[p[i]]=(ll)fm[p[i]]*t[w[l]]*fm[w[l]];
			long long c=gcd(fm[p[i]],fz[p[i]]);
			fm[p[i]]/=c;fz[p[i]]/=c;
			d[p[i]]--;if(d[p[i]]==0)w[++r]=p[i];
		}
	}
	for(i=1;i<=Q;i++)
	{
		printf("%lld %lld\n",fz[qu[i]],fm[qu[i]]);
	}
	return 0;
}
