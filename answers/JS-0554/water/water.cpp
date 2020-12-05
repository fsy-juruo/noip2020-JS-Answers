#include<bits/stdc++.h>
using namespace std;
int Mapp[100100][20];
bool h[100100];
int Input[100100],L;
struct node
{
	long long x,y;
}S[100100];
long long Getgcd(long long m,long long n)
{
	long long r=m%n;
	while(r)
	{
		m=n;
		n=r;
		r=m%n;	
	}	
	return n;
}
node Plus(node a, node b)
{
	if(a.x==0&&a.y==0)
	{
		return b;
	}
	long long tx=a.x*b.y+a.y*b.x,ty=a.y*b.y;
	long long Gcd=Getgcd(tx,ty);
	
	tx/=Gcd,ty/=Gcd;
	node res;
	res.x=tx,res.y=ty;
	return res;
}
void dfs(int Nod,long long wat)
{
	if(Mapp[Nod][0]==0)
	{
		node p;
		p.x=1,p.y=wat;
		S[Nod]=Plus(S[Nod],p);
		return;
	}
	for(int i=1;i<=Mapp[Nod][0];++i)
	{
		dfs(Mapp[Nod][i],wat*Mapp[Nod][0]);
	}
}
int main()
{
	freoepn("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>Mapp[i][0];
		for(int j=1;j<=Mapp[i][0];++j)
		{
			cin>>Mapp[i][j];
			h[Mapp[i][j]]=1;
		}
	}
	
	for(int i=1;i<=n;++i)
	{
		if(h[i]==0)Input[++L]=i;
	}
	for(int i=1;i<=L;++i)
	{
		dfs(Input[i],1);
	}
	for(int i=1;i<=n;++i)
	{
		if(Mapp[i][0]==0)cout<<S[i].x<<' '<<S[i].y<<endl;
	}
	return 0;
}
