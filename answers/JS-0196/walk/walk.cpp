#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x7f7f7f7fll;

int n,m,q=1,w[11],c[100005],d[100005];
int ans,st[11],p[100005],fp[200005];
int cnt[100005];

bool legal(int b[11])
{
	for(int i=1;i<=m;i++)
		if(b[i]<1 || b[i]>w[i])
			return 0;
	return 1;
}

int work()
{
	int b[11];
	for(int i=1;i<=m;i++)
		b[i] = st[i];
	int p=1,s=0;
	while(legal(b))
	{
		s++;
		b[c[p]] += d[p];
		p++;
		if(p>n)
		{
			bool flag=1;
			for(int i=1;i<=m;i++)
				if(b[i]!=st[i])
					flag = 0;
			if(flag)
			{
				puts("-1");
				exit(0);
			}
			p = 1;
		}
	}
	return s;
}

void dfs(int x)
{
	if(x==m+1)
	{
		ans += work();
		return;
	}
	for(int i=1;i<=w[x];i++)
	{
		st[x] = i;
		dfs(x+1);
	}
}

void subtask1()
{
	dfs(1);
	cout<<ans<<endl;
}

void subtask2()
{
	memset(fp,INF,sizeof(fp));
	int N = n;
	int mn=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		p[i] = p[i-1]+d[i];
		if(fp[p[i]+N]>=INF)
			fp[p[i]+N] = i;
		mn = min(mn,p[i]), mx = max(mx,p[i]);
	}
	for(int i=1;i<=-mn;i++)
		cnt[i] = fp[-i+N];
	for(int i=1;i<=mx;i++)
		cnt[w[1]-i+1] = fp[i+N];
	for(int i=-mn+1;i<=w[1]-mx;i++)
		if(p[n]==0)
		{
			puts("-1");
			return;
		}
		else if(p[n]>0)
		{
			int zq=(w[1]-mx+1-i+p[n]-1)/p[n];
			cnt[i] = n*zq;
			cnt[i] += cnt[i+p[n]*zq];
		}
		else
		{
			int zq=(i+mn-p[n]-1)/abs(p[n]);
			cnt[i] = n*zq;
			cnt[i] += cnt[i+p[n]*zq];
		}
	for(int i=1;i<=w[1];i++)
		ans += cnt[i];
	cout<<ans<<endl;
}

signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;cin>>w[i++]);
	for(int i=1;i<=m;i++)
		q *= w[i];
	for(int i=1;i<=n;scanf("%lld%lld",c+i,d+i),i++);
	if(n<=100)
		subtask1();
	else if(m==1)
		subtask2();
	else
		puts("-1");
	
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
1 -1
1 -1
*/
