#include<bits/stdc++.h>
using namespace std;
int n,m,psk[100010],tot,p[100010],q[100010],k;//psk保存排水口 
bool jsk[100010];//jsk判断是否是接收口
vector<int>edge[100010];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch^'0';ch=getchar();}
	return x*f;
}
int gcd(int x,int y)
{
	int r=x%y;
	while(r)
	{
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
void add(int x,int c,int d)
{
	if(p[x]==0)
	{
		p[x]=c;
		q[x]=d;
		return;
	}
	int a=p[x],b=q[x],f=1ull*b*d/gcd(b,d);
	a*=f/b;
	c*=f/d;
	a+=c;
	int ff=gcd(a,f);
	p[x]=a/ff;
	q[x]=f/ff;
	return;
}
void work(int u,int num)
{
	if(edge[u].size()==0)
	{
		add(u,1,num);
		return;	
	}
	for(int i=0;i<edge[u].size();++i)
	work(edge[u][i],num*edge[u].size());
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
	{
		p[i]=0;
		q[i]=1;
		int d;
		d=read();
		for(int j=1;j<=d;++j)
		{
			int a;
			a=read();
			jsk[a]=true;
			edge[i].push_back(a);
		}
		if(d==0)psk[++tot]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(k==m)break;
		if(jsk[i]==false)
		{
			k++;
			p[i]=1;
			work(i,1);
		}
	}
	for(int i=1;i<=tot;++i)
	{
		printf("%d %d\n",p[psk[i]],q[psk[i]]);
	}
	return 0;
}
