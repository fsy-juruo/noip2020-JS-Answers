#include<bits/stdc++.h>

#define N 100005
#define INF 0x3f3f3f3f
#define int long long

using namespace std;

int degree[N], d[N], head[N], nex[N << 3], to[N << 3], tot, n, m, x;
int a[N], b[N];

queue<int> q;

void addedge(int x, int y)
{
	nex[++ tot] = head[x];
	to[tot] = y;
	head[x] = tot;
}

int gcd(int x, int y)
{
	if(!y) return x;
	return gcd(y, x % y);
}

void spy(int &x, int &y)
{
	int g = gcd(x, y);
	x /= g; y /= g;
}

void add(int &x, int &y, int a, int b)
{
	int l = b * y / gcd(b, y);
	x *= l / y; a *= l / b;
	x += a; y = l;
	spy(x, y);
}

signed main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
	{
		a[i] = 0; b[i] = 1;
		scanf("%lld", &d[i]);
		for(int j = 1; j <= d[i]; ++ j)
		{
			scanf("%lld", &x);
			addedge(i, x);
			degree[x] ++;
		}
	}
	for(int i = 1; i <= n; ++ i)
		if(!degree[i]) q.push(i);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(u <= m) a[u] = 1;
		if(!d[u]) continue;
		b[u] *= d[u]; spy(a[u], b[u]);
		for(int i = head[u]; i; i = nex[i])
		{
			int v = to[i];
			add(a[v], b[v], a[u], b[u]);
			degree[v] --;
			if(!degree[v]) q.push(v);
		}
	}
	for(int i = 1; i <= n; ++ i)
		if(!d[i]) printf("%lld %lld\n", a[i], b[i]);
	return 0;
}
