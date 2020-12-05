#include<bits/stdc++.h>
using namespace std;
long long n,k,s,mm,mn=INT_MAX,ans,w[15],c[15],d[15];
void read(long long &s)
{
	s=0;
	long long f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		s=(s<<3)+(s<<1)+(c-48);
		c=getchar();
	}
	s=s*f;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);
	read(k);
	for(long long i=1;i<=k;i++)read(w[i]);
	for(long long i=1;i<=n;i++)
	{
		read(c[i]);
		read(d[i]);
	}
	if(k==1)
	{
		for(long long i=1;i<=n;i++)
		{
			s+=d[i];
			mm=max(mm,s);
			mn=min(mn,s);
		}
		if(s==0&&abs(mm)+abs(mn)<=w[1])
		{
			cout<<-1<<endl;
			return 0;
		}
		for(long long i=1;i<=w[1];i++)
		{
			long long x=i;
			if(s>0)
			{
				long long o=w[1]-mm-x;
				long long e=o/s;
				ans+=e*n;
				x+=s*e;
			}
			else
			{
				long long o=x+mn;
				long long e=o/s;
				ans+=e*n;
				x-=s*e;
			}
			while(1)
			{
				for(long long j=1;j<=n;j++)
				{
					x+=d[j];
					ans++;
					if(x<=0||x>w[1])break;
				}
				if(x<=0||x>w[1])break;
			}
		}
		cout<<ans%(long long)(1e9+7)<<endl;
	}
	return 0;
}
