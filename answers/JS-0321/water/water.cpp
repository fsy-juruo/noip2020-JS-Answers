#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+ch-48;ch=getchar();}
	return sum*f;
}
struct node{
	long long fz,fm;
};
node a[100005];
vector<long long> vec[100005];
long long rd[100005];
bool vis[100005];
bool ps[100005];
long long n,m;
node pl(node a,node b)
{
	node c;
	c.fm=a.fm*b.fm;
	c.fz=a.fm*b.fz+a.fz*b.fm;
	return c;
}
long long gcd(long long x,long long y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
node yf(node a)
{
	if(a.fm==0||a.fz==0) return a;
	long long k=gcd(a.fm,a.fz);
	node p;
	p.fm=a.fm/k;
	p.fz=a.fz/k;
	return p;
}
void topsort(long long now)
{
	if(vis[now]) return;
	vis[now]=1;
	node p=a[now];
	p.fm*=vec[now].size();
	for(long long i=0;i<vec[now].size();i++)
		{
			long long to=vec[now][i];
			a[to]=pl(a[to],p);
			a[to]=yf(a[to]);
			rd[to]--;
			if(rd[to]==0) topsort(to);
		}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=n;i++) a[i].fm=1;
	for(long long i=1;i<=m;i++)
		{
			a[i].fm=1;
			a[i].fz=1;
		}
//	for(int i=1;i<=n;i++) cout<<a[i].fz<<" "<<a[i].fm<<endl;
//	cout<<pl(a[1],a[2]).fz<<" "<<pl(a[1],a[2]).fm<<endl;
	for(long long i=1;i<=n;i++)
		{
			long long k=read();
			for(long long j=1;j<=k;j++)
				{
					long long x=read();
					vec[i].push_back(x);
					rd[x]++;
				}
			if(k==0) ps[i]=1;
		}
	for(long long i=1;i<=n;i++)
		{
			if(!vis[i]&&rd[i]==0)
				{
					topsort(i);
				}
		}
	for(long long i=1;i<=n;i++)
		{
			if(!ps[i]) continue;
			if(a[i].fz==0||a[i].fm==0) cout<<0<<endl;
			else cout<<a[i].fz<<" "<<a[i].fm<<endl;
		}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
