#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int T, n;
#define maxn 1100007
string s, b, c, t[maxn];
#define ll long long
int a[30], sm[maxn][30];
ll f[maxn], r[maxn], ans;
vector <int> v[maxn];
void work ()
{
	cin >> s;
	n = s.size();
	c = "";
	for (int i = 0; i <= n - 1; i++)
	{
		c += s[i];
		t[i] = c;
	}
	b = "";
	for (int i = 0; i <= (n - 1) / 2 - 1; i++)
	{
		b += s[i];
		string x = b;
		int cnt = 1;
		if (i) for (int j = i + 1; j + i + 1 < n; j += i + 1, cnt++)
		{
			x += b;
			if (x != t[j + i])
				break;
		}
		f[i] = cnt;
	}
	int cnt = 0, x;
	for (int i = 0; i < 30; i++) a[i] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (!f[i]) f[i] = 1;
		x = s[i] - 'a';
		a[x]++;
		if (a[x] & 1) r[i] = r[i + 1] + 1;
		else r[i] = r[i + 1] - 1;
		for (int j = 0; j < 30; j++)
		{
			sm[i][j] = sm[i + 1][j];
			if (r[i] >= j) sm[i][j]++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (f[i] > 1)
		for (int j = 0; j < i; j++)
			for (int k = 2; k <= f[i]; k++)
				v[j].push_back ((i + 1) * k);
	}
	for (int i = 0; i < 30; i++) a[i] = 0;
	for (int i = 0; i < n - 2; i++)
	{
		x = s[i] - 'a';
		a[x]++;
		if (a[x] & 1) ++cnt;
		else --cnt;
		ans += sm[i + 2][cnt];
		for (int j = 0; j < v[i].size(); j++)
		ans += sm[v[i][j]][cnt];
	}
	cout << ans << endl;
}
int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		memset (f, 0, sizeof(f));
		memset (sm, 0, sizeof(sm));
		ans = 0;
		work();
		for (int i = 0; i < n; i++) v[i].clear();
	}
}
