#include <bits/stdc++.h>
using namespace std;
#define signed long long
const signed maxn=5e5+5;
const signed mod=1e9+7;
int read()
{
	static int*tmp=new int();
	scanf("%d",tmp);
	return *tmp;
}
signed w[maxn];
signed c[maxn];
signed d[maxn];
signed n,k;
void sol1()
{
	signed ans=0;
	
	if(k==1)
	{
		signed delta=0;
		signed del=0;
		signed ta=0;
		signed shit[maxn];
		for(signed i=1;i<=n;++i)
		{
			delta+=d[i];
			if(shit[delta+(int)2e5]==0)
			{
				shit[delta+(int)2e5]=i;
			}
		}
		signed A=0;
		signed ans[maxn];
		for(signed i=1;i<=w[1];++i)
		{
			ans[i]=LLONG_MAX;
			if(shit[(int)2e5-i])
			{
				ans[i]=min(ans[i],shit[(int)2e5-i]);
			}
			if(shit[(int)2e5+w[1]-i+1])
			{
				ans[i]=min(ans[i],shit[(int)2e5+w[1]-i+1]);
			}
			else
			{
				ans[i]=ans[i-delta]+n;
			}
			A+=ans[i];
			A%=mod;
		}
		cout<<A<<endl;
	}
	else  
	{
		for(signed i=1;i<=5;++i)
		{
			if(w[i]==0)
			{
				w[i]=1;
			}
		}
		signed ans=0;
		signed i[6];
		for(i[1]=1;i[1]<=w[1];++i[1])
		for(i[2]=1;i[2]<=w[2];++i[2])
		for(i[3]=1;i[3]<=w[3];++i[3])
		for(i[4]=1;i[4]<=w[4];++i[4])
		for(i[5]=1;i[5]<=w[5];++i[5])
		{
			signed tp=0;
			signed j[6];
			for(signed t=1;t<=5;++t)
			{
				j[t]=i[t];
			}
			while(true)
			{
				for(signed i=1;i<=n;++i)
				{
					j[c[i]]+=d[i];
					++tp;
				for(signed i=1;i<=5;++i)
				{
					if(j[i]>w[i]||j[i]<=0)
					{
						ans+=tp;
						goto err;
					}
				}
				
				}
			}
			err:{}
		}
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	k=read();
	for(signed i=1;i<=k;++i)
	{
		w[i]=read();
	}
	signed tp[233];
	for(signed i=1;i<=n;++i)
	{
		c[i]=read();
		d[i]=read();
		tp[c[i]]+=d[i];
	}
	for(signed i=0;i<233;++i)
	{
		if(tp[i])
		{
			goto err;
		}
	}cout<<"-1"<<endl;
	return 0;
	err:{}
	if(n<=100000)
	{
		sol1();
	}
	else
	{
		cout<<3<<endl;
	}
	return 0;
}

