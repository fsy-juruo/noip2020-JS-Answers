#include<bits/stdc++.h>
using namespace std;

const int N=305;
int n,m,a[N][N],b[N];
int st[N],cnt;
int rr[1000005][2];

void add(int x,int y)
{
	rr[++cnt][0]=x;
	rr[cnt][1]=y;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int id=1;id<n;id++)
	{
		if(b[id]==m) continue;
//		cout<<id<<endl;
		for(int j=b[id]+1;j<=m;j++) st[++st[0]]=a[id][j];
		while(st[0])
		{
			int u=st[st[0]--];
//			cout<<' '<<u<<endl;
			if(u==id)
			{
				add(id+1,n+1),add(id,id+1),b[id]++;
				for(int i=b[id]+1;i<=m;i++) add(id,n+1);
				add(id+1,id);
				for(int i=b[id]+1;i<=m;i++) add(n+1,id);
				add(n+1,id+1);
			}
			else
			{
				st[++st[0]]=a[u][m];
				for(int i=m;i>=b[u]+1;i--) a[u][i]=a[u][i-1];
				for(int i=b[u]+1;i<=m;i++) add(u,n+1);
				add(id,u),a[u][++b[u]]=u;
				for(int i=b[u]+1;i<=m;i++) add(n+1,u);
				add(n+1,id);
			}
//			cout<<endl;
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d %d\n",rr[i][0],rr[i][1]);
}
