# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n,m;
int d[N];
int in[N],out[N];
bool vis[N];
vector <int> f[N];

vector <int> S;
vector <int> T;

struct Num // p / q;
{
	long long p,q;
	Num(){}
	Num(long long _p,long long _q) : p(_p),q(_q) {}
}A[N];

long long gcd(long long,long long );

long long gcd(long long x,long long y)
{
	if(x % y == 0) return y;
	else return gcd(y,x % y);
}

long long gggcd(long long x,long long y)
{
	if(x == 0 && y == 0) return 1;
	else return gcd(x,y);
}

long long lcm(long long x,long long y)
{
//	if(x == 0 && y == 0) return
	return x * y / gcd(x,y);
}

Num operator +(const struct Num &x,const struct Num &y)
{
//	printf("S+\n");
//	printf("xp = %d,xq = %d,yp = %d,yq = %d\n",x.p,x.q,y.p,y.q);
	if(x.p == 0 && x.q == 0)
	{
		return y;
	}
	if(y.p == 0 && y.q == 0) 
	{
		return x;
	}
	long long newq = lcm(x.q,y.q);
//	printf("newq = %lld\n");
	long long Xp = x.p * (newq / x.q);
//	printf("Xp = %lld\n");
	long long Yp = y.p * (newq / y.q);
//	printf("Yp = %lld\n");
	Num New;
	New.q = newq;
	New.p = Xp + Yp;
	int ggcd = gggcd(New.q,New.p);
	New.q /= ggcd,New.p /= ggcd;
//	printf("T+\n");
	return New;
}

Num operator *(const struct Num &x,const struct Num &y)
{
//	printf("S*\n");
//	printf("xp = %lld,xq = %lld,yp = %lld,yq = %lld\n",x.p,x.q,y.p,y.q);
	if(x.p == 0 && x.q == 0) 
	{
		return Num(0,0);
	}
	if(y.p == 0 && y.q == 0) 
	{
		return Num(0,0);
	}
	long long newp = x.p * y.p;
	long long newq = x.q * y.q;
//	printf("newp = %lld,newq = %lld\n",newp,newq);
	if(newp == 0 || newq == 0) return Num(0,0);
	int ggcd = gggcd(newp,newq);
//	printf("ggcd = %lld\n",ggcd);
	newp /= ggcd,newq /= ggcd;
	Num New;
	New.p = newp,New.q = newq;
//	printf("T*\n");
	return New;
}

struct edge
{
	int to;
	Num w;
	edge(){}
	edge(int _to,Num _w) : to(_to),w(_w) {}
};

//vector <edge> g[N];

template <typename T> void read(T &x)
{
	int w = 1;
	x = 0;
	char ch = getchar();
	while(!isdigit(ch))
	{
		if(ch == '-') w = -1;
		ch = getchar();
	}
	while(isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= w;
	return;
}

void build(void)
{
	queue <int> q;
	for(int i = 0; i < S.size(); i++)
	{
		q.push(S[i]);
		vis[S[i]] = 1;
	}
	while(!q.empty())
	{
		int x = q.front();q.pop();
//		if(vis[x]) continue;
//		printf("x = %d\n",x);
		Num cur = Num(1,d[x]);
		Num w = cur * A[x];
//		printf("YES\n");
		for(int i = 0 ; i < f[x].size(); i++)
		{
			int v = f[x][i];
//			printf("x = %d,v = %d\n",x,v);
//			g[x].push_back(edge(v,w));
//			printf("YESbuild\n");
//			printf("A[v] : p = %d,q = %d\n",A[v].p,A[v].q);
			if(!vis[v]) 
			{
				vis[v] = 1;
				A[v] = w;
			}
			else A[v] = A[v] + w;
//			printf("YES2\n");
			q.push(v);
		}
		if(out[x] > 0) A[x] = Num(0,0);
	}
	return;
}

int main(void)
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
//	Num X = Num(3,4),Y = Num(4,7);
//	printf("%d %d\n",X.p,X.q);
	read(n),read(m);
	for(int i = 1; i <= n; i++)
	{
//		int d;
		read(d[i]);
		for(int j = 1; j <= d[i]; j++)
		{
			int v;
			read(v);
			f[i].push_back(v);
			in[v]++;
			out[i]++;
		}
	}
//	printf("YES\n");
	for(int i = 1; i <= n; i++)
	{
		if(in[i] == 0) S.push_back(i);
		if(out[i] == 0) T.push_back(i);
	}
	for(int i = 0; i < S.size(); i++)
	{
		int x = S[i];
		A[x].p = 1,A[x].q = 1;
	}
	build();
	for(int i = 0; i < T.size(); i++)
	{
		printf("%lld %lld\n",A[T[i]].p,A[T[i]].q);
	}
	return 0;
}
