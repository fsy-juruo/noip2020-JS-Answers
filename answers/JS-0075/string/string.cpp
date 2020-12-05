#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline ll read()
{
	ll s = 0, f = 0;
	char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

inline void write(ll x)
{
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

inline string reads()
{
	string ss = "";
	char ch = getchar();
	while (!islower(ch)) ch = getchar();
	while (islower(ch)) ss += ch, ch = getchar();
	return ss;
}

bool mp1[1010], mp2[1010];
string tmps;
ll pos;
ll cnt, cnt2, cnt3, cnt4;
ll t;
string s;
bool flag;
ll ans;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	t = read();
	while (t--)
	{
		s = reads();
		ll l = s.size();
		tmps = "";
		tmps += s[0];
		ans = 0;
		for (int i = 1; i < l - 1; i++)
		{
			memset(mp1, 0, sizeof(mp1));
			memset(mp2, 0, sizeof(mp2));
			tmps += s[i];
			pos = i;
			cnt = 1;
			flag = false;
			for (int j = 0; j <= i; j++)
			{
				pos++;
				if (s[pos] == tmps[j]) 
				{
					if (j == i)
					{
						cnt++;
						j = -1;
					}
					if (pos == l - 1)
					{
						if (j < i) pos -= j + 1;
						break;
					}
					continue;
				}
				else 
				{
					flag = false;
					pos -= j + 1;
					break;
				}
			}
			cnt2 = 0;
			if (pos == l - 1)
			{
				cnt--;
				pos -= i + 1;
				for (int j = 0; j <= i; j++)
				{
					if (mp1[tmps[j]])
					{
						cnt2--;
					}
					else
					{
						cnt2++;
					}
					mp1[tmps[j]] = !mp1[tmps[j]];
				}
			}
			else
			{
				for (int j = pos + 1; j < l; j++)
				{
					if (mp1[s[j]])
					{
						cnt2--;
					}
					else
					{
						cnt2++;
					}
					mp1[s[j]] = !mp1[s[j]];
				}
			}
			cnt3 = 0;
			if (cnt > 1)
			{
				cnt3 = cnt2;
				for (int j = 0; j <= i; j++)
				{
					if (mp1[tmps[j]])
					{
						cnt3--;
					}
					else
					{
						cnt3++;
					}
					mp1[tmps[j]] = !mp1[tmps[j]];
				}
			}
			cnt4 = 0;
			for (int j = 0; j < i; j++)
			{
				if (mp2[tmps[j]])
				{
					cnt4--;
				}
				else
				{
					cnt4++;
				}
				if (cnt4 <= cnt2)
				{
					ans += (cnt - 1) / 2 + 1;
				}
				if (cnt4 <= cnt3)
				{
					if (cnt >= 2)
					{
						ans += (cnt - 2) / 2 + 1;
					}
				}
				mp2[tmps[j]] = !mp2[tmps[j]];
			}
		}
		write(ans), puts("");
	}
	return 0;
}

/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
