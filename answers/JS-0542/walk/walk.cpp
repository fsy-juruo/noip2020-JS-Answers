#include<bits/stdc++.h>
using namespace std;
int n,k,w[20],c[500010],d[500010],s[20],ma[20],mi[20],f,ll[20],ans,lans;
const int mod=1000000007;
template<typename T> void read(T &x)
{
	long long f=1;x=0;char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=f;
}
void dfs(int x)
{
	if(x==k+1)
	{
		int i=1,lll[20];
		for(i=1;i<=k;i++) lll[i]=ll[i];
		i=1;
		while(1)
		{
			lll[c[i]]+=d[i];ans=(ans+1)%mod;
			if(lll[c[i]]<1||lll[c[i]]>w[c[i]]) break;
			i=i%n+1;	
		}
		return;
	}
	for(int i=1;i<=w[x];i++) 
	{
		ll[x]=i;
		dfs(x+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=k;i++) read(w[i]);memset(s,0,sizeof(s));memset(ma,0,sizeof(ma));memset(mi,0x3f,sizeof(mi));
	for(int i=1;i<=n;i++){
	read(c[i]);read(d[i]);s[c[i]]=s[c[i]]+d[i];ma[c[i]]=max(ma[c[i]],s[c[i]]);mi[c[i]]=min(mi[c[i]],s[c[i]]);
	} 
	f=0;
	for(int i=1;i<=k;i++)
	{
		if(s[i]!=0){f=1;break;}
		if(ma[i]>w[i]/2-1+w[i]&&mi[i]>w[i]/2-1+w[i]){f=1;break;}
	}
	if(f==0) {cout<<"-1"<<endl;return 0;}ans=0;
	dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}

