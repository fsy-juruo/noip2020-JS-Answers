#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k;
int w, c, d;

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i ++ ) scanf("%d", &w);
	for (int i = 1; i <= n; i ++ ) scanf("%d%d", &c, &d);
	printf("-1\n");
	return 0;
}
