#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
bool flag;
ll n,k,w[11],d[11][500005],ans,sum;
struct step
{
	ll dim,s;
}a[500005];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++)
	{
		a[i].dim=read(),a[i].s=read();
		d[a[i].dim][i]+=a[i].s;
		for(int j=1;j<=k;j++)
		{
			d[j][i]+=d[j][i-1];
			if(d[j][i]>w[j]) flag=1;
		}
	}
	for(int i=1;i<=k;i++) if(d[i][n]) flag=1;
	if(!flag){printf("-1");return 0;}
	if(k==1)
	{
		ll f[100005];
		memset(f,0,sizeof(f));
		for(int i=1;i<=w[1];i++)
		{
			ll p=i;
			ans=0;
			while(p&&p<=w[1])
			{
				for(int j=1;j<=n;j++)
				{
					p=p+a[j].s;
					ans++;
					if(f[p])
					{
						ans+=f[p];
						p=0;
						break;
					}
					if(p==0||p>w[1]) break;
				}
			}
			f[i]=ans;
			sum+=f[i];
		}
	}
	else if(k==2)
	{
		for(int i=1;i<=w[1];i++)
		{
			for(int j=1;j<=w[2];j++)
			{
				ll p1=i,p2=j;
				ans=0;
				while(p1&&p2&&p1<=w[1]&&p2<=w[2])
				{
					for(int k=1;k<=n;k++)
					{
						if(a[k].dim==1) p1+=a[k].s;
						else p2+=a[k].s;
						ans++;
						if(p1==0||p2==0||p1>w[1]||p2>w[2]) break;
					}
				}
				sum+=ans;
			}
		}
	}
	else if(k==3)
	{
		for(int i=1;i<=w[1];i++)
		{
			for(int j=1;j<=w[2];j++)
			{
				for(int k=1;k<=w[3];k++)
				{
					ll p1=i,p2=j,p3=k;
					ans=0;
					while(p1&&p2&&p3&&p1<=w[1]&&p2<=w[2]&&p3<=w[3])
					{
						for(int q=1;q<=n;q++)
						{
							if(a[q].dim==1) p1+=a[q].s;
							else if(a[q].dim==2) p2+=a[q].s;
							else p3+=a[q].s;
							ans++;
							if(p1==0||p2==0||p3==0||p1>w[1]||p2>w[2]||p3>w[3]) break;
						}
					}
					sum+=ans;
				}
			}
		}
	}
	else if(k==5)
	{
		for(int i=1;i<=w[1];i++)
		{
			for(int j=1;j<=w[2];j++)
			{
				for(int k=1;k<=w[3];k++) for(int u=1;u<=w[4];u++) for(int v=1;v<=w[5];v++)
				{
					ll p1=i,p2=j,p3=k,p4=u,p5=v;
					ans=0;
					while(p1&&p2&&p3&&p4&&p5&&p1<=w[1]&&p2<=w[2]&&p3<=w[3]&&p4<=w[4]&&p5<=w[5])
					{
						for(int q=1;q<=n;q++)
						{
							if(a[q].dim==1) p1+=a[q].s;
							else if(a[q].dim==2) p2+=a[q].s;
							else if(a[q].dim==3) p3+=a[q].s;
							else if(a[q].dim==4) p4+=a[q].s;
							else p5+=a[q].s;
							ans++;
							if(p1==0||p2==0||p3==0||p4==0||p5==0||p4>w[4]||p5>w[5]||p1>w[1]||p2>w[2]||p3>w[3]) break;
						}
					}
					sum+=ans;
				}
			}
		}
	}
	else if(k==4)
	{
		for(int i=1;i<=w[1];i++)
		{
			for(int j=1;j<=w[2];j++)
			{
				for(int k=1;k<=w[3];k++) for(int u=1;u<=w[4];u++)
				{
					ll p1=i,p2=j,p3=k,p4=u;
					ans=0;
					while(p1&&p2&&p3&&p4&&p1<=w[1]&&p2<=w[2]&&p3<=w[3]&&p4<=w[4])
					{
						for(int q=1;q<=n;q++)
						{
							if(a[q].dim==1) p1+=a[q].s;
							else if(a[q].dim==2) p2+=a[q].s;
							else if(a[q].dim==3) p3+=a[q].s;
							else if(a[q].dim==4) p4+=a[q].s;
							ans++;
							if(p1==0||p2==0||p3==0||p4==0||p4>w[4]||p1>w[1]||p2>w[2]||p3>w[3]) break;
						}
					}
					sum+=ans;
				}
			}
		}
	}
	printf("%lld",sum%mod);
	return 0;
}
