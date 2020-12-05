#include <bits/stdc++.h>
using namespace std;

template < typename T >
inline void read(T &x)
{
	x = 0;
	bool flg = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57)
		flg |= c == '-';
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
	if (flg) x = -x;
}

int OUTPUT[45];

template < typename T >
inline void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int len = 0;
	do
	{
		OUTPUT[++len] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (len)
		putchar(OUTPUT[len--]);
}

template < typename T >
inline void writesp(T x)
{
	write(x);
	putchar(32);
}

template < typename T >
inline void writeln(T x)
{
	write(x);
	putchar(10);
}

const int N = 1e5 + 5;
int n, m, front, rear/*, in[N]*/;
pair < long long, long long > ans[N];
vector < int > G[N];

struct node
{
	int Id;
	pair < long long, long long > x;
	
	inline node()
	{
		
	}
	
	inline node(int _Id, pair < long long, long long > _x)
	{
		Id = _Id;
		x = _x;
	}
}q[N * 20];

inline pair < long long, long long > Add(pair < long long, long long > x, pair < long long, long long > y)
{
	long long num = x.second / __gcd(x.second, y.second) * y.second;
	x.first *= (num / x.second);
	y.first *= (num / y.second);
	x.first += y.first;
	long long g = __gcd(x.first, num);
	x.first /= g;
	num /= g;
	return make_pair(x.first, num);
}

inline pair < long long, long long > Div(pair < long long, long long > x, long long y)
{
	x.second *= y;
	long long g = __gcd(x.first, x.second);
	x.first /= g;
	x.second /= g;
	return x;
}

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
//	pair < long long, long long > NUM = Add(make_pair(1, 2), make_pair(1, 6));
//	writesp(NUM.first), writeln(NUM.second);
//	pair < long long, long long > NUM = Div(make_pair(2, 3), 5);
//	writesp(NUM.first), writeln(NUM.second);
//	return 0;
	read(n);
	read(m);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		read(x);
		for (int j = 1; j <= x; ++j)
		{
			int y;
			read(y);
			G[i].push_back(y);
		}
	}
	for (int i = 1; i <= n; ++i)
		ans[i] = make_pair(0, 1);
	front = 1;
	rear = m;
	for (int i = 1; i <= m; ++i)
		q[i] = node(i, make_pair(1, 1));
	while (front <= rear)
	{
		ans[q[front].Id] = Add(ans[q[front].Id], q[front].x);
		int len = G[q[front].Id].size();
		if (len)
		{
			pair < long long, long long > num = Div(q[front].x, len);
			for (int i = 0; i < len; ++i)
			{
//				int tId = G[q[front].Id][i];
				q[++rear] = node(G[q[front].Id][i], num);
			}
		}
		++front;
	}
	for (int i = 1; i <= n; ++i)
		if (!G[i].size()) writesp(ans[i].first), writeln(ans[i].second);
	return 0;
}

