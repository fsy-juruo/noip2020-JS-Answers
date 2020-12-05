#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1050100;

int n , a[N];
int T;
int cnt[N][27];
int suml[N] , sumr[N];
int kmp[N];
int k , p[N];
int ans;

template <typename T> void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void write(T x , char c) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar(c);
}

void Pre() {
	int j = 0;
	kmp[1] = 0;
	for (int i = 2; i <= n; i++) {
		while(j > 0 && a[j + 1] != a[i]) j = kmp[j];
		if (a[j + 1] == a[i]) j++;
		kmp[i] = j;
	}
	return;
}

int main() {

	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);

	read(T);
	while(T--) {
		char ch = getchar();
		n = 0;
		ans = 0;
		for (; ch >= 'a' && ch <= 'z'; ch = getchar()) a[++n] = ch - 'a';
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				cnt[i][j] = cnt[i - 1][j];
			}
			cnt[i][a[i]]++;
			p[i] = i;
		}
		for (int i = 1; i <= n; i++) {
			suml[i] = sumr[i] = 0;
			for (int j = 0; j < 26; j++) {
				if (cnt[i][j] & 1) suml[i]++;
				if ((cnt[n][j] - cnt[i - 1][j]) & 1) sumr[i]++;
			}
		}
		Pre();
		for (int i = 2; i < n; i++) {
			if (kmp[i] && i % (i - kmp[i]) == 0) {
				k = i - kmp[i];
				int t = i / (i - kmp[i]);
				for (int j = 1; j * j <= t; j++) {
					if (t % j == 0) p[k * j] = p[(t / j) * k] = i;
				}
			}
		}
		for (int i = 2; i < n; i++) {
			int jc , oc;
			oc = sumr[p[i] + 1];
			jc = sumr[p[i] + 1 - i];
			for (int j = 1; j < i; j++) {
				if (suml[j] <= oc) {
					ans += ((p[i] - i) / i) / 2;
					ans++;
				}
				if (suml[j] <= jc) {
					ans += (((p[i] - i) / i) + 1) / 2;
				}
			}
		}
		write(ans , '\n');
	}

	return 0;

}

