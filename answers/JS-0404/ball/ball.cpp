#include <cstdio>
int n, m, ans, an[820007][2];
int d[57][407];
void sw (int a, int w, int b, int st, int ig)
{
	int p = 0, we = w, wwe = w;
	if (st - we -1 > 0)
	{
		for (int i = m; i > we; --i)
		{
			an[ans][0] = a, an[ans++][1] = n+1;
			d[n+1][++p] = d[a][i];	
	//		printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		for (int i = m; i >= st+ig; --i)
		{
			an[ans][0] = b, an[ans++][1] = a;
			d[a][++we] = d[b][i];
	//			printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		if (p+ig >= m)
		{
			for (int i = p; i > m-ig; --i)
			{
				an[ans][0] = n+1, an[ans++][1] = a;
				d[a][++we] = d[n+1][p--];
	//				printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
			}
		}
		for (int i = st; i < st+ig; ++i)
		{
			an[ans][0] = b, an[ans++][1] = n+1;
			d[n+1][++p] = d[b][i];
	//			printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		int wee = we;
		for (int i = wwe+1; i <= wee; ++i)
		{
			an[ans][0] = a, an[ans++][1] = b;
			d[b][st++] = d[a][we--];
	//			printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		for (int i = p; i > p-ig; i--)
		{
			an[ans][0] = n+1, an[ans++][1] = a;
			d[a][++wwe] = d[n+1][i];
	//			printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		p -= ig;
		for (int i = p; i > 0; --i)
		{
			if (wwe < m) 
			{
				an[ans][0] = n+1, an[ans++][1] = a;
				d[a][++wwe] = d[n+1][i];
			}
			else
			{
				an[ans][0] = n+1, an[ans++][1] = b;
				d[b][st++] = d[n+1][i];
			}
	//			printf ("%d %d\n", an[ans-1][0], an[ans-1][1]);
		}
		return ;
	}
	for (int i = m; i >= st; --i)
	{
		an[ans][0] = b, an[ans++][1] = n+1;
		d[n+1][++p] = d[b][i];
	}
	for (int i = m; i > we; --i)
	{
		an[ans][0] = a, an[ans++][1] = b;
		d[b][st++] = d[a][i];
	}
	for (int i = p; i > p-ig; --i)
	{
		an[ans][0] = n+1, an[ans++][1] = a;
		d[a][++we] = d[n+1][i];
	}
	for (int i = p-ig; i > 0; --i)
	{
		if (we < m) 
		{
			an[ans][0] = n+1, an[ans++][1] = a;
			d[a][++we] = d[n+1][i];
		}
		else
		{
			an[ans][0] = n+1, an[ans++][1] = b;
			d[b][st++] = d[n+1][i];
		}
	}
}
int main()
{
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf ("%d", &d[i][j]);
	for (int i = 1; i <= n; ++i)
	{
		int we = 0, ig = 1;
		while (d[i][we+1] == i) ++we;
		for (int j = i+1; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
				if (d[j][k] == i)
				{
					while (d[j][k+ig] == i) ++ig;
					sw (i, we, j, k, ig);
					we += ig;
					if (we == m) break;
				}
			if (we == m) break;
		}
	}
	printf ("%d\n", ans);
	for (int i = 0; i < ans; ++i)
	{
		printf ("%d %d\n", an[i][0], an[i][1]);
	}
	return 0;
}
