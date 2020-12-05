#include<bits/stdc++.h>
using namespace std;
int a[100001];
int sum[100001];
int head[1001001];
int h[100001];
//int v[100001];
bool b[100001];
int p[100001];
int q[100001];
int num(int a,int b)
{
		if(b==0)
			return a;
		return num(b,a%b);
}
int dfs(int now)
{
	int a,b;
	a=p[now];
	b=q[now]*(sum[now]-sum[now-1]);
	for(int i=sum[now-1]+1;i<=sum[now];i++)
	{
		int z,x,y;
		z=b*q[head[i]]/num(b,q[head[i]]);
		x=z/b;
		y=z/q[head[i]];
		q[head[i]]=z;
		p[head[i]]=a*x+p[head[i]]*y;
		int h=num(q[head[i]],p[head[i]]);
		p[head[i]]/=h;
		q[head[i]]/=h;
		dfs(head[i]);
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[m+1];
	int w[n+1];
	int k=0;
	int f=0;
	int s=0;
//	for(int i=0;i<=n+10;i++)
//		v[i]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>sum[i];
		if(sum[i]==0)
			w[++f]=i;	
		for(int j=1;j<=sum[i];j++)
		{
			int a,c;
			
			if(j==1)
				cin>>head[++k],b[head[k]]=1;//,v[k]=-1
			else
			{
				cin>>a;
				b[a]=1;
//				v[k+1]=v[k];
//				v[k]=j;
				head[++k]=a;	
			}		
		}	 
		sum[i]+=sum[i-1];
	}
	k=0;
	
	for(int i=1;i<=n;i++)
	{
		int a=m;
		if(b[i])
			continue;
		p[i]=1;
		q[i]=1;
		x[++s]=i;	
	}
	for(int i=1;i<=m;i++)
		dfs(x[i]);

fclose(stdin);
	fclose(stdout)
	return 0;
}
//	for(int i=1;i<=f;i++)
//		cout<<p[i]<<" "<<q[i]<<endl;
//	while(1)
//	{
//		cout<<head[++k]<<" ";
//		if(v[k]==-1&&v[k+1]==-1)
//			break;
//		if(v[k]==-1)
//			cout<<endl;
//	}
//	for(int i=1;i<=3;i++)
//	{
//		cout<<head[i]<<" "<<v[i]<<endl;;
//	}

