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

const int N = 55, M = 405/*, MAXN = 820000*/, MAXN = 820005;
int n, m/*, a[N][M*/, K, X[MAXN], Y[MAXN];
vector < int > v[M];
//bool vis[M][M];

inline void F()
{
	writeln(K);
	for (int i = 1; i <= K; ++i)
		writesp(X[i]), writeln(Y[i]);
	exit(0);
}

inline bool Check()
{
	for (int i = n + 1; i; --i)
	{
		int len = v[i].size();
		if (len && len != m) return 0;
		if (len > 1)
		{
			for (int j = 1; j < len; ++j)
				if (v[i][j] != v[i][j - 1]) return 0;
		}
	}
//	for (int i = 1; i <= n; )
//	for (int i = n + 1; i; --i)
//	{
//		int len = v[i].size();
//		for (int j = 0; j < len; ++j)
//		{
//			if (f[v[i][j]])
//		}
//	}
	return 1;
}

inline bool CHK(int i, int j, int x, int y)
{
	if (i == y && j == x) return 0;
	return 1;
}

void dfs(int x = 0, int y = 0)
{
//	if (K > 20)
//	{
////		puts("0");
////		exit(0);
//		F();
////		return;
//	}
//	writesp(x), writeln(y);
//	writesp(v[x].size()), writeln(v[y].size());
//	for (int i = 0; i < v[x].size(); ++i)
//		writesp(v[x][i]);
//	puts("!");
//	if (K > MAXN - 10)
//	{
//		puts("QEAWRDFSAGB");
//		exit(0);
//	}
//	assert(K <= MAXN);
	if (Check()) F();
//	++K;
	for (int i = n + 1; i; --i)
		if (v[i].size()/* > 1*/)
		{
//			if (i == y)
//			{
				for (int j = n + 1; j; --j)
					if (j != i/* && j != x */ && /*!vis[j][i]*/CHK(i, j, x, y) && v[j].size() < m)
					{
						v[j].push_back(v[i].back());
						v[i].pop_back();
						X[++K] = i;
						Y[K] = j;
//						vis[j][i] = 1;
//	if (K > MAXN - 10)
//	{
//		puts("QEAWRDFSAGB");
//		exit(0);
//	}
						dfs(i, j);
//						vis[j][i] = 0;
//						X[K] = Y[K] = 0;
						--K;
						v[i].push_back(v[j].back());
						v[j].pop_back();
					}
//			}
//			else
//			{
//				for (int j = n + 1; j; --j)
//					if (j != i && v[j].size() < m)
//					{
////						v[j].push_back(v[i].back());
////						v[i].pop_back();
////						X[++K] = i;
////						Y[K] = j;
////						dfs(i, j);
////						--K;
////						v[i].push_back(v[j].back());
////						v[j].pop_back();
//						v[j].push_back(v[i].back());
//						v[i].pop_back();
//						X[++K] = i;
//						Y[K] = j;
////	if (K > MAXN - 10)
////	{
////		puts("QEAWRDFSAGB");
////		exit(0);
////	}
//						dfs(i, j);
//						--K;
//						v[i].push_back(v[j].back());
//						v[j].pop_back();
//					}
//			}
		}
//	--K;
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; ++i)
	{
//		v[i].erase(v[i].begin(), v[i].end());
		for (int j = 1; j <= m; ++j)
		{
//			read(a[i][j]);
			int x;
			read(x);
			v[i].push_back(x);
		}
	}
//	puts("!!!!!!!!!!!!!!!!"), writeln(v[2].size());
//	for (int i = 1; i <= n + 1; ++i)
//	{
//		if (v[i].size() > n * m)
//		{
//			puts("ok");
//			exit(0);
//		}
//	}
	dfs();
//	F();
	return 0;
}
//g++ D:\submit\S5-023JS-0132\checker.cpp -o checker
//D:\submit\S5-023JS-0132\ball.in
//D:\submit\S5-023JS-0132\ball.out

