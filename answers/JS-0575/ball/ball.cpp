#include <bits/stdc++.h>
using namespace std;
inline short read()
{
	short X = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {X = (X << 3) + (X << 1) + (ch ^ 48); ch = getchar();}
	return X;
}
inline void write(int X)
{
	if (X == 0) {putchar('0'); return;}
	short cnt = 0, num[21];
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) putchar(num[cnt--] ^ 48);
	return;
}
vector < map< short, short > >colorset;
vector < stack < short > > ball;
vector <short> qf, qt;
short n, m;
short a;
inline void putl(short x)
{
	qf.push_back(x); qt.push_back(1);
	ball[1].push(ball[x].top());
	++colorset[1][ball[x].top()];
	--colorset[x][ball[x].top()];
	ball[x].pop();
	return;
}
inline void putr(short x)
{
	qf.push_back(x); qt.push_back(n + 1);
	ball[n + 1].push(ball[x].top());
	++colorset[n + 1][ball[x].top()];
	--colorset[x][ball[x].top()];
	ball[x].pop();
	return;
}
inline void putrn(short x)
{
	qf.push_back(x); qt.push_back(n);
	ball[n].push(ball[x].top());
	++colorset[n][ball[x].top()];
	--colorset[x][ball[x].top()];
	ball[x].pop();
	return;
}
inline void putanswer()
{
	write(qf.size()); putchar('\n');
	for (int i = 0; i < qf.size(); ++i)
	{
		write(qf[i]); putchar(' '); write(qt[i]); putchar('\n');
	}
	return;
}
int main()
{	
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read(); m = read();
	colorset.resize(n + 2);
	ball.resize(n + 2);
	for (short i = 1; i <= n; ++i)
	{
		for (short j = 1; j <= m; ++j)
		{
			a = read();
			++colorset[i][a];
			ball[i].push(a);
		}
	}
	for (; n > 1; --n)
	{
		for (int i = 1; i < n; ++i)
		{
			while (colorset[i][n])
			{
				if (ball[i].top() == n) putr(i);
				else putrn(i);
			}
		}
		while (ball[n].size())
		{
			if (ball[n].top() == n) putr(n);
			else putl(n);
		}
	}
//	n = 2;
//	while (ball[1].size())
//	{
//		if (ball[1].top() == 1) putrn(1);
//		else putr(1);
//	}
//	for (int i = ball[3].size(); i > m; --i) putl(3);
	putanswer();
	return 0;
}
