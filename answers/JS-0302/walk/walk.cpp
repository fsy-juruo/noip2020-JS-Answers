#include<bits/stdc++.h>
#define fox(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

inline int rd() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

const int P = 1e9 + 7, K = 11, N = 5e5 + 10;
int n, k, w[K];
int a[K], b[K], ar[K][N], br[K][N];

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = rd(), k = rd();
	fox (i, 1, k) w[i] = rd();
	int c, d, r[K];
	fox (i, 1, k) r[i] = 0;
	fox (i, 1, n) {
		c = rd(), d = rd();
		r[c] += d;
		if (r[c] > 0 && !ar[c][r[c]]) a[c] = r[c], ar[c][r[c]] = i;
		if (r[c] < 0 && !br[c][-r[c]]) b[c] = -r[c], br[c][-r[c]] = i;
	}
	
	bool flag = 1;
	fox (i, 1, k) {
		if (r[i] < 0)
			swap(a[i], b[i]), swap(ar[i], br[i]), r[i] = -r[i];
		if (r[i] != 0) flag = 0;
	}
	if (flag) {
		fox (i, 1, k) {
			if (a[i] + b[i] <= w[i]) {
				puts("-1");
				return 0;
			}
		}
	}
	
	int g = 0;
	
	int xa, xr, L, R, l, rr, mid;
	int ss, ans = 0;
	fox (i, 1, k) {
		//puts("-------");
		fox (j, 1, w[i]) {
			xa = xr = P, ss = 1;
			if (j <= b[i]) xa = 0, xr = br[i][j];
			if ((w[i] - j + 1) <= a[i]) xr = min(xr, ar[i][w[i] - j + 1]), xa = 0;
			if (r[i] && xa) {
				xa = (w[i] - j + 1 - a[i] + r[i] - 1) / r[i];
				xr = ar[i][w[i] - j + 1 - r[i] * xa];
			}
			if (xa == P) continue;
			
			fox (o, 1, k) {
				if (i == o) continue;
				L = 0, l = 1, rr = a[o];
				while (l <= rr) {
					mid = l + rr >> 1;
					if (ar[o][mid] < xr) L = mid, l = mid + 1;
					else rr = mid - 1;
				} ++L;
				L += xa * r[o];
				if (xa) L = max(L, (xa - 1) * r[o] + a[o] + 1);
				
				
				if (xa) R = w[o] - b[o];
				else {
					R = 0, l = 1, rr = b[o];
					while (l <= rr) {
						mid = l + rr >> 1;
						if (br[o][mid] < xr) R = mid, l = mid + 1;
						else rr = mid - 1;
					}
					R = w[o] - R;
				}
				
				if (R - L + 1 > 0) ss = 1LL * ss * (R - L + 1) % P;
				else ss = 0;
			}
			//cout << ss << endl;
			g += ss;
			ans = (ans + 1LL * ss * (1LL * xa * n % P + xr)) % P;
		}
	}
	
	//cout << g << endl;
	printf("%d\n", ans);
	return 0;
}

