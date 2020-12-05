#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxlen = 1048576;
int a[maxlen], num[maxlen];
string st;
ll ans, rec[maxlen][27];
bool f[26];

void get_kmp(string st)
{
	a[0] = 0;
	for (int i = 1; i < st.size(); i++)
	{
		int pos = a[i - 1];
		while (pos && (st[pos] != st[i]))
			pos = a[pos - 1];
		a[i] = (st[pos] == st[i]) ? pos + 1 : 0;
	}
}

ll func(int x, int k)
{
	if (x < 1)
		return 0;
	if (~rec[x][k])
		return rec[x][k];
	
	ll ret = 0;
	fill(f, f + 26, false);
	f[st[0] - 'a'] = true;
	int cur = 1;
	if (cur <= k)
		ret++;
	
	for (int i = 1; i < x; i++)
	{
		if (f[st[i] - 'a'])
		{
			f[st[i] - 'a'] = false;
			cur--;
		}
		else
		{
			f[st[i] - 'a'] = true;
			cur++;
		}
		
		if (cur <= k)
			ret++;
	}
	return rec[x][k] = ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> st;
		fill(f, f + 26, false);
		fill(rec[0], rec[0] + st.size() * 27, -1);
		ans = 0;
		num[st.size() - 1] = 1;
		f[st[st.size() - 1] - 'a'] = true;
		for (int i = st.size() - 2; i >= 0; i--)
		{
			if (f[st[i] - 'a'])
			{
				f[st[i] - 'a'] = false;
				num[i] = num[i + 1] - 1;
			}
			else
			{
				f[st[i] - 'a'] = true;
				num[i] = num[i + 1] + 1;
			}
		}
		get_kmp(st);
		
		for (int i = 1; i < st.size() - 1; i++)
		{
			int curlen = i + 1, k;
			if (curlen % (curlen - a[i]) != 0)
				k = 1;
			else
				k = curlen / (curlen - a[i]);
			
			ans += func(curlen / k - 1, num[i + 1]);
			for (int j = 1; j <= k / 2; j++)
			{
				if (k % j == 0)
					ans += func(curlen / j - 1, num[i + 1]);
			}
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

