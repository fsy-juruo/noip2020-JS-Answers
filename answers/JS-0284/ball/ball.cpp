#include <bits/stdc++.h>
using namespace std;

template <class T>
void read(T& x)
{
	x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
}

struct Node
{
	int a, b;	
}Res[820005];

stack <int> stk[3];

int n, m, num, ans, maxm[3], stk3;

void Print()
{
	printf("%d\n", ans);
	for (int i = 1; i <= ans; ++i)
		printf("%d %d\n", Res[i].a, Res[i].b);
}

void doit(int x)
{
	while (!stk[x].empty() && stk[x].top() == num)
	{
		++ans;
		stk[x].pop();
		++stk3;
		Res[ans].a = x;
		Res[ans].b = 3;
	}
}

void work(int x)
{
	while (!stk[x].empty() && stk[x].top() != num) 
	{
		++ans;
		stk[(x == 1) ? 2 : 1].push(stk[x].top());
		stk[x].pop();
		Res[ans].a = x;
		Res[ans].b = ((x == 1) ? 2 : 1);
	}
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	read(n); read(m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int x;
			read(x);
			if (stk[i].empty() || x == stk[i].top()) ++maxm[i];
			else maxm[i] = 1;
			stk[i].push(x);
		}
	}
	num = (maxm[1] > maxm[2]) ? stk[1].top() : stk[2].top();
	while (1)
	{
		doit(1);
		if (stk3 == m && (stk[1].size() == m || stk[2].size() == m))
		{
			Print();
			return 0;
		}
		doit(2);
		if (stk3 == m && (stk[1].size() == m || stk[2].size() == m))
		{
			Print();
			return 0;
		}
		work((stk[1].size() > stk[2].size()) ? 1 : 2);
	}
	return 0;
}

