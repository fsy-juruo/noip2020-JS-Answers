#include<bits/stdc++.h>
#define Mod 1000000007
using namespace std;
inline void read(long long &x)
{
	char ch;int f=1;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f;
}
inline void write(long long x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);putchar(x%10+'0');
}
inline void writeln(long long x,char ch)
{
	write(x);
	putchar(ch);
}
long long k,b[1001],a[1001],wmax[1001],wmin[1001],w[1001],n,c[1000001],d[1000001],W[1001];
long long solve()
{
	int f=0;
	for(int i=1;i<=k;i++)
	{
		b[i]=a[i];
		if(wmax[i]+a[i]>w[i]||wmin[i]+a[i]<=0)f=1;
	}
//	for(int i=1;i<=k;i++)
//	{
//		cout<<b[i]<<' ';
//	}
//	cout<<endl;
	if(f==1)
	{
		for(int i=1;i<=n;i++)
		{
			b[c[i]]+=d[i];
			if(b[c[i]]>w[i]||b[c[i]]<=0)
			{
				//cout<<"?"<<i<<' '<<b[i]<<endl;
				return i;
			}
		}
	}
	
	else
	{
		long long ans=0;
		while(1)
		{
			
			for(int i=1;i<=k;i++)
			{
			   // cout<<i<<' '<<b[i]<<endl;
				if(b[i]+wmax[i]>w[i]||wmin[i]+b[i]<=0)
				{
					f=i;break;
				}
				b[i]+=W[i];
				
			}
			if(f!=0)break;ans+=n;
			ans%=Mod;
			
		}
		for(int i=1;i<=n;i++)
		{
			//if(i%n==0)continue;
			b[c[i]]+=d[i];
			if(b[c[i]]>w[i]||b[c[i]]<0)
			{
			//	cout<<"???"<<ans<<endl;
				return ans+i;
			}
		}
	}
	
}
long long ans_;
void dfs(int dep )
{
	if(dep>k)
	{
		long long s=solve();
		ans_+=s;
		ans_=ans_%Mod;
	//	cout<<s<<endl;
		return;
	}
	for(int i=1;i<=w[dep];i++)
	{
        a[dep]=i;
        dfs(dep+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>c[i]>>d[i];
	}
	for(int i=1;i<=n;i++)
	{
		W[c[i]]+=d[i];
		if(W[c[i]]<wmin[c[i]])wmin[c[i]]=W[c[i]];
		if(W[c[i]]>wmax[c[i]])wmax[c[i]]=W[c[i]];
	}
//	for(int i=1;i<=k;i++)
//	{
//		cout<<W[i]<<' '<<wmax[i]<<' '<<wmin[i]<<endl;
//	}
	dfs(1);
	cout<<ans_<<endl;
	return 0;
}

