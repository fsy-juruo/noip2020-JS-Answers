#include <iostream>
#include <cstdio>

const int baka = 9;
int n, k, w[11], P[11], ans, a[11];

struct Step
{
	int c, d;
}s[500009];

int read()
{
	char ch = getchar();
	int figure = 0, flag = 1;
	while((ch < '0'||ch > '9') && ch != '-')
	{
		ch = getchar();
	}
	if(ch == '-')
	{
		flag = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9')
	{
		figure = (figure<<3) + (figure<<1) + ch - '0';
		ch = getchar();
	}
	return figure * flag;
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read();
	k = read();
	for (register int i = 1; i <= k; ++i)
	{
		w[i] = read();
		P[i] = 1;
	}
	for (register int i = 1; i <= n; ++i)
	{
		s[i].c = read();
		s[i].d = read();
	}
	P[k] = 0;
	while(9 == baka)
	{
		++P[k];
		for (register int i = k; i >= 2; --i)
		{
			if(P[i] > w[i])
			{
				P[i] = 1;
				++P[i - 1];
			}
		}
		if(P[1] > w[1])
		{
			break;
		}
		for (register int i = 1; i <= k; ++i)
		{
			a[i] = P[i];
		}
		int next = 1;
		while (9 == baka)
		{
			++ans;
			if(ans == 1000000007)
			{
				ans = 0;
			}
			a[s[next].c]+=s[next].d;
			if (a[s[next].c] < 1||a[s[next].c] > w[s[next].c])
			{
				break;
			}
			++next;
			if (next == n + 1)
			{
				bool flandre = 0;
				for (register int i = 1; i <= k; ++i)
				{
					if(a[i] != P[i])
					{
						flandre = 1;
						break;
					}
				}
				if(!flandre)
				{
					printf("-1");
					return 0;
				}
				next = 1;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

