#include <bits/stdc++.h>
using namespace std;
#define PROG "ball"
#define FILEIO 1
#define DEBUG 0

const int N=50, M=400;
int n, m;
int a[N+1][M+1], c[N+1][M+1];
int b[N+1];//b:ball counter 
// c:how many color#m on #n
// i=0 -> n+1

int bad()
{
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<=m; ++j)
		{
			if (i==j) continue;
			if (c[i][j]) return i;
		}
	}
	return 0;
}

const int K=820000;
int k, mx[K], my[K];

bool mv(int x, int y)
{
	if (b[y]>=m) return false;
	--c[x][a[x][b[x]]];
	--c[y][a[y][b[y]]];
	a[y][++b[y]]=a[x][b[x]--];
	mx[k]=x; my[k]=y; ++k;
#if DEBUG
	printf("$ mv: %d -> %d\n", x, y);
#endif
	return true;
}

void solve()
{
	int i, j, p;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; ++i)
	{
		b[i]=m;
		for (j=1; j<=m; ++j)
		{
			scanf("%d", &a[i][j]);
			++c[i][a[i][j]];
		}
	}
	int kill=0;
	while ((i=bad()))
	{
		++kill;
		if (kill>10) break;
#if DEBUG
		printf("$ bad %d\n", i);
#endif
		// throw bads until one good 
		while (a[i][b[i]]!=i)
		{
			// todo: use others than just 0
			for (j=0; j<=n; ++j)
			{
				if (i==j) continue;
				if (mv(i, j)) break;
			}
		}
		// search needs
		for (j=1; j<=n; ++j)
		{
			if (i==j) continue;
			if (c[j][i])
			{
				while (a[j][b[j]]!=i)
				{
					for (p=0; p<=n; ++p)
					{
						if (j==p) continue;
						if (mv(j, p)) break;
					} 
				}
				// *==i
				for (p=0; p<=n; ++p)
				{
					if (j==p) continue;
					if (mv(j, p)) break;
				}
				break;
			}
		}
	}
	while (b[0])
	{
		if (!mv(0, a[0][b[0]])) break;
	}
	printf("%d\n", k);
	for (i=0; i<k; ++i)
	{
		printf("%d %d\n", mx[i]?mx[i]:n+1, my[i]?my[i]:n+1);
	}
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
