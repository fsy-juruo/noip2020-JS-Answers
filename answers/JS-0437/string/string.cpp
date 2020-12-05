#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e3 + 10);

int t[110], f[maxn][maxn];
string s;
int cases;
int ans, cnt;

int main()
{
	// may use long long
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	
	cin >> cases;
	for (int times = 1; times <= cases; times++)
	{
		memset(t, 0, sizeof(t));
		memset(f, 0, sizeof(f));
		ans = 0;
		cin >> s;
		if (s.length() < 3)
		{
			cout << 0 << endl;
			continue;
		}
		t[s[0] - 'a'] = 1;
		cnt = 1;
		for (int i = 1; i <= s.length(); i++)
			f[0][i] = 1;
		for (int i = 1; i < s.length(); i++)
		{
			t[s[i] - 'a']++;
			if (t[s[i] - 'a'] % 2 == 0)
				cnt--;
			else
				cnt++;
			for (int j = 0; j <= s.length(); j++)
			{
				f[i][j] = f[i - 1][j];
				if (cnt <= j) f[i][j]++;
			}
		}
		memset(t, 0, sizeof(t));
		cnt = 0;
		for (int i = 1; i < s.length(); i++)
			t[s[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			if (t[i] % 2 == 1) cnt++;
		for (int i = 1; i < s.length() - 1; i++)
		{
			t[s[i] - 'a']--;
			if (t[s[i] - 'a'] % 2 == 0)
				cnt--;
			else
				cnt++;
			for (int j = 1; j * j <= i + 1; j++)
			{
				if ((i + 1) % j != 0) continue;
				int q = (i + 1) / j;
				bool flag;
				if (q != j && q != 1)
				{
					flag = true;
					for (int k = q; k <= i; k++)
						if (s[k] != s[k - q])
						{
							flag = false;
							break;
						}
					if (!flag) continue;
					ans += f[q - 2][cnt];
					//cout << i + 1 << " " << q << " " << cnt << " " << f[q - 2][cnt] << endl;
				}
				if (j != 1)
				{
					flag = true;
					for (int k = j; k <= i; k++)
						if (s[k] != s[k - j])
						{
							flag = false;
							break;
						}
					if (!flag) continue;
					ans += f[j - 2][cnt];
					//cout << i + 1 << " " << j << " " << cnt << " " << f[j - 2][cnt] << endl;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}

