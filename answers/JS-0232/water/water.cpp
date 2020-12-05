#include<bits/stdc++.h>
using namespace std;
#define int long long
#define to lzto
#define tuopu lztuopu
inline void read(int &num)
{
	num=0;
	int f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		num=num*10+c-48;
		c=getchar();
	}
	num*=f;
}
const int maxn = 1e6+7;
const int inf = 0x7fffffff;

int n,m,tot,x,d,cnt;
int hed[maxn],to[maxn],nxt[maxn],ru[maxn],val[maxn];
int fenzi[maxn],fenmu[maxn],chu[maxn],ans[maxn],id[maxn]; 
queue<int>q;

void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=hed[x];
	hed[x]=tot;
}

int gcd(int a,int b)
{
	if(!(a%b))
		return b;
	return gcd(b,a%b);
}

void lzflo(int x,int y)
{
	int fz1,fm1,fz2,fm2;
	
	fz1=fenzi[x];
	fm1=fenmu[x]*chu[x];
	fz2=fenzi[y];
	fm2=fenmu[y];
	fenzi[y]=fm2*fz1+fm1*fz2;
	fenmu[y]=fm1*fm2;
	int k=gcd(fenzi[y],fenmu[y]);
	fenzi[y]/=k;
	fenmu[y]/=k;
}

void tuopu()
{
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=hed[x];i;i=nxt[i])
		{
			int y=to[i];
			lzflo(x,y);
			ru[y]--;
			if(!ru[y])
				q.push(y);
		}
		if(chu[x])
		{
			fenzi[x]=0;
			fenmu[x]=1;
		}
	}
}


signed main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i)
	{
		fenmu[i]=1;
		read(d);
		for(int j=1;j<=d;++j)
			read(x),add(i,x),ru[x]++,chu[i]++;
	}
	for(int i=1;i<=n;++i)
		if(!chu[i])
			id[++cnt]=i;
	for(int i=1;i<=m;++i)
		fenzi[i]=1,fenmu[i]=1;
	for(int i=1;i<=n;++i)
		if(!ru[i])
			q.push(i);
	tuopu();
	for(int i=1;i<=cnt;++i)
	{
		x=id[i];
		int k=gcd(fenzi[x],fenmu[x]);
		fenzi[x]/=k;
		fenmu[x]/=k;
		printf("%lld %lld\n",fenzi[x],fenmu[x]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
