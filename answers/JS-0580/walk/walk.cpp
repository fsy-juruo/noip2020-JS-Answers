#include <bits/stdc++.h>
using namespace std;
#define PROG "walk"
#define FILEIO 1
#define DEBUG 0

const int MOD=1e9+7;
const int K=10, N=5e5;
int n, k, w[K], c[N], d[N];

struct point
{
	vector<int> v;
	inline point()
	{ v.resize(k, 1); }
	inline int& operator[] (int p)
	{ return v[p]; }
	inline int operator[] (int p) const
	{ return v[p]; }
	bool valid() const
	{
		for (int i=0; i<k; ++i)
		{
			if (v[i]<1||v[i]>w[i])
				return false;
		}
		return true;
	}
	point& operator++()
	{
		int i=k-1;
		++v[i];
		while (i>=0&&v[i]>w[i])
		{
			v[i]=1; --i;
			++v[i];
		}
		if (i<0) v[0]=0;
		return *this;
	}
	void print()
	{
		printf("(%d", v[0]);
		for (int i=1; i<k; ++i)
		{
			printf(",%d", v[i]);
		}
		printf(")");
	}
};

const int O=1e5;
int cnt;
point p;

void dfs(int o)
{
	//printf("$ dfs(%d) ", o);
	//p.print();
	//printf("\n");
	if (cnt==-1) return;
	if (!p.valid())
	{
		cnt=o;
		return;
	}
	if (o>=O)
	{
		cnt=-1;
		return;
	}
	int i=o%n;
	p[c[i]]+=d[i];
	dfs(o+1);
	p[c[i]]-=d[i];
}

void solve()
{
	int i, ans=0;
	scanf("%d%d", &n, &k);
	for (i=0; i<k; ++i)
		scanf("%d", &w[i]);
	for (i=0; i<n; ++i)
	{
		scanf("%d%d", &c[i], &d[i]);
		--c[i];
	}
	point s;
	while (s[0])
	{
		cnt=0; p=s;
		dfs(0);
		//printf("$ ");
		//s.print();
		//printf(" = %d\n", cnt);
		++s; ans+=cnt; ans%=MOD;
	}
	printf("%d\n", ans);
}

int main()
{
#if FILEIO
	freopen(PROG ".in", "r", stdin);
	freopen(PROG ".out", "w", stdout);
#endif
	solve();
#if FILEIO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
