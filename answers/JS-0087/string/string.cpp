#include<bits/stdc++.h>

#define N 1200000
#define INF 0x3f3f3f3f
#define int long long

using namespace std;

int T, n, ans, v[1005][1005];
char c[N], s[N];
int vis[26];
bool f;

void pre()
{
	for(int i = 1; i <= n; ++ i)
	{
		memset(vis, 0, sizeof(vis));
		for(int j = i; j <= n; ++ j)
		{
			vis[c[j] - 'a'] ++;
			v[i][j] = v[i][j - 1] + (vis[c[j] - 'a'] % 2) * 2 - 1;
		}
	}
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		f = 1; ans = 0;
		scanf("%s", c + 1);
		n = strlen(c + 1);
		for(int i = 2; i <= n; ++ i)
			if(c[i] != c[i - 1]) f = 0;
		if(f)
		{
			if(n % 2)
			{
				for(int i = 2; i < n; i += 2)
					ans += (i - 1) * ((n - i) / i + ((n - i) % i > 0));
				for(int i = 3; i < n; i += 2)
					ans += (i - 1) / 2 * ((n - i) / i + ((n - i) % i > 0));
				for(int i = 6; i < n; i += 4)
					ans += (i / 4) * ((n - i) / i + ((n - i) % i > 0));
			}
			else
			{
				for(int i = 2; i < n; i += 2)
					ans += (i - 1) / 2 * ((n - i) / i + ((n - i) % i > 0));
				for(int i = 3; i < n; i += 2)
					ans += (i - 1) * ((n - i) / i + ((n - i) % i > 0));
				for(int i = 6; i < n; i += 4)
					ans -= (i / 4) * ((n - i) / i + ((n - i) % i > 0));
			}
			printf("%lld\n", ans);
			continue;
		}
		pre();
		for(int i = 2; i < n; ++ i)
		{
			int kmax;
			for(int k = 1; k * i < n; ++ k)
			{
				bool flag = 1;
				for(int kk = (k - 1) * i + 1; kk <= k * i; ++ kk)
					if(c[kk] != c[kk - (k - 1) * i])
						{flag = 0; break;}
				if(!flag) break;
				kmax = k;
			}
			for(int j = 1; j < i; ++ j)
			{
				int n1 = v[1][j];
				for(int k = 1; k <= kmax; ++ k)
				{
					int n2 = v[k * i + 1][n];
					if(n1 <= n2) ++ ans; 
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
