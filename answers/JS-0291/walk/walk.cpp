#include <bits/stdc++.h>
using namespace std;
long long w[15];
const int mod=1000000007;
long long c[500005],d[500005];
long long a[15],t[15];
long long l[100005],r[100005];
long long read1()
{
	char cc=getchar();
	while(!(cc>=48&&cc<=57))
	{
		if(cc=='-')
		{
			break;
		}
		cc=getchar();
	}
	bool f=false;
	long long s=0;
	if(cc=='-')
	{
		f=true;
	}
	else
	{
		s=cc-48;
	}
	while(1)
	{
		cc=getchar();
		if(cc>=48&&cc<=57)
		{
			s=s*10+cc-48;
		}
		else
		{
			break;
		}
	}
	if(f==true)
	{
		s=-s;
	}
	return s;
}
long long ans,n,k;
void dfs(long long n1)
{
	if(n1==k+1)
	{
		for(long long i=1;i<=k;i++)
		{
			t[i]=a[i];
		}
		bool f=false;
		while(1)
		{
			for(long long i=1;i<=n;i++)
			{
				t[c[i]]+=d[i];
				ans++;
				if(ans>=mod)
				{
					ans-=mod;
				}
				if(t[c[i]]>w[c[i]]||t[c[i]]<1)
				{
					f=true;
					break;
				}
			}
			if(f==true)
			{
				break;
			}
			bool ff=false;
			for(long long i=1;i<=k;i++)
			{
				if(a[i]!=t[i])
				{
					ff=true;
					break;
				}
			}
			if(ff==false)
			{
				puts("-1");
				exit(0);
			}
		}
	}
	else
	{
		for(long long i=1;i<=w[n1];i++)
		{
			a[n1]=i;
			dfs(n1+1);
		}
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=k;i++)
	{
		w[i]=read1();
	}
	for(long long i=1;i<=n;i++)
	{
		c[i]=read1();
		d[i]=read1();
	}
	if(k==1)
	{
		long long tot=0,maxl=0,maxr=0,cur=0;
		for(long long i=1;i<=n;i++)
		{
			cur+=d[i];
			maxl=min(maxl,cur);
			maxr=max(maxr,cur);
			if(cur>0)
			{
				if(r[cur]==0)
				{
					r[cur]=i;
				}
			}
			else if(cur<0)
			{
				if(l[-cur]==0)
				{
					l[-cur]=i;
				}
			}
		}
		maxl=-maxl;
		maxr=w[1]-maxr+1;
		tot=cur;
		for(long long i=1;i<=w[1];i++)
		{
			long long h=i;
			if(i<=maxl)
			{
				ans+=l[i];
				ans%=mod;
			}
			else if(i>=maxr)
			{
				ans+=r[w[1]-i+1];
				ans%=mod;
			}
			else
			{
				if(tot<0)
				{
					ans+=((h-maxl)/abs(tot)*n);
					ans%=mod;
					h=h-(h-maxl)/abs(tot)*abs(tot);
					if(h>maxl)
					{
						h-=abs(tot);
						ans+=n;
						ans%=mod;
					}
					ans+=l[h];
					ans%=mod;
				}
				else if(tot==0)
				{
					puts("-1");
					return 0;
				}
				else
				{
					ans+=((maxr-h)/abs(tot)*n);
					ans%=mod;
					h=h+(maxr-h)/abs(tot)*abs(tot);
					if(h<maxr)
					{
						h+=abs(tot);
						ans+=n;
						ans%=mod;
					}
					ans+=r[w[1]-h+1];
					ans%=mod;
				}
			}
		}
		cout<<ans<<endl;
	}
	else
	{
    	dfs(1);
    	cout<<ans<<endl;
    }
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

3 1
5
1 1
1 1
1 -1

*/
//40 points
