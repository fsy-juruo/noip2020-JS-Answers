#include<bits/stdc++.h>
using namespace std;
int g[410][52], r[52];
inline int siz(int u)
{return r[u];}
inline void push(int u, int d)
{ ++r[u]; g[r[u]][u] = d;}
inline void pop(int u)
{ --r[u]; return;}
inline int top(int u)
{ return g[r[u]][u];}
inline bool sm(int u)
{
	bool re = true;
	for(int i = 2; i <= siz(u); ++i)
		re &= (g[i][u] == g[i-1][u]);
	return re;
}
bool flg = true;
int x[100000], y[100000], cnt = 0;
int n, m;
void dfs(int d, int s)
{
	if(d > s) return;
	bool f = true;
	for(int i = 1; i <= n; ++i)
		f &= sm(i);
	if(f)
	{
		printf("%d\n", cnt);
		for(int i = 0; i < cnt; ++i)
			printf("%d %d\n", x[i], y[i]);
		flg = false;
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			if(siz(i) && siz(j)!= m)
			{
				push(j, top(i));
				pop(i);
			}
			x[cnt++] = i, y[cnt++] = j;
			dfs(d+1, s);
			if(flg)
			{
				--cnt;
				push(i, top(j));
				pop(j);
			}
		}
	
}
int main(void)
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			int c; scanf("%d", &c);
			push(i, c);
		}
	for(int i = 81; flg && i <= 810000; i *= 10)
		dfs(0, i);
	return 0;
}
