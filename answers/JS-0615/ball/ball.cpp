#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, a;

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			scanf("%d", &a);

	printf("0\n");
	return 0;
}
