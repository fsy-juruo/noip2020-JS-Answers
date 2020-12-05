#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
	x = 0;
	char ch = getchar();
	T fh = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') fh = -1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	x *= fh;
}
template <typename T>
void wt(T x) {
	if (x > 9) wt(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char ch) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	wt(x);
	putchar(ch);
}
const int N = 1e6 + 2e5;
char st[N];
int n, pre[30], c[30], suf[N], cnt;
unsigned long long v1[N], v2[N], up1[N], up2[N];
const int p1 = 231, p2 = 23331;
inline int lowbit(int x) {
	return x & (-x);
}
void add(int x) {
	for (; x <= 27; x += lowbit(x)) {
		c[x] ++;
	}
}
int ask(int x) {
	int sum = 0;
	for (; x; x -= lowbit(x)) {
		sum += c[x];
	}
	return sum;
}
const int inf = 1;
inline bool check(int x, int y) {
	if (v1[y] - (v1[y - x] * up1[x]) == v1[x] && v2[y] - (v2[y - x] * up2[x]) == v2[x]) return true;
	else return false;
}
long long ans = 0;
void work(int x) {
	ans += ask(suf[x + 1] + inf);
	for (int i = x * 2; i < n; i += x) {
		if (check(x, i)) {
			ans += ask(suf[i + 1] + inf);
		}
		else break;
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T;
	readin(T);
	while (T --) {
		for (int i = 1; i <= 29; i ++) c[i] = 0;
		scanf("%s", st + 1);
		n = strlen(st + 1);
		ans = 0;
		up1[0] = up2[0] = 1;
		for (int i = 1; i <= n; i ++) {
			v1[i] = (v1[i - 1] * p1) + st[i] - 'a';
			up1[i] = up1[i - 1] * p1;
			v2[i] = (v2[i - 1] * p2) + st[i] - 'a';
			up2[i] = up2[i - 1] * p2;
		}
		for (int i = 0; i <= 26; i ++) pre[i] = 0;
		suf[n + 1] = 0;
		for (int i = n; i >= 1; i --) {
			if (pre[st[i] - 'a'] == 0) suf[i] = suf[i + 1] + 1;
			else suf[i] = suf[i + 1] - 1;
			pre[st[i] - 'a'] ^= 1;
		}
		for (int i = 0; i <= 26; i ++) pre[i] = 0;
		cnt = 0;
		for (int i = 2; i < n; i ++) {
			if (pre[st[i - 1] - 'a'] == 0) cnt ++;
			else cnt --;
			pre[st[i - 1] - 'a'] ^= 1;
			add(cnt + inf);
			work(i);
		}
		writeln(ans, '\n');
	} 
	return 0;
}

