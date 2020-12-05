#include<bits/stdc++.h>
using namespace std;
int n,m,num,top;
int head[100010],ru[50],fz[100010],fm[100010],chu[100010],ansfz[100010],ansfm[100010];
bool visi[100010];
struct node
{
	int to;
	int next;
}edge[5*100010];
void add(int a,int b)
{
	num++;
	edge[num].to=b;
	edge[num].next=head[a];
	head[a]=num;
}
int gys(int a,int b)
{
	int c=a%b;
	if(c==0)
		return b;
	else
		return gys(b,c);
}
void dfs(int k)
{
	for(int i=head[k];i;i=edge[i].next)
	{
		int v=edge[i].to;
		fz[v]=1;
		fm[v]=fm[k]*chu[k];
		dfs(v);
		fz[v]=0;
		fm[v]=0;
	}
	if(chu[k]==0)
	{
		if(ansfz[k]==0)
		{
			ansfz[k]=fz[k];
			ansfm[k]=fm[k];
		}
		else
		{
			int maxg=gys(fm[k],ansfm[k]);
			int mingbs=fm[k]/maxg*ansfm[k];	
			ansfz[k]=mingbs/ansfm[k]*ansfz[k]+mingbs/fm[k]*fz[k];
			ansfm[k]=mingbs;
			maxg=gys(ansfz[k],ansfm[k]);
			ansfz[k]/=maxg;
			ansfm[k]/=maxg;
		}
		
	}
	
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int d,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d);
		chu[i]=d;
		for(int j=1;j<=d;j++)
		{
			scanf("%d",&x);
			visi[x]=true;
			add(i,x);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(top==m)
			break;
		if(!visi[i])
		{
			top++;
			ru[top]=i;
			fz[i]=1;
			fm[i]=1;
		}
	}
	for(int i=1;i<=m;i++)
		dfs(ru[i]);
	for(int i=1;i<=n;i++)
		if(chu[i]==0)
		printf("%d %d\n",ansfz[i],ansfm[i]);
	return 0;
}
