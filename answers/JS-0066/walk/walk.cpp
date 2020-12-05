#include<bits/stdc++.h>
using namespace std;
#define ll long long
int readint()
{
	char c=getchar(); int neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
ll readll()
{
	char c=getchar(); ll neg=1,res=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') neg=-1;
	for(;'0'<=c&&c<='9';c=getchar()) res=res*10+(c-'0');
	return neg*res;
}
void writeint(int x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[15]; int top=0;
	while(x) {int nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void writell(ll x)
{
	if(x==0) {putchar('0'); return;}
	if(x<0) {putchar('-'); x=-x;}
	char stk[25]; int top=0;
	while(x) {ll nxt=x/10; stk[++top]=(x-nxt*10+'0'); x=nxt;}
	for(int i=top;i>=1;i--) putchar(stk[i]); return;
}
void Writeint(int x,char c)
{
	writeint(x); putchar(c); return;
}
void Writell(ll x,char c)
{
	writell(x); putchar(c); return;
}
const ll mod=1e9+7;
const int maxn=5e5+5;
const int maxk=15;
ll w[maxk];
int n,k,c[maxn],d[maxn];
ll l[maxk],r[maxk],minn[maxk],maxx[maxk],change[maxk];
ll changes[maxn][maxk],mn[maxn][maxk],mx[maxn][maxk];
void solveline()
{
	for(int i=1;i<=n;i++)
	{
		changes[i][1]=d[i];
		changes[i][1]+=changes[i-1][1];
		mn[i][1]=min(mn[i-1][1],changes[i][1]);
		mx[i][1]=max(mx[i-1][1],changes[i][1]);
	}
	bool possible=(changes[n][1]?false:true);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll l=1,r=w[1]*n;
		while(l<r)
		{
			ll mid=(l+r+1)>>1,rounds=mid/n,ret=mid%n;
			ll cur_mn=mn[(int)ret][1]+min((ll)0,rounds*changes[n][1]);
			ll cur_mx=mx[(int)ret][1]+max((ll)0,rounds*changes[n][1]);
			if(i+cur_mn>=1&&i+cur_mx<=w[1])
				l=mid;
			else r=mid-1;
		}
		if(l>=n&&possible)
		{
			puts("-1");
			exit(0);
		}
		ans+=l; ans-=(ans>=mod)*mod;
	}
	Writell(ans,'\n');
	exit(0);
	
}
void fl()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
}
int main()
{
//	printf("%.24lf\n",(sizeof(changes)+sizeof(mn)+sizeof(mx)+sizeof(c)+sizeof(change)+sizeof(d)+sizeof(k)+sizeof(l)+sizeof(maxk)+sizeof(maxn)+sizeof(maxx)+sizeof(minn)+sizeof(mod)+sizeof(n)+sizeof(r)+sizeof(w))/1024.0/1024.0);
	fl();
	n=readint(); k=readint();
	for(int i=1;i<=k;i++)
		w[i]=readll();
	for(int i=1;i<=n;i++)
	{
		c[i]=readint();
		d[i]=readint();
	}
//	if(k==1) solveline();
	for(int i=1;i<=k;i++)
	{
		l[i]=1;
		r[i]=w[i];
	}
	ll ans=0;
	for(ll t=1;;t++)
	{
		int i=(int)(t%n); if(i==0) i=n;
		ll lstv=1;
		for(int j=1;j<=k;j++)
			lstv=lstv*(r[j]-l[j]+1)%mod;
		change[c[i]]+=d[i];
		minn[c[i]]=min(minn[c[i]],change[c[i]]);
		maxx[c[i]]=max(maxx[c[i]],change[c[i]]);
		l[c[i]]=max(l[c[i]],(ll)1-minn[c[i]]);
		r[c[i]]=min(r[c[i]],w[c[i]]-maxx[c[i]]);
		ll curv=1;
		for(int j=1;j<=k;j++)
			curv=curv*(r[j]-l[j]+1)%mod;
		ans=(ans+(lstv-curv+mod)%mod*t%mod)%mod;
		if(l[c[i]]>r[c[i]]) break;
		if(t==n)
		{
			bool possible=true;
			for(int j=1;j<=k;j++)
				if(change[j])
				{
					possible=false;
					break;
				}
			if(possible)
			{
				puts("-1");
				return 0;
			}
		}
	}
	Writell(ans,'\n');
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

6 1
10
1 1
1 -1
1 -1
1 -1
1 -1
1 -1
*/

