#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define INF 1000000000
#define LINF 1000000000000000000
#define N 1050000
using namespace std;
int z[N],od[N],suf_od[N],sum[30];
ll ans;
string s;
char buf[N];
int brute(int x,int st)
{
	int i;
	for(i=0;i+max(st,x)<s.size();i++)
	{
		if(s[st+i]!=s[x+i])
		{
			return i;
		}
	}
	return i;
}
void z_func()
{
	int i,l,r,tz;
	memset(z,0,sizeof(z));
	z[0]=s.size();
	l=r=0;
	for(i=1;i<s.size();i++)
	{
		if(i>=r)
		{
			z[i]=brute(i,0);
			l=i;
			r=i+z[i];
		}
		else
		{
			tz=z[i-l];
			if(tz!=r-i)
			{
				z[i]=min(tz,r-i);
			}
			else
			{
				z[i]=tz+brute(r,r-i);
				r=i+z[i];
				l=i;
			}
		}
	}
	return;
}
void get_odd()
{
	int i,mask=0,t=0;
	for(i=0;i<s.size();i++)
	{
		if(mask&(1<<(int)(s[i]-'a')))
		{
			t--;
		}
		else
		{
			t++;
		}
		mask^=(1<<(int)(s[i]-'a'));
		od[i]=t;
	}
	t=0;
	mask=0;
	for(i=s.size()-1;i>=0;i--)
	{
		if(mask&(1<<(int)(s[i]-'a')))
		{
			t--;
		}
		else
		{
			t++;
		}
		mask^=(1<<(int)(s[i]-'a'));
		suf_od[i]=t;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,i,j,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",&buf);
		s=buf;
		z_func();
		get_odd();
		memset(sum,0,sizeof(sum));
		ans=0;
		for(i=od[0];i<=26;i++)
		{
			sum[i]++;
		}
		for(i=2;i<s.size();i++)//|A+B|
		{
			for(j=0;j+i<s.size();)
			{
				if(z[j]<i)
				{
					break;
				}
				j+=i;
				k=suf_od[j];
				ans+=sum[k];
			}
			for(j=od[i-1];j<=26;j++)
			{
				sum[j]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1. file name
2. long long & int
3. array size
4. special cases
5. border
6. initialization
7. max&min value
8. big const->TLE
9. strange errors (/0,int->long long,iterator,unsigned long long...)
10. typo(n&m,=&-...)
*/
