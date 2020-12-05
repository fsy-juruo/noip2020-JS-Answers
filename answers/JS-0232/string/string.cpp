#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
inline void read(int &num)
{
	num=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		num=num*10+c-48;
		c=getchar();
	}
	num*=f;
}
const int maxn = 2e6+7;
int T,n,a[maxn],can[maxn],b[maxn],frcnt[maxn],frzmcn[28],bacnt[maxn],bazmcn[28];
ll ans;
char s[maxn];
bool chk(int l,int p)
{
	if(l==p)
		return true;
	for(int i=p-l+1,ct=1;i<=p;++i,++ct)
		if(a[ct]!=a[i])
			return false;
	return true;
}
/*void sub()
{
	
}*/
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--)
	{
		ans = 0;
		cin>>(s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)
			a[i]=s[i]-'a'+1,can[i]=0,frcnt[i]=0,bacnt[i]=0;
		bool tp=1;
		for(int i=2;i<=n;++i)
			if(a[i]!=a[i-1])
				tp=0;
		for(int k=0;k<=26;++k)
			frzmcn[k]=0,bazmcn[k]=0;
		/*if(tp&&n>1000)
		{
			sub();
			continue;
		}*/
		
		for(int i=1;i<=n;++i)
		{
			frzmcn[a[i]]++;
			for(int j=1;j<=26;++j)
				if(frzmcn[j]&1)
					++frcnt[i];
		}
		for(int i=n;i>=1;--i)
		{
			bazmcn[a[i]]++;
			for(int j=1;j<=26;++j)
				if(bazmcn[j]&1)
					++bacnt[i];
		}
		for(int i=1;i<n;++i)
		{
			int lm=frcnt[i];
			for(int l=1;i+l<n;++l)
			{
				int j=i+l;
				int nw=j;
				while(nw<n&&chk(j,nw))
				{
					if(bacnt[nw+1]>=lm)
						++ans;
					nw+=j;
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
kkkkkkkkkkkkkkkkkkkk

156
*/
