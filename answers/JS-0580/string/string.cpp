#include <bits/stdc++.h>
using namespace std;
#define PROG "string"
#define FILEIO 1
#define DEBUG 0
#define NAIVE 0

const int S=1e8+1;//1<<20|1;
int n;
char s[S];

void reads(char* s)
{
	n=0;
	char c=getchar();
	while (isspace(c)) c=getchar();
	while (!isspace(c))
	{
		*s++=c; ++n;
		c=getchar();
	}
}

void prints(int beg, int end)
{
	for (int i=beg; i<end; ++i)
		putchar(s[i]);
	putchar('\n');
}

const int C=127;
int cnt[C];

#if NAIVE
int fun(int beg, int end)
{
	int ret=0;
	memset(cnt, 0, sizeof(cnt));
	for (int i=beg; i<end; ++i)
	{
		++cnt[(int)s[i]];
	}
	for (int i=' '+1; i<C; ++i)
	{
		if (cnt[i]&1) ++ret;
	}
	return ret;
}
#else
int pf[S], sf[S];

void prefun()
{
#if DEBUG
	printf("$ prefun: ");
#endif
	memset(cnt, 0, sizeof(cnt));
	int tot=0;
	for (int i=0; i<n; ++i)
	{
		++cnt[(int)s[i]];
		if (cnt[(int)s[i]]&1) ++tot;
		else --tot;
		pf[i]=tot;
#if DEBUG
		printf("%d ", pf[i]);
#endif
	}
#if DEBUG
	printf("\n");
#endif
}

void suffun()
{
#if DEBUG
	printf("$ suffun: ");
#endif
	memset(cnt, 0, sizeof(cnt));
	int tot=0;
	for (int i=n-1; i>=0; --i)
	{
		++cnt[(int)s[i]];
		if (cnt[(int)s[i]]&1) ++tot;
		else --tot;
		sf[i]=tot;
#if DEBUG
		printf("%d ", sf[i]);
#endif
	}
#if DEBUG
	printf("\n");
#endif
}
#endif
#if 0
int nxt[S];

// nnrnnr
void calc()
{
	memset(nxt, 0, sizeof(nxt));
	//nxt[1]=0;
	for (int i=2, j=0; i<n; ++i)
	{
		while (j>0&&(s[i]!=s[j+1])) j=nxt[j];
		if (s[i]==s[j+1]) ++j;
		nxt[i]=j;
	}
#if DEBUG
	printf("$ calc <<\n");
	for (int i=0; i<n; ++i)
	{
		printf("%d\n", nxt[i]);
	}
	printf("$ >>\n");
#endif
}
#endif
#if 0 //prime factor
const int P=1e4;
int pr[P], pc[P];
#endif

void solve()
{
	int t, o, i, j, k, a, c;
	scanf("%d", &t);
	for (o=1; o<=t; ++o)
	{
		int ans=0;
		reads(s);
#if !NAIVE
		prefun(); suffun();
#endif
		//calc();
		//printf("$ n=%d\n", n);
		for (c=1; c<=n-2; ++c)
		{
			// k pieces
			int pre=n-c;
			for (k=1; k<=pre; ++k)
			{
				if (pre%k) continue;
				bool ok=true;
				int siz=pre/k;
				for (j=0; j<siz; ++j)
				{
					for (i=1; i<k; ++i)
					{
						if (s[i*siz+j]!=s[j])
						{
							ok=false;
							break;
						}
					}
					if (!ok) break;
				}
				if (ok)
				{
					for (a=1; a<siz; ++a)
					{
#if NAIVE
						i=a; j=n-c;
						if (fun(0, i)<=fun(j, n))
#else
						if (pf[a-1]<=sf[n-c])
#endif
						{
							++ans;
#if 0//DEBUG
							printf("$ <!!!\n");
							prints(0, i);
							prints(i, j);
							prints(j, n);
							printf("$ >\n");
#endif
						}
					}
				}
			}
			
		}
		printf("%d\n", ans);
	}
}

int main()
{
#if FILEIO
	freopen(PROG ".in", "r", stdin);
	freopen(PROG ".out", "w", stdout);
#endif
	solve();
#if FILEIO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
