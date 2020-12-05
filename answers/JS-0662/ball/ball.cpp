#include<bits/stdc++.h>
using namespace std;
int cnt,a[888888],b[888888],N,m,arr[55][444],len[444],nw[444],used[444],col,c[444],u[444],mx,num[444],rst[444],req,cc,pos,pt[444];
pair<int,int> brr[55];
void process(int x,int y)
{
	if (x==y) return;
	++cnt;
	a[cnt]=x;b[cnt]=y;
	arr[y][++len[y]]=arr[x][len[x]];
	len[x]--;
}
void doit(int n)
{
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++)
	{
		memset(u,0,sizeof(u));
		for (int j=1;j<=m;j++)
		{
			if (!u[arr[nw[i]][j]]) 
			{
				u[arr[nw[i]][j]]=1;
				c[arr[nw[i]][j]]+=(j-1);
			}
		}
		for (int j=1;j<=N;j++)
		{
			if (!used[j] && !u[j]) c[j]+=m;
		}
	}
	mx=-1e9;
	for (int i=1;i<=N;i++)
	{
		if (!used[i] && mx<c[i]) 
		{
			mx=c[i];
			col=i;
		} 
	}
	used[col]=1;
	memset(num,0,sizeof(num));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (arr[nw[i]][j]==col) num[i]++;
		}
	}
	for (int i=1;i<=n;i++) brr[i]=make_pair(num[i],i);
	sort(brr+1,brr+n+1);
	for (int i=1;i<=brr[1].first;i++) process(nw[brr[n].second],nw[n+1]);
	for (int i=1;i<=n;i++)
	{
		rst[i]=0;
		for (int j=1;j<=m;j++)
		{
			if (arr[nw[brr[i].second]][j]==col) break;
			else rst[i]++;
 		}
	}
	for (int i=1;i<=m;i++) 
	{
		if (len[nw[brr[1].second]]==rst[1]) break;
		if (arr[nw[brr[1].second]][len[nw[brr[1].second]]]==col) process(nw[brr[1].second],nw[brr[n].second]);
		else process(nw[brr[1].second],nw[n+1]);
	}
	brr[n].first=0;
	for (int i=1;i<=m;i++)
	{
		if (arr[nw[brr[n].second]][i]==col) brr[n].first++;
	}
	for (int i=2;i<=n;i++)
	{
		req=m-brr[i].first;
		while(len[nw[brr[i-1].second]]>req)
		{
			process(nw[brr[i-1].second],nw[n+1]);
		} 
		while(len[nw[brr[i-1].second]]<req)
		{
			process(nw[n+1],nw[brr[i-1].second]);
		}
		for (int j=m;j>=1;j--)
		{
			if (len[nw[brr[i].second]]==rst[i] && i!=n) break;
			if (arr[nw[brr[i].second]][j]==col) process(nw[brr[i].second],nw[brr[i-1].second]);
			else process(nw[brr[i].second],nw[n+1]);
		}
	}
	cc=0;
	for (int i=1;i<=m;i++) cc+=(arr[nw[n+1]][i]==col);
	if (cc==0)
	{
		for (int i=1;i<n;i++)
		{
			for (int j=m;j>=1;j--)
			{
				if (arr[nw[brr[i].second]][j]==col) process(nw[brr[i].second],nw[brr[n].second]);
			}
		}
		pos=1;
		for (int i=1;i<=m;i++)
		{
			while(len[nw[brr[pos].second]]==m) pos++;
			process(nw[n+1],nw[brr[pos].second]);
		}
		for (int i=1;i<n;i++) pt[i]=nw[brr[i].second];
		pt[n]=nw[n+1];
		for (int i=1;i<=n;i++) nw[i]=pt[i];
		return;
	}
	for (int i=1;i<=cc;i++) process(nw[brr[n-1].second],nw[brr[n].second]);
	for (int i=m;i>=1;i--) 
	{
		if (arr[nw[n+1]][i]==col) process(nw[n+1],nw[brr[n-1].second]);
		else process(nw[n+1],nw[brr[n].second]);
	}
	for (int i=1;i<n;i++)
	{
		for (int j=m;j>=1;j--)
		{
			if (arr[nw[brr[i].second]][j]==col) process(nw[brr[i].second],nw[n+1]);
		}
	}
	pos=1;
	while(pos<n)
	{
		while(len[nw[brr[pos].second]]==m && pos<n) pos++;
		if (pos>=n) break;
		
		process(nw[brr[n].second],nw[brr[pos].second]);
	}
	while(len[nw[brr[n].second]]>0)
	{
		process(nw[brr[n].second],nw[n+1]);
	}
	for (int i=1;i<=n;i++) pt[i]=nw[brr[i].second];
	for (int i=1;i<=n;i++) nw[i]=pt[i];
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&N,&m);
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=m;j++)
		scanf("%d",&arr[i][j]);
	}
	for (int i=1;i<=N;i++) len[i]=m;
	for (int i=1;i<=N+1;i++) nw[i]=i;
	for (int i=N;i>=2;i--)
	{
		doit(i);
	}
	for (int i=1;i<=m;i++) 
	{
		if (nw[2]!=N+1) process(N+1,nw[2]);
	}
	printf("%d\n",cnt);
	for (int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",a[i],b[i]);
	}
	return 0;
}
