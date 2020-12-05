#include<bits/stdc++.h>
#define N 55
#define M 405
#define ASK 820005

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		n = n * 10 + (ch ^ '0'), ch = getchar();
}

int n, m, ansfrom[ASK], ansto[ASK], anstot;
stack <int> s[N];
map<int, int> copos;

int main(int argc, char *argv[])
{
	freopen ("ball.in", "r", stdin);
	freopen ("ball.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			int x;
			read(x);
			s[i].push(x);
		}
	int tot = 0, color = 0;
	while (tot < n)
	{
		color = s[n - tot].top();
		copos[color] = n - tot + 1;
		for (int i = n + 1; i >= 1; --i)
			while (!s[i].empty() && copos.count(s[i].top()))
			{
				if (copos[s[i].top()] == i || (int)s[copos[s[i].top()]].size() >= m)
					break;
				s[copos[color]].push(s[i].top());
				s[i].pop();
				ansfrom[++anstot] = i, ansto[anstot] = copos[color];
			}
		int pos = 1;
		while (!s[n - tot].empty())
		{
			if (copos.count(s[n - tot].top()) && (int)s[copos[color]].size() < m)
			{
				s[copos[color]].push(color);
				s[n - tot].pop();
				ansfrom[++anstot] = n - tot, ansto[anstot] = copos[color];
			}
			else
			{
				s[pos].push(s[n - tot].top());
				s[n - tot].pop();
				ansfrom[++anstot] = n - tot, ansto[anstot] = pos;
				while ((int)s[pos].size() == m || pos == n - tot)
					++pos;
			}
		}
		++tot;
	}
	printf ("%d\n", anstot);
	for (int i = 1; i <= anstot; ++i)
		printf ("%d %d\n", ansfrom[i], ansto[i]);
	return 0;
}
