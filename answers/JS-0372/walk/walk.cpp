#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	int num=0;bool flg=false;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') flg=true;
	else num=ch^48;
	ch=getchar();
	while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch^48),ch=getchar();
	return flg?-num:num;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((x%10)^48);
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
const int p=1e9+7,N=5e5+5;
int tmp,ans;
int n,k,w[15],c[N],d[N],mx[N],mn[N],L,R,t[15];
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	tmp=1;
	for(int i=1;i<=k;i++) w[i]=read(),tmp=tmp*w[i]%p;
	ans=tmp;
	for(int i=1;i<=n;i++)
	{
		c[i]=read(),d[i]=read();
		t[c[i]]+=d[i];
		mx[c[i]]=max(mx[c[i]],t[c[i]]),mn[c[i]]=min(mn[c[i]],t[c[i]]);
		tmp=1;
		for(int j=1;j<=k;j++)
		{
			L=max(1ll,1-mn[j]),R=min(w[j],w[j]-mx[j]);
			if(L>R)
			{
				tmp=-1;
				break;
			}
			tmp=tmp*(R-L+1)%p;
		}
		if(tmp==-1) break;
		ans=(ans+tmp)%p;
	}
	if(tmp==-1)
	{
		writeln(ans);
		return 0;
	}
	bool flg=false;
	for(int i=1;i<=k&&!flg;i++)
	{
		if(t[i]) flg=1;
	}
	if(!flg)
	{
		writeln(-1);
		return 0;
	}
	int stp=1;
	while(1)
	{
		t[c[stp]]+=d[stp];
		mx[c[stp]]=max(mx[c[stp]],t[c[stp]]),mn[c[stp]]=min(mn[c[stp]],t[c[stp]]);
		tmp=1;
		for(int j=1;j<=k;j++)
		{
			L=max(1ll,1-mn[j]),R=min(w[j],w[j]-mx[j]);
			if(L>R)
			{
				tmp=-1;
				break;
			}
			tmp=tmp*(R-L+1)%p;
		}
		if(tmp==-1) break;
		ans=(ans+tmp)%p;
		stp=stp%n+1;
	}
	writeln(ans);
	return 0;
}

