#include <bits/stdc++.h>
using namespace std;

template < typename T >
inline  const void read(register T &x)
{
 register bool flag = x = 0;
 register char c;
 while ((c = getchar()) < 48 || c > 57)
	   flag = c == '-';
 do
 {
  x = (x << 1) + (x << 3) + (c ^ 48);
 }while ((c = getchar()) > 47 && c < 58);
 if (flag) x = -x;
}

int OUTPUT[40];
template < typename T >
inline const void write(register T x)
{
 if (x < 0)
 {
  putchar('-');
  x = -x;
 }
 register short SIZE = 0;
 do
 {
  OUTPUT[SIZE++] = x % 10 | 48;
  x /= 10;
 }while (x > 0);
 while (SIZE > 0) putchar(OUTPUT[--SIZE]);
}

template < typename T >
inline const void writeln(register T x)
{
 write(x);
 putchar(10);
}

const long long MAXN = 604661760000000000; 
int n, m, tot = 0;
int son[100001][5];
long long f[100001];
bool vis[100001];
int next[500001], head[100001], ver[500001], d[100001];
void add(int u, int v)
{
	next[++tot] = head[u], head[u] = tot, ver[tot] = v;
}
queue < int > q;
void dfs(int pt)
{
	for (int i = head[pt];i;i = next[i])
	{
		if (!f[ver[i]]) dfs(f[ver[i]]);
		f[pt] += f[ver[i]] / d[ver[i]];
	}
	for (int i = 1; i <= d[pt]; i++)
		if (d[son[pt][i]] != 0) q.push(son[pt][i]);
}

void bfs()
{	
	for (int i = 1; i <= d[1]; i++) if (d[son[1][i]]) q.push(son[1][i]);
	while (!q.empty())
	{
		int now = q.front();q.pop();
		dfs(now);
	}
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n);read(m);
	for (int i = 1; i <= n; i++)
	{
		read(d[i]);
		for (int j = 1; j <= d[i]; j++)
		{
			int v;
			read(v);
			add(v, i);
			son[i][j] = v;
		}
	}
	f[1] = 604661760000000000;
	bfs();
	for (int i = 1; i <= n; i++)
	{
		long long ans3 = 0, ans4 = 0, ans5 = 0;
		if (d[i] == 0)
		{
			for (int j = head[i]; j; j = next[j])
			{
				if (d[ver[j]] == 1) ans4 += 4 * f[ver[j]];
				if (d[ver[j]] == 2) ans4 += 2 * f[ver[j]];
				if (d[ver[j]] == 3) ans3 += f[ver[j]];
				if (d[ver[j]] == 4) ans4 += f[ver[j]];
				if (d[ver[j]] == 5) ans5 += f[ver[j]];
			}
			long long gcd, bcs3 = 0, bcs4 = 0, bcs5 = 0, cs3 = 3, cs4 = 4, cs5 = 5;
			if (ans3 != 0)
			{
				gcd = __gcd(1813985280000000000, ans3);
				bcs3 = ans3 / gcd, cs3 = 1813985280000000000 / gcd;
			}
			if (ans4 != 0)
			{
				gcd = __gcd(2418647040000000000, ans4);
				
				bcs4 = ans4 / gcd, cs4 = 2418647040000000000 / gcd;
			}
			if (ans5 != 0)
			{
				gcd = __gcd(3023308800000000000, ans5);
				bcs5 = ans5 / gcd, cs5 = 3023308800000000000 / gcd;
			}
			gcd = __gcd(cs3, __gcd(cs4, cs5));
			long long cs = cs3 * cs4 * cs5 / gcd / gcd;
			long long bcs = bcs3 * cs / cs3 + bcs4 * cs / cs4 + bcs5 * cs / cs5;
			gcd = __gcd(cs, bcs);
			write(bcs / gcd);putchar(' ');writeln(cs / gcd);
		}
	}
 return 0;
}
/*5 1
3 2 3 5
2 4 5
2 4 5
0
0
*/
