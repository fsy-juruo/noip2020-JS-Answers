#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20) + 7;
char ch[MAXN];
int sf[MAXN], sd[MAXN], hash1[27];
int s[MAXN][27];
int check(int l, int p)
{
	for (int i = l; i <= l + p - 1; i++)
	{
		int pos = i % p; if (pos == 0) pos = p;
		if (ch[i] != ch[pos]){
			return 0;
		} 
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	string st;
	while (T--)
	{
		cin >> st;
		int n = st.size(); int flag = 1;
		for (int i = 1; i <= n; i++)
			ch[i] = st[i - 1];
		for (int i = 1; i <= 26; i++)
			hash1[i] = 0;
		for (int i = 2; i <= n; i++)
			if (ch[i] != ch[i - 1])
			{
				flag = 0;
				break;
			}
		for (int i = 1; i <= n; i++)
		{
			int v = (int)(ch[i] - 'a' + 1);
			hash1[v]++;
			if (hash1[v] & 1) sf[i] = sf[i - 1] + 1;
			else sf[i] = sf[i - 1] - 1;
		}
		for (int i = 1; i <= 26; i++)
			hash1[i] = 0;
		for (int i = n; i >= 1; i--)
		{
			int v = (int)(ch[i] - 'a' + 1);
			hash1[v]++;
			if (hash1[v] & 1) sd[i] = sd[i + 1] + 1;
			else sd[i] = sd[i + 1] - 1;
		}  
		for (int i = 1; i <= n; i++)
		{			
			for (int j = 0; j <= 26; j++)
			{
				if (j == sf[i]) s[i][j] = 1;
				else s[i][j] = 0;
				s[i][j] += s[i - 1][j];	
			}
		}
		long long ans = 0;
		for (int j = 1; j <= 26; j++)
			s[1][j] += s[1][j - 1];
		if (flag == 1)
		{
			for (int i = 2; i < n; i++)
			{
				for (int j = 1; j <= 26; j++)
					s[i][j] += s[i][j - 1];	
				for (int j = 1; j <= n / i; j++)
				{
					if (i * j == n) break;
					ans += (long long)s[i - 1][sd[i * j + 1]];
				}
			}
			cout << ans << '\n';
			continue;
		}
		for (int i = 2; i < n; i++)
		{
			int l = i + 1;
			for (int j = 1; j <= 26; j++)
				s[i][j] += s[i][j - 1];	
			ans += (long long)s[i - 1][sd[i + 1]];
			while (l + i <= n && check(l, i))
			{
				ans += (long long)s[i - 1][sd[l + i]];
				l += i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

