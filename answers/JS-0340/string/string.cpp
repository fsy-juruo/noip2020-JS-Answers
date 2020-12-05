#include <bits/stdc++.h>
using namespace std;

int T, n, vis[30], v[30], cntl[1005], cntr[1005], ans;

inline int cale(string st)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < st.size(); ++i)
		++vis[st[i] - 'a' + 1];
	int sum = 0;
	for (int i = 1; i <= 26; ++i)
		if (vis[i] & 1) ++sum;
	return sum;
}

inline string sub(string st, int l, int r)
{
	string s = "";
	for (int i = l; i <= r; ++i)
		s += st[i];
	return s;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		memset(cntl, 0, sizeof(cntl));
		memset(cntr, 0, sizeof(cntr));
		ans = 0;
		string st, a, b, c, m, fin;
		cin >> st;
		n = st.size();
		st = ' ' + st;
		memset(v, 0, sizeof(v));
		for (int i = 1; i <= n; ++i)
		{
			cntl[i] = cntl[i - 1];
			++v[st[i] - 'a' + 1];
			if (v[st[i] - 'a' + 1] & 1) ++cntl[i];
			else --cntl[i];
		}
		memset(v, 0, sizeof(v));
		for (int i = n; i >= 1; --i)
		{
			cntr[i] = cntr[i + 1];
			++v[st[i] - 'a' + 1];
			if (v[st[i] - 'a' + 1] & 1) ++cntr[i];
			else --cntr[i];
		}
		for (int lc = 1; lc <= n - 2; ++lc)
		{
			c = sub(st, n - lc + 1, n);
			for (int la = 1; la < n - lc; ++la)
				if (cntl[la] <= cntr[n - lc + 1])
				{
					a = sub(st, 1, la);
					for (int lb = 1; lb <= n - la - lc; ++lb)
					{
						b = sub(st, la + 1, la + lb);
						m = a + b;
						int lm = la + lb, rest = n - lc, g;
						if (rest % lm) continue;
						g = rest / lm, fin = "";
						for (int i = 1; i <= g; ++i) fin += m;
						if (fin == sub(st, 1, rest)) ++ans;
					}
				}
		}
		printf("%d\n", ans);
	}
	return 0;
}

