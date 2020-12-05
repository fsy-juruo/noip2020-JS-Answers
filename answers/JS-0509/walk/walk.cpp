#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
const long long P = 1e9 + 7;
template <typename T>
void read(T &x)
{
	T f = 1; x = 0;
	char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
	for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
	x *= f;
}
template <typename T>
void write(T x)
{
	if (x < 0){
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar((char)(x % 10 + '0'));
}
template <typename T>
void writeln(T x, char ch = '\n')
{
	write(x); putchar(ch);
}
struct node
{
	int l;
	int r;
};
int n;
int m, k, w[19];
int c[MAXN], d[MAXN], hg[19], lw[19], b[19];
node a[19];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n); read(k);
	for (int i = 1; i <= k; i++)
		read(w[i]);
	for (int i = 1; i <= n; i++)
	{
		read(c[i]); read(d[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		b[c[i]] += d[i];
		if (b[c[i]] > hg[c[i]]) hg[c[i]] = b[c[i]];
		if (b[c[i]] < lw[c[i]]) lw[c[i]] = b[c[i]];
	}
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] != 0 || hg[i] - lw[i] > w[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{
		a[i].l = 1; a[i].r = w[i];
		b[i] = 0;
	}
	int pos = 1, p = 0;
	int ans = 0;
	while (a[pos].l <= a[pos].r)
	{
		b[c[pos]] += d[pos];
		int g = 0;
		if (b[c[pos]] < 0)
		{
			if (a[c[pos]].l <= -b[c[pos]]){
				g = -b[c[pos]] - a[c[pos]].l + 1;
				a[c[pos]].l = -b[c[pos]] + 1;
			} 
		}
		else if (b[c[pos]] > 0)
		{
			if (a[c[pos]].r > w[c[pos]] - b[c[pos]])
			{
				g = a[c[pos]].r - (w[c[pos]] - b[c[pos]]);
				a[c[pos]].r = w[c[pos]] - b[c[pos]];
			}
		}
		if (g == 0) continue;	
		p++;
		for (int i = 1; i <= k; i++)
		{
			if (i != c[pos]) {
				g *= (long long)(a[i].r - a[i].l + 1);
				g %= P;
			}
		}
		g *= p; g %= P;
		ans += g; ans %= P;
		if (a[c[pos]].r < a[c[pos]].l) break;
		if (pos == n) pos = 1;
		else pos++;
	}
	cout << ans << '\n';
	return 0; 
}

