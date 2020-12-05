// 1 ~ 8 (12)
#include <bits/stdc++.h>
using namespace std;
/*things you should actually check:
0. memory limit                     // ~9M
1. overflow                         // 30
2. special cases                    // no
3. do smth. better than noth.       //
4. stay organized                   //
5. complete freopen                 // completed
6. simple is better than ugly       //
7. flat is better than nested       //
8. sparse is better than dense      //
9. readablity counts                //
*/
int T;
int fr[1050000], bk[1050000]; // ~8M
char s[1050000]; // ~1M
#define list_checked
#ifdef list_checked
int main()
{
#ifndef LOCAL
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int n = strlen(s);
		int cnt[26], res = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			res -= cnt[s[i] - 'a'];
			cnt[s[i] - 'a'] ^= 1;
			res += cnt[s[i] - 'a'];
			fr[i] = res;
		}
		memset(cnt, 0, sizeof(cnt));
		res = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			res -= cnt[s[i] - 'a'];
			cnt[s[i] - 'a'] ^= 1;
			res += cnt[s[i] - 'a'];
			bk[i] = res;
		}
		int ans = 0;
		for (int i = 1; i < n; i++) for (int j = 2; j <= n - i; j++) if ((n - i) % j == 0)
		{
			bool ok = true;
			for (int k = j; k < n - i; k++) if (s[k] != s[k - j]) ok = false;
			if (ok) for (int k = 1; k < j; k++) if (fr[k - 1] <= bk[n - i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
#endif
/*sample:
3
nnrnnr
zzzaab
mmlmmlo
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
