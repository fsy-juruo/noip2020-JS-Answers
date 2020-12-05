#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N = 1100000;

int n, cnt[30], sum[N];

char str[N];

namespace Binary_Indexed_Tree
{
	int tree[N];
	inline int lowbit(int x) { return x & -x; }
	inline void modify(int x, int val) { for (; x <= N; x += lowbit(x)) tree[x] += val; }
	inline int query(int x) { int ret = 0; for (; x; x -= lowbit(x)) ret += tree[x]; return ret; }
}
using namespace Binary_Indexed_Tree;

struct String_Hash
{
	int Base;
	ULL p[N], F[N];
	
	inline void init(int num)
	{
		Base = num;
		p[0] = 1;
		for (int i = 1; i <= (1 << 20); i++) p[i] = p[i - 1] * Base;
	}
	
	inline void build() { for (int i = 1; i <= n; i++) F[i] = F[i - 1] * Base + (str[i] - 'a'); }
	inline ULL query(int l, int r) { return F[r] - F[l - 1] * p[r - l + 1]; }
	
} Hash[2];

inline void solve()
{
	memset(cnt, 0, sizeof(cnt));
	
	scanf ("%s", str + 1); n = strlen(str + 1);
	
	sum[n + 1] = 0;
	for (int i = n; i >= 1; i--)
	{
		cnt[str[i] - 'a']++;
		sum[i] = sum[i + 1];
		if (cnt[str[i] - 'a'] % 2 == 0) sum[i]--;
		else sum[i]++;
	}
		
	Hash[0].build(); Hash[1].build();

	memset(cnt, 0, sizeof(cnt));
	memset(tree, 0, sizeof(tree));
	
	LL ans = 0;
	int Fa = 0;
	for (int i = 2; i < n; i++)
	{
		cnt[str[i - 1] - 'a']++;
		if (cnt[str[i - 1] - 'a'] % 2 == 0) Fa--;
		else Fa++;
		
		modify(Fa + 1, 1);
		
		LL now = 0;
		for (int j = i; j < n; j += i)
		{
			if (Hash[0].query(j - i + 1, j) != Hash[0].query(1, i) || Hash[1].query(j - i + 1, j) != Hash[1].query(1, i)) break;
			
			now += query(sum[j + 1] + 1);
		}
		ans += now;
	}
	printf ("%lld\n", ans);
}

int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	
	Hash[0].init(99991); Hash[1].init(99997);
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	return 0;
}
