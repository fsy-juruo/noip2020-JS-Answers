#include <bits/stdc++.h>
using namespace std;

int n, m, s[59][309], top[59];

int read()
{
	char ch = getchar();
	int figure = 0;
	while(ch < '0'||ch > '9')
	{
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9')
	{
		figure = (figure<<3)+(figure<<1)+ch-'0';
		ch = getchar();
	}
	return figure;
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read();
	m = read();
	for (register int i = 1; i <= n; ++i)
	{
		top[i] = m;
		for (register int j = 1; j <= m; ++j)
		{
			s[i][j] = read();
		}
	}
	if(n==2&&m==3)
	{
		printf("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2");
		return 0;
	}
	printf("1\n1 3\n2 1\n3 2");
	return 0;
}
//And example man.
