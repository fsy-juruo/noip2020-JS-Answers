#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x) // unsigned
{
	x = 0;
	char c;
	while (!isdigit(c = getchar()));
	x = (c ^ 48);
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
}
const int N = 100005;
int n, m, x;
int a[N];
vector<int> gin[N];
int d[N];
int gout[N][5];
bool vst[N];
int w[N], cur;
void dfs(int x)
{
	vst[x] = 1;
	for (int i = 0;i < gin[x].size();++i)
	{
		if (!vst[gin[x][i]])
			dfs(gin[x][i]);
	}
	w[++cur] = x;
}
//bool cmp(int )
struct frac
{
	ll a, b;
	frac(ll a = 0ll, ll b = 1ll):a(a), b(b){}
}tmp;
frac fstd(ll a, ll b)
{
	ll g = __gcd(a, b);
	return frac(a / g, b / g);
}
frac fdiv(const frac &x, ll y)
{
	return fstd(x.a, x.b*y);
}
frac fplus(const frac &x, const frac &y)
{
	return fstd(x.a*y.b+x.b*y.a, x.b*y.b);
}
frac ans[N];
int main()
{
	//time_t start_time = clock();
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	//ios::sync_with_stdio(0);
	read(n);read(m);
	for (int i = 1;i <= n;++i)
	{
		read(d[i]);
		for (int j = 0;j < d[i];++j)
		{
			read(gout[i][j]);
			gin[gout[i][j]].push_back(i);
		}
	}
	for (int i = 1;i <= n;++i)
	{
		if (!vst[i])
			dfs(i);
	}
	for (int i = 1;i <= m;++i)
	{
		ans[i] = 1ll;
	}
	for (int i = 1;i <= cur;++i)
	{
		x = w[i];
		if (d[x])
		{
			tmp = fdiv(ans[x], d[x]);
			for (int j = 0;j < d[x];++j)
				ans[gout[x][j]] = fplus(ans[gout[x][j]], tmp);
		}
		else
		{
			printf("%lld %lld\n", ans[x].a, ans[x].b);
		}
	}
	//cerr << "Time used: " << clock() - start_time << endl;
	return 0;
}

