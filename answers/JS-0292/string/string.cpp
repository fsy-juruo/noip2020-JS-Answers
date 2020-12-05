#include<bits/stdc++.h>
using namespace std;
int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
const int maxn = 1e6 + 10;
int n;
char A[maxn];
int B[maxn];
int cnt1[maxn], cnt2[maxn];
int t[100];
unsigned long long f1[maxn], f2[maxn], m1[maxn], m2[maxn];
const unsigned long long mod = 998244353;
int c[maxn];
void add(int x) {
	x++;
	for (; x <= n + 1; x += x & -x) {
		c[x]++;
	}
}
int ask(int x) {
	x++;
	int sum = 0;
	for(; x; x -= x & -x) {
		sum += c[x];
	}
	return sum;
}
void solve() {
	memset(c, 0, sizeof(c));
	scanf("%s", A + 1);
	n = strlen(A + 1);
	if(n <= 2) {
		puts("0");
		return;
	}
	m1[0] = m2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		B[i] = A[i] - 'a';
		f1[i] = f1[i - 1] * 26 + B[i];
		f2[i] = f2[i - 1] * 26 + B[i], f2[i] %= mod;
		m1[i] = m1[i - 1] * 26, m2[i] = m2[i - 1] * 26, m2[i] %= mod;
	}
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; ++i) {
		t[B[i]] ^= 1, cnt1[i] = cnt1[i - 1];
		if(t[B[i]])cnt1[i]++;
		else cnt1[i]--;
	}
	memset(t, 0, sizeof(t));
	for (int i = n; i; --i) {
		t[B[i]] ^= 1, cnt2[i] = cnt2[i + 1];
		if(t[B[i]])cnt2[i]++;
		else cnt2[i]--;
	}
	long long sum = 0;
	add(cnt1[1]);
	for (int rB = 2; rB < n; ++rB) {
		sum += ask(cnt2[rB + 1]);
		for (int i = 2; rB * i < n; ++i) {
			if(f1[rB] * m1[rB * (i - 1)] + f1[rB * (i - 1)] == f1[rB * i] && (f2[rB] * m2[rB * (i - 1)] + f2[rB * (i - 1)]) % mod == f2[rB * i]) {
				sum += ask(cnt2[rB * i + 1]);
			} else {
				break;
			}
		}
		add(cnt1[rB]);
	}
	printf("%lld\n", sum);
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T = read();
	while (T--) {
		solve();
	}
	return 0;
}

