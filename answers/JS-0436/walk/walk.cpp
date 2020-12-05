#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;


int n,k,maxw;
int w[15],ans;
int c[100010],d[100010];

template<typename Tp>
void read(Tp &x)
{
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}

int st[15],tp;
int s[15];

void dfs2(int now)
{
	if(now>n) now=1;
	for(int i=1;i<=k;i++)
	{
		if(s[i]<=0||s[i]>w[i]) return;
	}
	s[c[now]]+=d[now],ans++;
	dfs2(now+1);
}

void dfs1(int x)
{
	if(x>k)
	{
		memcpy(s,st,sizeof(s));
		dfs2(1);
		return;
	} 
	for(int i=1;i<=w[x];i++)
	{
		st[++tp]=i;
		dfs1(x+1);
		tp--;
	}
}

int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=k;i++)
	{
		read(w[i]);
		maxw=max(maxw,w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		read(c[i]),read(d[i]);
	}
	if(n<=100&&k<=5&&maxw<=10)
	{
		dfs1(1);
		printf("%d\n",ans);
	}
	else printf("-1\n");
	return 0;
}
/*
?
3 2
3 3
1 1
2 -1
1 1
*/
