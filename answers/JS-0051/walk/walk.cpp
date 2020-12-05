#include<bits/stdc++.h>
typedef long long ll;
#define K 15
#define N 500005

using namespace std;

template <class T>
inline void read(T &n)
{
	n = 0;
	bool f = false;
	char ch = getchar();
	while (!isdigit(ch))
		ch == '-' ? f = true, ch = getchar() : ch = getchar();
	while (isdigit(ch))
		n = n * 10 + (ch ^ '0'), ch = getchar();
	f ? n = -n : n = n;
}

const ll mod = 1000000007;
int n, k;
ll w[K], deltapos[N][K], maxdelta[K], mindelta[K], c[N], d[N], f[N][K], ans, cho[K], regcho[K];

bool isnonsense()
{
	for (int i = 1; i <= k; ++i)
		if (maxdelta[i] - mindelta[i] > w[i])
			return false;
	return true;
}

inline void subtask1(int dep)
{
	if (dep > k)
	{
		memcpy(regcho, cho, sizeof(cho));
		ll sum = 0;
		bool flag = true;
		ll pos = n;
		while (flag)
		{
			bool isright = true;
			while (isright)
			{
				for (int i = 1; i <= k; ++i)
					if (cho[i] + maxdelta[i] > w[i] || cho[i] + mindelta[i] < 1)
					{
						isright = false;
						break;
					}
				if (isright)
				{
					for (int i = 1; i <= k; ++i)
						cho[i] += deltapos[n][i];
					sum = (sum + n) % mod;
				}
			}
			for (int i = 1; i <= n && flag; ++i)
				for (int j = 1; j <= k; ++j)
					if (cho[j] + deltapos[i][j] > w[j] || cho[j] + deltapos[i][j] < 1)
					{
						flag = false;
						pos = i;
						break;
					}
			sum = (sum + pos) % mod;
			for (int i = 1; i <= k; ++i)
				cho[i] += deltapos[n][i];
		}
		ans = (ans + sum % mod);
		memcpy(cho, regcho, sizeof(regcho));
	}
	else for (int i = 1; i <= w[dep]; ++i)
	{
		cho[dep] = i;
		subtask1(dep + 1);
		cho[dep] = 0;
	}
}

int main(int argc, char *argv[])
{
	freopen ("walk.in", "r", stdin);
	freopen ("walk.out", "w", stdout);
	read(n), read(k);
	for (int i = 1; i <= k; ++i)
		read(w[i]);
	for (int i = 1; i <= n; ++i)
	{
		read(c[i]), read(d[i]);
		for (int j = 1; j <= k; ++j)
		{
			deltapos[i][j] = deltapos[i - 1][j];
			if (j == c[i])
				deltapos[i][j] += d[i];
			maxdelta[j] = max(maxdelta[j], deltapos[i][j]);
			mindelta[j] = min(mindelta[j], deltapos[i][j]);
		}	
	}
	bool flag = true;
	for (int i = 1; i <= k; ++i)
		if (deltapos[n][i] != 0)
		{
			flag = false;
			break;
		}
	if (flag && isnonsense())
	{
		puts("-1");
		return 0;
	}
	subtask1(1);
	printf ("%lld\n", ans);
	return 0;
}
