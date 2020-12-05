#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 20) + 5;

int T, n, a[N], ans;
string str;

int lowbit(int x) { return x & (-x); }

int calc(int x)
{
	int cnt = 0;
	while (x)
	{
		++cnt;
		x -= lowbit(x);
	}
	return cnt;
}

void mor(int L, int x)
{
	for (int j = 1; j < L; ++j)
		if (calc(a[j]) <= x)
		{
			++ans;	
		}
}

void work(int Cs, int cir)
{
	int numC = calc(a[n] ^ a[Cs - 1]);
	int gs = (Cs - 1) / cir;
	for (int i = 1; i * i <= gs; ++i)
	{
		if (gs % i != 0) continue;
		mor(i * cir, numC);
		if (i * i != gs) mor(cir * (gs / i), numC);
	}
}

bool judge(int i, int j)
{
	if ((i - 1) % j != 0) return 0;
	int k = j + 1;
	while (1)
	{
		for (int cnt = 1; cnt <= j; ++cnt, ++k)
			if (str[cnt] != str[k]) return 0;
		if (k == i) return 1;
	}
}

void solve()
{
	ans = 0;
	memset(a, 0, sizeof(a));
	cin >> str;
	n = str.size();
	str = '#' + str;
	for (int i = 1; i <= n; ++i)
		a[i] = a[i - 1] ^ (1 << (str[i] - 97));
	for (int i = n; i >= 3; --i)
	{
		bool pd = 1;
		for (int j = 1; j <= (i - 1) / 2; ++j)
		{
			if (judge(i, j))
			{
				work(i, j);
				pd = 0;
				break;
			}
		}
		if (pd)
		{
			work(i, i - 1);
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	while (T--) solve();
	return 0;
}

