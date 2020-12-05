#include<bits/stdc++.h>

using namespace std;

struct alphabet
{
	int tot[30], num;
	
	void reset()
	{
		memset (tot, 0, sizeof(tot));
		num = 0;
	}
	
	void add(char x)
	{
		++tot[x - 'a'];
		if (tot[x - 'a'] & 1)
			++num;
		else --num;
	}
	
	void getalphabet(string s)
	{
		int len = s.size();
		for (int i = 0; i < len; ++i)
			add(s[i]);
	}
}alpha[1050000];

alphabet operator - (const alphabet &x, const alphabet &y)
{
	alphabet tmp;
	tmp.reset();
	for (int i = 'a' - 'a'; i <= 'z' - 'a'; ++i)
		tmp.tot[i] = x.tot[i] - y.tot[i], tmp.num += (tmp.tot[i] & 1);
	return tmp;
}

bool ok(string s, int sum, int pos)
{
	int t = pos / sum;
	for (int i = 1; i < t; ++i)
		for (int j = 0; j < sum; ++j)
			if (s[j + i * sum] != s[j + (i - 1) * sum])
				return false;
	return true;
}

int main(int argc, char *argv[])
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int ans = 0;
		string s;
		cin >> s;
		int len = s.size();
		alphabet tmp;
		tmp.reset();
		for (int i = 0; i < len; ++i)
			tmp.add(s[i]), alpha[i] = tmp;
		for (int i = len - 1; i > 1; --i)
		{
			int sqr = floor(sqrt(i));
			for (int j = 1; j <= sqr; ++j)
				if (i % j == 0)
				{
					if (j != 1 && ok(s, j, i))
						for (int k = 1; k < j; ++k)
						{
							alphabet C = alpha[len - 1] - alpha[i - 1], A = alpha[k - 1];
							if (C.num >= A.num)
								++ans;
						}
					int another = i / j;
					if (j * j != i && ok(s, another, i))
						for (int k = 1; k < another; ++k)
						{
							alphabet C = alpha[len - 1] - alpha[i - 1], A = alpha[k - 1];
							if (C.num >= A.num)
								++ans;
						}
				}
		}
		printf ("%d\n", ans);
	}
	return 0;
}
