#include <bits/stdc++.h>
using namespace std;

template < typename T >
inline  const void read(register T &x)
{
 register bool flag = x = 0;
 register char c;
 while ((c = getchar()) < 48 || c > 57)
	   flag = c == '-';
 do
 {
  x = (x << 1) + (x << 3) + (c ^ 48);
 }while ((c = getchar()) > 47 && c < 58);
 if (flag) x = -x;
}

int OUTPUT[40];
template < typename T >
inline const void write(register T x)
{
 if (x < 0)
 {
  putchar('-');
  x = -x;
 }
 register short SIZE = 0;
 do
 {
  OUTPUT[SIZE++] = x % 10 | 48;
  x /= 10;
 }while (x > 0);
 while (SIZE > 0) putchar(OUTPUT[--SIZE]);
}

template < typename T >
inline const void writeln(register T x)
{
 write(x);
 putchar(10);
}

char c[100001];
int f1[100001], f2[100001], tong[26];
int T;
bool sg[100001];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	read(T);
	while (T--)
	{
		scanf("%s", c + 1);
		int now = 2;char wy = c[1];bool iswy = 1;
		while (c[now] >= 'a' && c[now] <= 'z')
		{
			if (c[now] != wy) iswy = 0;
			++now;
		}
		--now;
		if (iswy)
		{
			int ans = 0;
			if (now % 2 == 0)
			{
				for (int i = 2; i < now; i++)
				{
					if (i % 2 == 1)
					{
						int t = sqrt(i);
						for (int j = 1; j <= t; j++)
							if (i % j == 0) ans += j + i / j - 2;
						if (t * t == i) ans -= t - 1;
					}
					else
					{
						int t = sqrt(i);
						for (int j = 1; j <= t; j++)
							if (i % j == 0) ans += (j - 1) / 2 + (i / j - 1) / 2;
						if (t * t == i) ans -= (t - 1) / 2;
					}				
				}	
			}
			else
			{
				for (int i = 2; i < now; i++)
				{
					if (i % 2 == 1)
					{
						int t = sqrt(i);
						for (int j = 1; j <= t; j++)
							if (i % j == 0) ans += (j - 1) / 2 + (i / j - 1) / 2;
						if (t * t == i) ans -= (t - 1) / 2;
					}
					else
					{
						int t = sqrt(i);
						for (int j = 1; j <= t; j++)
							if (i % j == 0) ans += j + i / j - 2;
						if (t * t == i) ans -= t - 1;
					}				
				}
			}
			writeln(ans);		
		}
		/*else
		{
			f1[0] = 0, f2[now + 1] = 0;
			int ans = 0;
			for (int i = 1; i <= now; i++)
			{
				tong[c[i] - 'a']++;
				if (tong[c[i] - 'a'] % 2 == 1) f1[i] = f1[i - 1] + 1;
				else f1[i] = f1[i - 1] - 1;
			}
			for (int i = 0; i < 26; i++) tong[i] = 0;
			for (int i = now; i >= 1; i--)
			{
				tong[c[i] - 'a']++;
				if (tong[c[i] - 'a'] % 2 == 1) f2[i] = f2[i + 1] + 1;
				else f2[i] = f2[i + 1] - 1;
			}
			memset(sg, 0, sizeof(sg));
			vector < int > v;
			int ttt = 0;
			for (int len = now - 1; len >= 1; len--)
			{
				if (!sg[len])
				{
					int t = sqrt(len);
					for (int xhj = 1; xhj <= t; xhj++)
					{
						for (int xhj = v[ttt]; xhj != 0; ttt--)
					{
						if (len % xhj == 0)
						{
							bool bs = 0;
							for (int i = xhj + 1; i <= len - xhj; i += xhj)
							{
								for (int j = 0; j < xhj; j++) 
								{
									if (c[i + j] != c[j + 1])
									{
										bs = 1;
										break;
									}
								}
							}
							v[++ttt] = len / xhj;
							if (!bs) 
							{
								int xhcs = len / xhj;
								int t = sqrt(xhcs);
								for (int i = 1; i <= t; i++)
								{
									if (xhcs % i == 0)
									{
										for (int j = 1; j < i * xhj; j++)
											for (int k = 1; k * i * xhj <= len; k++)
												if (f1[j] <= f2[k * i * xhj + 1]) ans++;
										sg[i * xhj] = 1;
										for (int j = 1; j < xhcs / i * xhj; j++)
											for (int k = 1; k * xhcs / i * xhj <= len; k++)
												if (f1[j] <= f2[k * xhcs / i * xhj + 1]) ans++;
										sg[xhcs / i * xhj] = 1;
									}
								}
								break;
							}
						}
					}
				}
						
					for (int xhj = v[ttt]; xhj != 0; ttt--)
					{
						if (len % xhj == 0)
						{
							bool bs = 0;
							for (int i = xhj + 1; i <= len - xhj; i += xhj)
							{
								for (int j = 0; j < xhj; j++) 
								{
									if (c[i + j] != c[j + 1])
									{
										bs = 1;
										break;
									}
								}
							}
							if (!bs) 
							{
								int xhcs = len / xhj;
								int t = sqrt(xhcs);
								for (int i = 1; i <= t; i++)
								{
									if (xhcs % i == 0)
									{
										for (int j = 1; j < i * xhj; j++)
											for (int k = 1; k * i * xhj <= len; k++)
												if (f1[j] <= f2[k * i * xhj + 1]) ans++;
										sg[i * xhj] = 1;
										for (int j = 1; j < xhcs / i * xhj; j++)
											for (int k = 1; k * xhcs / i * xhj <= len; k++)
												if (f1[j] <= f2[k * xhcs / i * xhj + 1]) ans++;
										sg[xhcs / i * xhj] = 1;
									}
								}
								break;
							}
						}
					}
				}
				
				
			}
			writeln(ans);
		}*/
	}
 return 0;
}
//nnrnnr
