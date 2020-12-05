#include <bits/stdc++.h>
using namespace std;

template < typename T >
inline void read(T &x)
{
	x = 0;
	bool flg = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57)
		flg |= c == '-';
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
	if (flg) x = -x;
}

int OUTPUT[45];

template < typename T >
inline void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int len = 0;
	do
	{
		OUTPUT[++len] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (len)
		putchar(OUTPUT[len--]);
}

template < typename T >
inline void writesp(T x)
{
	write(x);
	putchar(32);
}

template < typename T >
inline void writeln(T x)
{
	write(x);
	putchar(10);
}

const int N = 5e5 + 5, P = 1e9 + 7, K = 15;
int n, k, ans, cnt, c[N], d[N], w[N], a[N], b[N], lst[N][K];
//set < vector < int > > st;
//vector < int > v;

inline void Check()
{
	if (cnt >= 100000000)
	{
		puts("-1");
		exit(0);
	}
}

void dfs(int dep = 1)
{
	++cnt;
//	writeln(cnt);
	Check();
	if (dep > k)
	{
//		st.clear();
		for (int i = 1; i <= k; ++i)
			b[i] = a[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= k; ++j)
				lst[i][j] = 0;
		cnt += n * k;
		Check();
		for (int i = 1/*, cnt = 1*/; ; ++i/*, ++cnt*/)
		{
			if (i > n) i = 1;
			b[c[i]] += d[i];
			++ans;
			for (int j = 1; j <= k; ++j)
				if (b[j] != lst[i][j]) goto C;
			puts("-1");
			exit(0);
			C:;
//			Check();
			for (int j = 1; j <= k; ++j)
				lst[i][j] = b[j];
//			v.erase(v.begin(), v.end());
//			v.push_back(i);
//			for (int j = 1; j <= k; ++j)
//				v.push_back(b[j]);
//			if (st.find(v) != st.end())
//			{
//				puts("-1");
//				exit(0);
//			}
//			st.insert(v);
			if (b[c[i]] < 1 || b[c[i]] > w[c[i]])
			{
				
				return;
			}
		}
		return;
	}
	for (int i = 1; i <= w[dep]; ++i)
	{
		a[dep] = i;
		dfs(dep + 1);
	}
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n);
	read(k);
	for (int i = 1; i <= k; ++i)
		read(w[i]);
	for (int i = 1; i <= n; ++i)
		read(c[i]), read(d[i]);
	dfs();
	writeln(ans);
//	End:puts("-1");
	return 0;
}

