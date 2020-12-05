#include <bits/stdc++.h>
//#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast")
using namespace std;

template < typename T >
inline void read(T &x)
{
	x = 0;
	bool flg = 0;
	char c;
	while ((c = getchar()) < 48 || c > 57)
		flg |= c == '-';
	do
		x = (x << 1) + (x << 3) + (c ^ 48);
	while ((c = getchar()) > 47 && c < 58);
	if (flg) x = -x;
}

int OUTPUT[45];

template < typename T >
inline void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	int len = 0;
	do
	{
		OUTPUT[++len] = x % 10 | 48;
		x /= 10;
	}while (x);
	while (len)
		putchar(OUTPUT[len--]);
}

template < typename T >
inline void writesp(T x)
{
	write(x);
	putchar(32);
}

template < typename T >
inline void writeln(T x)
{
	write(x);
	putchar(10);
}

const int N = (1 << 20) + 5;
int T, n, c[N][30]/*, b[30], lst[N], Id[30], cnt[30]*/, jishu[N], jishu2[N], t[N];
char s[N];
long long ans;
//vector < int > fac[N];
//vector < int > G[N], v;

inline int lowbit(int x)
{
	return x & (-x);
}

inline void Update(int x)
{
//	if (!x) x = 1;
	while (x <= n)
	{
		++t[x];
		x += lowbit(x);
	}
}

inline int Query(int x)
{
	int ret = 0;
	while (x)
	{
		ret += t[x];
		x -= lowbit(x);
	}
	return ret;
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	for ( char i = 'a'; i <= 'z'; ++i)
//		writeln(i - 96);
//	return 0;
	read(T);
	while (T--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
//		writeln(n);
//		writeln(n);
//		memset(c, 0, sizeof(c));
//		memset(jishu, 0, sizeof(jishu));
//		memset(jishu2, 0, sizeof(jishu2));
		ans = 0;
//		memset()
		for (int i = 1; i <= n; ++i)
		{
			t[i] = 0;//Çå¿Õ 
			for (int j = 1; j <= 26; ++j)
				c[i][j] = c[i - 1][j];
			++c[i][s[i] - 96];
			jishu[i] = 1;
			for (int j = 1; j <= 26; ++j)
				if (c[i][j] & 1) ++jishu[i];
//			++jishu[i];
//			G[i].erase(G[i].begin(), G[i].end());
//			for ( int j = 1; j <= 26; ++j)
//				++ccccccccccccccccccccccccccccccccccccccccccccc
//				if (c[i][j] & 1) G[i].push_back(j);
		}
		for (int i = n; i; --i)
		{
			jishu2[i] = 1;//!!!!!!!!!!!!!!!!!!!!!
			for (int j = 1; j <= 26; ++j)
				if ((c[n][j] - c[i - 1][j]) & 1) ++jishu2[i];
		}
//		for ( int i = 1; i <= n; ++i)
//			writesp(jishu[i]), writeln(jishu2[i]);
//		for ( int i = 1; i <= n; ++i)
//			;
//		for ( int i = n; i; --i)
//		{
//			v.erase(v.begin(), v.end());
//			for ( int j = 1; j <= 26; ++j)
//				b[j] = c[n][j] - c[i - 1][j];
//			for ( int j = 1; j <= 26; ++j)
//				if (b[j] & 1) v.push_back(j);
//			
//		}
//		memset(Id, 0, sizeof(Id));
//		memset(lst, 0, sizeof(lst));
//		for ( int i = 1; i <= n; ++i)
//		{
//			lst[i] = Id[s[i] - 96];
//			Id[s[i] - 96] = i;
////			writeln(lst[i]);
//		}
//		for ( int i = 1; i <= n; ++i)
//			;
//		for ( int i = n; i; --i)
//		{
////			for ( int j = 1; j <= 26; ++j)
////				cnt[j]
//			++cnt[s[i]];
//			int num = 0;
//			for ( int j = 1; j <= 26; ++j)
//				if (cnt[j] & 1) ++num;
//			for ( int j = 1; j < i; ++j)
//			{
//				int tmp = 0;
//				for ( int k = 1; k <= 26; ++k)
//					if (c[j][k] & 1) ++tmp;
//				if (tmp < num)
//				{
//				
//				}
//			}
//		}
//		for ( int i = 1; i <= n; ++i)//A
			for (int j = 1; j < n; ++j)//B
			{
				for (int /*o = 1, */k = j + 1, l = j + 1; /*(k = j * o + 1)*/k <= n; /*++o*/k += j)
				{
//					if (jishu[i] <= jishu2[k] && !((k - 1) % j))
//					{
//						int l1 = j;
//						if (!())
//						if (i == 1 && j == 3) puts("ok"), writeln(k);
						for (; l < k; ++l)
							if (s[l] != s[l - j]) goto End;
						ans += Query(jishu2[k]);
//						for ( int i = 1; i < j; ++i)
//							if (jishu[i] <= jishu2[k]) ++ans;
//						++ans;
//						writesp(i), writesp(j), writeln(k);
						End:;
//					}
				}
				Update(jishu[j]);
			}
		writeln(ans);
	}
	return 0;
}
/*
100
aaaaaaaaaaaaaaaaaaaa
156
aaaaaaaaaaaaaaaaaaa
179
aaaaaaaaaaaaaaaaaa
123
aaaaaaaaaaaaaaaaa
138
aaaaaaaaaaaaaaaa
96
aaaaaaaaaaaaaaa
102
aaaaaaaaaaaaaa
67
aaaaaaaaaaaaa
76
aaaaaaaaaaaa
46
aaaaaaaaaaa
49
aaaaaaaaaa
30
aaaaaaaaa
30
aaaaaaaa
16
aaaaaaa
16
aaaaaa
7
aaaaa
6
aaaa
2
aaa
1
aa
0
a
0
*/
