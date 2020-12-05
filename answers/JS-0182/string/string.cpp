#include <bits/stdc++.h>
#define LL long long
using namespace std;

string s;

int vis[1500005], vis2[1500005];

int main()
{	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	cin >> T;
	while (T--)
	{
		memset(vis, 0, sizeof(vis));
		int Ans = 0;
		cin >> s;
		int len = s.size() - 1;
		string A = "";
		A = A + s[0];
		vis[s[0] - 96]++;
		int SumA = 1;
		for (int i = 1; i <= len - 1; i++)
		{
			for (int j = i; j <= len - 1; j++)
			{
				string B = "";
				for (int S = i; S <= j; S++)
				 	B = B + s[S];
				string p = A + B;
				int SumC = 0;
				memset(vis2, 0, sizeof(vis2));
				for (int k = j + 1; k <= len; k++)
				{
					vis2[s[k] - 96]++;
					if (vis2[s[k] - 96] & 1) SumC++;
					else SumC--;
				}
				if (SumA <= SumC) Ans++;
				for (int G = p.size(); G < len; G += p.size())
				{
					int to = G + p.size() - 1;
					if (to >= len) break;
					string sp = "";
					for (int S = G; S <= to; S++)
						sp = sp + s[S];
					if (sp == p)
					{
						memset(vis2, 0, sizeof(vis2));
						SumC = 0;
						for (int k = to + 1; k <= len; k++)
						{
							vis2[s[k] - 96]++;
							if (vis2[s[k] - 96] & 1) SumC++;
							else SumC--;
						}
						if (SumA <= SumC) Ans++;
					}	
					else break;
				}
			}
			A = A + s[i];
			vis[s[i] - 96]++;
			if (vis[s[i] - 96] & 1) SumA++;
			else SumA--;
		}
		cout << Ans << endl;
	}
	return 0;
}

