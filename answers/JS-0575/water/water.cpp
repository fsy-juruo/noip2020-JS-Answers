#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
inline ll read()
{
	ll X = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return X;
}
inline void write(ll X)
{
	if (X == 0) {putchar('0'); return;}
	short cnt = 0, num[21];
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
inline int gcd(ll a, ll b)
{
	int tmp;
	while (tmp = a % b) {a = b; b = tmp;}
	return b;
}
inline void add_water(ll &a, ll &b, ll pa, ll pb)
{
	ll f = gcd(b, pb);
	a = (ll)(a * 1.0 / f * pb + pa * 1.0 / f * b); b = (ll)(b * 1.0 / f * pb);
	f = gcd(a, b);
	a /= f; b /= f;
}
struct Node
{
	vector < int > tube;
	ll a, b;
}mp[100010];
ll n, m, d, a;
vector < int > isout;
queue < int > q;
void bfs(int x)
{
	int y;
	q.push(x);
	while (q.size())
	{
		x = q.front();
		if(mp[x].tube.size()) mp[x].b *= mp[x].tube.size();
		for(int i = 0; i < mp[x].tube.size(); ++i)
		{
			y = mp[x].tube[i];
			q.push(y);
			add_water(mp[y].a, mp[y].b, mp[x].a, mp[x].b);
		}
		if(mp[x].tube.size()) {mp[x].a = 0; mp[x].b = 1;}
		q.pop();
	}
	return;
}
int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read(); m = read();
	for (int i = 1; i <= n; ++i)
	{
		mp[i].a = 0; mp[i].b = 1;
		d = read();
		if (d == 0) isout.push_back(i);
		else
		{
			for(int j = 1; j <= d; ++j)
			{
				a = read();
				mp[i].tube.push_back(a);
			}
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		mp[i].a = 1;
		bfs(i);
	}
	for (int i = 0; i < isout.size(); ++i)
	{
		write(mp[isout[i]].a); putchar(' '); write(mp[isout[i]].b); putchar('\n');
	}
	return 0;
}
