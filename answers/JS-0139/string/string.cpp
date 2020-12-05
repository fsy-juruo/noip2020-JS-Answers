#include <bits/stdc++.h>
using namespace std;

const int N = 30;

struct State {
	int cnt[26];
	int ans;
	void init() {memset(cnt, 0, sizeof(cnt)), ans = 0;}
	void modify(char c, int val) {
		int x = c - 'a';
		ans -= cnt[x] & 1;
		cnt[x] += val;
		ans += cnt[x] & 1;
	}
}cur;

int T[40];
int suc[1100000];
char s[1100000];
int z[1100000];

void modify(int x, int v) {
	x++;
	while (x <= N) T[x] += v, x += x & -x;
}

int query(int x) {
	x++;
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

void get_z(int n) {
	z[0] = -1;
	int L = 0, R = 0;
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R] == s[R - L]) R++;
			z[i] = R - L, R--;
			continue;
		}
		if (i + z[i - L] - 1 < R) {
			z[i] = z[i - L];
			continue;
		}
		L = i, R++;
		while (R < n && s[R] == s[R - L]) R++;
		z[i] = R - L, R--;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int Case; scanf("%d", &Case);
	while (Case--) {
		scanf("%s", &s);
		int n = strlen(s);
		get_z(n);
		cur.init();
		for (int i = n - 1; i >= 0; i--) {
			cur.modify(s[i], 1);
			suc[i] = cur.ans;
		}
		cur.init();
		cur.modify(s[0], 1);
		memset(T, 0, sizeof(T));
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			modify(cur.ans, 1);
			int len = i + 1;
			for (int j = len; j < n; j += len) {
				ans += query(suc[j]);
				if (j + len >= n || z[j] < len) break;
			}
			cur.modify(s[i], 1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
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
