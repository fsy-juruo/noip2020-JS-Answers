// 1 ~ 10
#include <bits/stdc++.h>
using namespace std;
/*things you should actually check:
0. memory limit                     // < 6.7M
1. overflow                         // 1e14
2. special cases                    // no
3. do smth. better than noth.       //
4. stay organized                   //
5. complete freopen                 // completed
6. simple is better than ugly       //
7. flat is better than nested       //
8. sparse is better than dense      //
9. readablity counts                //
*/
int n, m;
int d[100005], a[100005][10]; // ~4.5M
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
struct frac
{
	long long num, den;
	frac()
	{
		num = 0;
		den = 1;
	}
	frac operator+(frac f)
	{
		frac g;
		g.den = den * f.den;
		g.num = num * f.den + den * f.num;
		int h = gcd(g.den, g.num);
		g.den /= h;
		g.num /= h;
		return g;
	}
	frac operator/(long long i)
	{
		frac f;
		f.den = den * i;
		f.num = num;
		int g = gcd(f.den, f.num);
		f.den /= g;
		f.num /= g;
		return f;
	}
} ans[100005]; // ~1.7M
int in[100005]; // ~0.5M
queue<int> q;
void print(frac f)
{
	printf("%lld %lld\n", f.num, f.den);
}
#define list_checked
#ifdef list_checked
int main()
{
#ifndef LOCAL
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		for (int j = 0; j < d[i]; j++)
		{
			scanf("%d", &a[i][j]);
			in[a[i][j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		ans[i].num = 1;
		q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < d[cur]; i++)
		{
			ans[a[cur][i]] = ans[a[cur][i]] + ans[cur] / d[cur];
			in[a[cur][i]]--;
			if (in[a[cur][i]] == 0) q.push(a[cur][i]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == 0)
		{
			print(ans[i]);
		}
	}
	return 0;
}
#endif
/*sample:
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
