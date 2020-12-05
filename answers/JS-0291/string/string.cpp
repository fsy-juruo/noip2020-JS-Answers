#include <bits/stdc++.h>
using namespace std;
int cnt[35];
int g[1200005];
long long c[1200005],n,va;
unsigned long long p[1200005];
unsigned long long f[1200005];
const long long P=13331;
long long lowbit(long long n)
{
	return n&(-n);
}
void add(long long n1)
{
	if(n1==0)
	{
		va++;
		return;
	}
	while(n1<=n)
	{
		c[n1]++;
		n1+=lowbit(n1);
	}
}
long long ask(long long n1)
{
	long long s=va;
	while(n1>0)
	{
		s+=c[n1];
		n1-=lowbit(n1);
	}
	return s;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long tt;
	cin>>tt;
	string s;
	for(long long t=1;t<=tt;t++)
	{
    	cin>>s;
		n=s.size();
		long long cnta=0;
		long long ans=0;
		va=0;
		memset(cnt,0,sizeof(cnt));
		g[n]=0;
		for(long long i=n-1;i>=0;i--)
		{
			cnt[s[i]-'a']++;
			if(cnt[s[i]-'a']%2==1)
			{
				g[i]=g[i+1]+1;
			}
			else
			{
				g[i]=g[i+1]-1;
			}
		}
		p[0]=1;
		for(long long i=1;i<=n;i++)
		{
			f[i]=f[i-1]*P+s[i-1]-'a';
			p[i]=p[i-1]*P;
		}
		memset(cnt,0,sizeof(cnt));
		memset(c,0,sizeof(c));
		for(long long i=0;i<n;i++)
		{
			if(i!=0)
			{
				cnt[s[i-1]-'a']++;
				if(cnt[s[i-1]-'a']%2==1)
				{
					cnta++;
				}
				else
				{
					cnta--;
				}
				add(cnta);
			}
			long long q=0;
			while(1)
			{
				if(q==n)
				{
					break;
				}
				if(q!=0)
				{
					ans+=ask(g[q]);
				}
	            if(s.size()-q-1<i)
	            {
	            	break;
				}
				if(f[q+i+1]-f[q]*(p[i+1])!=f[i+1])
				{
			        break;
				}
				q+=(i+1);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab

377943
322610
491244
364771
344864

648723692
674229434
914772932
610408292
619614553

*/
//84 points
