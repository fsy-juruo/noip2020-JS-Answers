#include <bits/stdc++.h>
using namespace std;
struct chu
{
	short g;
	int nt[6];
}c[100010];
struct fs
{
	int z;
	int m;
}wr[100010];
int jin[11], cu[100010], n, m, ot;
int gcd(int a, int b)
{
	if (b == 0)
	{
	    return a;
	}
	return gcd(b, a % b);
}
int yue1(int a, int b)
{
	return a / gcd(a, b);
}
int yue2(int a, int b)
{
	return b / gcd(a, b);
}
int jia1(int a, int b, int c, int d)
{
	if (a * d + b * c > INT_MAX / 5 or b * d > INT_MAX / 5)
	    return yue1(a * d + b * c, b * d);
	return a * d + b * c;
}
int jia2(int a, int b, int c, int d)
{
	if (a * d + b * c > INT_MAX / 5 or b * d > INT_MAX / 5)
	    return yue2(a * d + b * c, b * d);
	return b * d;
}
void dfs(int w, int zi, int mu)
{
	wr[w].z = jia1(wr[w].z, wr[w].m, zi, mu);
	wr[w].m = jia2(wr[w].z, wr[w].m, zi, mu);
	if (c[w].g == 0)
	{
		return;
	}
	for (short i = 1; i <= c[w].g; i++)
	{
		dfs(c[w].nt[i], zi, mu * c[w].g);
	}
}
int main()
{
  	freopen("water.in", "r", stdin);
  	freopen("water.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i].g;
		for (int j = 1; j <= c[i].g; j++)
		{
		    cin >> c[i].nt[j];	
		}
		if (c[i].g == 0)
		{
		    cu[++ot] = i;	
		}
	}
	for (int i = 1; i <= m; i++)
	{
		jin[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		wr[i].m = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		dfs(jin[i], 1, 1);
	}
	for (int i = 1; i <= ot; i++)
	{
	    printf("%d %d", yue1(wr[cu[i]].z, wr[cu[i]].m), yue2(wr[cu[i]].z, wr[cu[i]].m));
	    cout << endl;
	}
	return 0;
}
