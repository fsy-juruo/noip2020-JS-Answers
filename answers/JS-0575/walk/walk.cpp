#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline int read()
{
	int X = 0; bool f = false; char ch = getchar();
	while (ch < '0' || ch > '9') {f |= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return f ? -X : X;
}
inline void write(int X)
{
	if (X == 0) {putchar('0'); return;}
	if (X < 0) {putchar('-'); X = -X;}
	short cnt = 0, num[20];
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
int mp[11], startmp[11], gomp[11];
int n, k, ans;
vector < int > c, d;
bool f;
void walk()
{
	for (int i = 1; i <= k; ++i) gomp[i] = startmp[i];
	for (int i = 0; i < c.size(); ++i)
	{
		ans = (ans + 1) % mod;
		if (gomp[c[i]] + d[i] > mp[c[i]] || gomp[c[i]] + d[i] < 1) return;
		gomp[c[i]] += d[i];
	}
	f = true;
	for (int i = 1; i <= k; ++i) f &= gomp[i] == startmp[i];
	if (f) {printf("-1\n"); exit(0);}
	while (1)
	{
		for (int i = 0; i < c.size(); ++i)
		{
			ans = (ans + 1) % mod;
			if (gomp[c[i]] + d[i] > mp[c[i]] || gomp[c[i]] + d[i] < 1) return;
			gomp[c[i]] += d[i];
		}
	}
	return;
}
void restart(short dep)
{
	if (dep > k) {walk(); return;}
	for (int i = 1; i <= mp[dep]; ++i)
	{
		startmp[dep] = i;
		restart(dep + 1);
	}
	return;
}
int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read();
	k = read();
	for (int i = 1; i <= k; ++i) mp[i] = read();
	for (int i = 1; i <= n; ++i) {c.push_back(read()); d.push_back(read());}
	restart(1);
	write(ans); putchar('\n');
	return 0;
}
