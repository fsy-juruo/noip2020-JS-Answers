#include<bits/stdc++.h>
using namespace std;
struct node{
	long long p1,q1;
}ans[100010];
struct asf{
	int u,v,nex;
}edge[100010];
int n,m,tot,pre[100010],head[100010],d[100010];
vector<long long>rec[100010];
queue<int>q;
int read(){
	int cnt=0,b=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')b=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return b*cnt;
}
void add(int x,int y){
	tot++;
	edge[tot].u=x;
	edge[tot].v=y;
	edge[tot].nex=head[x];
	head[x]=tot; 
}
long long gcd(long long x,long long y){
	long long c;
	while(x)
	{
		c=x;
		x=y%x;
		y=c;
	}
	return c;
}
void deal(int x)
{
	long long pp=0,qq=1,c;
	for(int i=0;i<rec[x].size();i++)
	{
		pp=pp*rec[x][i]+qq;
		qq*=rec[x][i];
		c=gcd(pp,qq);
		pp/=c;
		qq/=c;
	}
	ans[x].p1=pp;
	ans[x].q1=qq;
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		int a;
		d[i]=read();
		for(int j=1;j<=d[i];j++)
		{
			a=read();
			pre[a]++;
			add(i,a);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!pre[i])
		{
			q.push(i);
			rec[i].push_back(1);
		}
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(d[x]==0){
			deal(x);
			continue;
		}
		for(int i=head[x];i!=-1;i=edge[i].nex)
		{
			int y=edge[i].v;
			for(int j=0;j<rec[x].size();j++)
			rec[y].push_back(rec[x][j]*d[x]);
			pre[y]--;
			if(pre[y]==0)q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i].p1)
			cout<<ans[i].p1<<' '<<ans[i].q1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
