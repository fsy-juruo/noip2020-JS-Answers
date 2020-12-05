#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
void read(T &x) // unsigned
{
	x = 0;
	char c;
	while (!isdigit(c = getchar()));
	x = (c ^ 48);
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
}
const int N = 1050000;
char c[N];
int n, cur, bst[N], mn[N], h[N];
bool f[26];int F[N];
int cnt[27];
void solve()
{
	ll ans = 0;
	memset(bst, 0, sizeof(bst));
	memset(mn, 0, sizeof(mn));
	memset(h, 0, sizeof(h));
	memset(f, 0, sizeof(f));
	memset(F, 0, sizeof(F));
	memset(cnt, 0, sizeof(cnt));
	scanf("%s", c + 1);
	n = strlen(c + 1);
	--n;
	cur = 1;
	bst[1] = mn[1] = 1;
	int i = 2, j;
	while (i <= n)
	{
		j = 1;
		while (j <= cur && i <= n && c[i] == c[j]) bst[i] = j, ++i, ++j;
		if (j == 1)
		{
			cur = bst[i] = mn[i] = i;
			++i;
		}
		else if (j <= cur)
		{
			for (int k = 1;k < j;++k)
			{
				mn[i - k] = i - k;
			}
			cur = i - 1;
		}
		else
		{
			mn[i - 1] = cur;
			for (int k = 2;k <= cur;++k)
			{
				mn[i - k] = i - k;
			}
		}
	}
	/*for (int i = 1;i <= n;++i)
	{
		cout << bst[i] << " ";
	}
	cout << endl;
	for (int i = 1;i <= n;++i)
	{
		cout << mn[i] << " ";
	}
	cout << endl;*/
	for (int i = 1;i <= n;++i)
	{
		++h[mn[i]];
	}
	for (int i = 1;i <= n;++i)
	{
		if (mn[i] != i)
		{
			h[i] = h[mn[i]] / (i / mn[i]);
		}
	}
	/*for (int i = 1;i <= n;++i)
	{
		cout << h[i] << " ";
	}
	cout << endl;*/
	++n;
	for (int i = 1;i <= n;++i)
	{
		if ((f[c[i] - 'a'] ^= 1) & 1) F[i] = F[i - 1] + 1;
		else F[i] = F[i - 1] - 1;
	}
	F[0] = F[n];
	++cnt[F[1]];
	if ((f[c[1] - 'a'] ^= 1) & 1) F[1] = F[0] + 1;
	else F[1] = F[0] - 1;
	int p, q;
	for (int i = 2;i < n;++i)
	{
		int tmp = F[i];
		p = 0, q = 0;
		if ((f[c[i] - 'a'] ^= 1) & 1) F[i] = F[i - 1] + 1;
		else F[i] = F[i - 1] - 1;
		for (int j = 0;j <= F[i];++j)
		{
			p += cnt[j];
		}
		for (int j = 0;j <= F[n];++j)
		{
			q += cnt[j];
		}
		ans += (ll)((h[i] + 1) / 2) * p;
		ans += (ll)((h[i] / 2)) * q;
		++cnt[tmp];
	}
	printf("%lld\n", ans);
}
int main()
{
	//time_t start_time = clock();
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//ios::sync_with_stdio(0);
	int T;
	read(T);
	while (T--) solve();
	//cerr << "Time used: " << clock() - start_time << endl;
	return 0;
}

