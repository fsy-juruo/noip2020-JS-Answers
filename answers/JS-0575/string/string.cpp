#include <bits/stdc++.h>
using namespace std;
int T;
string str;
unsigned long long ans;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		ans = 0;
		cin >> str;
		for (int j = 1; j < str.size() / 2; ++j) ans += ((str.size() + 1) / 2 - j + 1) * ((str.size() + 1) / 2 - j) / 2 + (str.size() / 2 - 1);
		ans += (str.size() / 2) * (str.size() / 2 + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}
