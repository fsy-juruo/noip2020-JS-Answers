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
const int N = 5e5 + 5;
int n, k, p[15], t[15], w[15], dc[15], ic[15], a[15], c[N], d[N];
long long ans = 0;
bool trp = false;
void dfs(int dep) {
	if (dep == k + 1) {
		bool flg = true;
		for (int i = 1; i <= k; i ++) {
			if (a[i] != 0) {
				flg = false;
				break;
			} 
			else if (p[i] + dc[i] < 1 || p[i] + ic[i] > w[i]) {
				flg = false;
				break;
			}
		}
		int val = 0;
		if (flg == true) {
			trp = true;
			return;
		}
		else {
			for (int i = 1; i <= k; i ++) t[i] = p[i];
			int id = 1;
			while (true) {
				t[c[id]] += d[id];
				val ++;
				if (t[c[id]] > w[c[id]] || t[c[id]] < 1) break;
				id = id % n + 1;
			}
			ans += val;
		}
	}
	else {
		for (int i = 1; i <= w[dep]; i ++) {
			p[dep] = i;
			dfs(dep + 1);
			if (trp) return;
		}
	}
}
int L[N], R[N], dp[N];
const int mod = 1e9 + 7;
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	readin(n); readin(k);
	for (int i = 1; i <= k; i ++) {
		readin(w[i]);
		a[i] = 0;
	}
	for (int i = 1; i <= n; i ++) {
		readin(c[i]); readin(d[i]);
		a[c[i]] += d[i];
		dc[c[i]] = min(dc[c[i]], a[c[i]]);
		ic[c[i]] = max(ic[c[i]], a[c[i]]);
	}
	if (n <= 1000) {
		dfs(1);
		if (trp) puts("-1");
		else writeln(ans, '\n');
	}
	else if (k == 1) {
		int pos = 0;
		for (int i = 1; i <= n; i ++) {
			pos += d[i];
			L[i] = min(L[i - 1], pos);
			R[i] = max(R[i - 1], pos);
		}
		long long val = 0;
		if (pos <= 0) {
			int li, ri, cho;
			for (int i = 1; i <= w[1]; i ++) {
				li = 1; ri = n;
				cho = -1;
				while (li <= ri) {
					int mid = li + ri >> 1;
					if (L[mid] + i < 1 || R[mid] + i > w[1]) {
						cho = mid;
						ri = mid - 1;
					}
					else li = mid + 1;
				}
				if (cho != -1) dp[i] = cho;
				else if (dp[i + pos] != -1) dp[i] = (dp[i + pos] + n) % mod;
				else {
					trp = true;
					break;
				}
			}
		}
		if (pos > 0) {
			int li, ri, cho;
			for (int i = w[1]; i >= 1; i --) {
				li = 1; ri = n;
				cho = -1;
				while (li <= ri) {
					int mid = li + ri >> 1;
					if (L[mid] + i < 1 || R[mid] + i > w[1]) {
						cho = mid;
						ri = mid - 1;
					}
					else li = mid + 1;
				}
				if (cho != -1) dp[i] = cho;
				else if (dp[i + pos] != -1) dp[i] = (dp[i + pos] + n) % mod;
				else {
					trp = true;
					break;
				}
			}			
		}
		if (trp) puts("-1");
		else {
			ans = 0;
			for (int i = 1; i <= w[1]; i ++) {
				ans = (ans + dp[i]) % mod;
			}
			writeln(ans, '\n');
		}
	}
	return 0;
}

