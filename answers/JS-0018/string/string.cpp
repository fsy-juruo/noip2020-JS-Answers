#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = (1 << 20) + 5;
template <typename T> inline void rd(T &x)
{
	x = 0; int f = 1; char ch = 0;
	for(;!isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - 48;
	x *= f;
}
template <typename T> inline void wrote(T x)
{
	if(x < 0) {putchar('-'); wrote(-x); return;}
	if(x < 10){putchar(x + 48); return;}
	wrote(x / 10); putchar(x % 10 + 48);
}
template <typename T> inline void writeln(T x)
{
	wrote(x); puts("");
}

ll ans, f[N], rf[N];
ll hs[N];

void chk(string st, int pos)
{
	for(int i = 0; i < st.size() - 1; ++i)
	{
		if(f[i] <= rf[pos]) ++ans;
	}
}

void solve(string s)
{
	string ab = ""; ab += s[0];
	for(int i = 1; i < s.size() - 1; ++i)
	{
		ab = ab + s[i];
		chk(ab, i + 1);
		for(int j = i + 1; j + i + 1 < s.size(); j += i + 1)
		{
			bool flg = 1;
			for(int k = 0; k <= i; ++k)
			{
				if(s[j + k] != s[k])
				{
					flg = 0;
					break;
				}
			}
			if(flg == 0) break;
			chk(ab, j + i + 1);
		}
	}
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	rd(T);
	while(T--)
	{
		string str;
		cin >> str; ans = 0;
		memset(hs, 0, sizeof hs); rf[str.size()] = 0;
		for(int i = 0; i < str.size(); ++i)
		{
			++hs[str[i]];
			if(i == 0) {f[i] = 1; continue;}
			if(hs[str[i]] % 2 == 0) f[i] = f[i - 1] - 1;
			else f[i] = f[i - 1] + 1;
		}
		memset(hs, 0, sizeof hs);
		for(int i = str.size() - 1; i >= 0; --i)
		{
			++hs[str[i]];
			if(hs[str[i]] % 2 == 0) rf[i] = rf[i + 1] - 1;
			else rf[i] = rf[i + 1] + 1;
		}
		solve(str);
		writeln(ans);
	}
	return 0;
}

