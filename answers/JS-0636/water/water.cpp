#include<bits/stdc++.h>
using namespace std;
int ind[100005];
long long a[100005], b[100005];
bitset<100005> vis;
vector<int> g[100005];
int siz[100005];
long long gcd(long long a, long long b)
{
	return a? gcd(b%a, a):b;
}
inline void add(int t, int f)
{
	long long tb = b[t]*b[f]*siz[f];
	long long ta = b[t]*a[f]+b[f]*siz[f]*a[t];
	long long g = gcd(ta, tb);
	a[t] = ta/g, b[t] = tb/g;
}
void dfs(int p)
{
	vis[p] = true;
	for(int i = 0; i < g[p].size(); ++i)
	{
		int t = g[p][i];
		--ind[t]; add(t, p);
		if(ind[t] == 0)
			dfs(t);
	}
}
int main(void)
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		int p; scanf("%d", &p);
		for(int k = 1; k <= p; ++k)
		{
			int t; scanf("%d", &t);
			g[i].push_back(t);
			++ind[t];
		}
		siz[i] = p;
	}
	for(int i = 1; i <= n; ++i)
		b[i] = 1;
	for(int i = 1; i <= n; ++i)
	{
		if(vis[i]) continue;
		if(ind[i] == 0)
		{
			a[i] = 1;
			dfs(i);
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!siz[i]) // size == 0
		{
			long long A = a[i], B = b[i];
			long long g = gcd(A, B);
			printf("%lld %lld\n", A/g, B/g);
		}
	return 0;
}
