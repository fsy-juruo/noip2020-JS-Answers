#include <cstdio>
const int N = 1e5+7;
int n, m;
int b[N][2];
inline int gcd (int a, int b)
{
	return b==0 ? a : gcd(b, a%b);
}
void add (int v, int f[2], int d)
{
	int e[2];
	e[0] = f[0], e[1] = f[1];
	e[1] *= d;
	if (b[v][1] == 0) b[v][0] = e[0], b[v][1] = e[1];
	else{
		int g = gcd (b[v][1], e[1]);
		b[v][1] *= e[1]/g;
		b[v][0] *= e[1]/g;
//	printf("xxx %d %d\n", b[v][1], g);
		b[v][0] += e[0]*b[v][1]/e[1];
	}
}
int main()
{
	freopen ("water.in", "r", stdin);
	freopen ("water.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		int v, d;
		scanf ("%d", &d);
		for (int j = 1; j <= d; ++j)
		{
			scanf ("%d", &v);
			if (i <= m) 
			{
				int e[2] = {1, 1};
				add (v, e, d);
			}
			else add (v, b[i], d);
//			printf ("00%d %d\n", b[v][0], b[v][1]);
		}
		if (d == 0) 
		{
			int g = gcd(b[i][0], b[i][1]);
			printf ("%d %d\n", b[i][0]/g, b[i][1]/g);	
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
