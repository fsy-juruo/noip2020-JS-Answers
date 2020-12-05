#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define LD long double
#define _rep(i, x, y) for(int i = x; i <= y; i++)
#define _per(i, x, y) for(int i = x; i >= y; i--)
template <typename T>
inline void read(T &x) {
	x = 0; T f = (T) 1;
	char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T>
inline void write(T x) {
	if(x < 0) x = -x, putchar('-');
	if(x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T>
inline void writesp(T x, char sp) {
	write(x); putchar(sp);
}

const int maxK = 15, maxN = 5e5 + 10, P = 1e9 + 7;
int n, k, ans, w[maxK], a[maxN], b[maxN], cur[maxK], maxR[maxK], minR[maxK], latt[200010];
LL dp[200010];

int coor[16], cr[16];
bool valid() {
	_rep(i, 1, k) if(cr[i] > w[i] || cr[i] <= 0) return false;
	return true;
}
bool pre_valid() {
	_rep(i, 1, k) if((cr[i] + maxR[i]) > w[i] || (cr[i] + minR[i]) <= 0) return false;
	return true; 
}
int wjp_ak_ioi() {
	_rep(i, 1, k) cr[i] = coor[i];
	int steps = 0, qwq = 1;
	while(pre_valid()) {
		_rep(i, 1, k) cr[i] += cur[i];
//		_rep(i, 1, k) writesp(cr[i],  ' ');
//		puts("");
		steps = (steps + n) % P;
	}
	while(valid()) {
		cr[a[qwq]] += b[qwq];
//		_rep(i, 1, k) writesp(cr[i],  ' ');
//		puts("");
		qwq = (qwq) % n + 1;
		steps = (steps + 1) % P;
	}
	return steps;
}

void search_coor(int dep) {
	if(dep > k) {
		ans = (ans + wjp_ak_ioi()) % P;
		return;
	}
	_rep(i, 1, w[dep]) {
		coor[dep] = i;
		search_coor(dep + 1);
		coor[dep] = 0;
	}
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n); read(k);
	_rep(i, 1, k) read(w[i]);
	_rep(i, 1, n) {
		read(a[i]); read(b[i]);
		cur[a[i]] += b[i];
		maxR[a[i]] = std::max(maxR[a[i]], cur[a[i]]);
		minR[a[i]] = std::min(minR[a[i]], cur[a[i]]);
	}
//	std::cout << cur[1] << std::endl;
	int flg1 = 1, flg2 = 1;
	_rep(i, 1, n) {
		if(cur[i] != 0) flg1 = 0;
		if(maxR[i] - minR[i] > w[i] - 1) flg2 = 0;
	}
	if(flg1 && flg2) {
		puts("-1");
		return 0;
	} else {
		if(k == 1) {
			int q = 0;
			_rep(i, 1, n) {
				q += b[i];
				if(!latt[q + w[1]] && q) latt[q + w[1]] = i;
			}	
//			_rep(i, -w[1], w[1]) {
//				writesp(latt[i + w[1]], ' ');
//			}
//			puts("");
			LL INF = 1ll << 60;
			_rep(i, 1, w[1]) dp[i] = INF;
			ans = 0;
			_rep(i, 1, w[1]) {
				int Ldur = -i + w[1];
				int Rdur = (w[1] - i + 1) + w[1];
				if(latt[Ldur]) {
					dp[i] = std::min(dp[i], 1ll * latt[Ldur]);
				} 
				if(latt[Rdur]) {
					dp[i] = std::min(dp[i], 1ll * latt[Rdur]);
				}
			}	
			if(cur[1] > 0) {
				_per(i, w[1], 1) {
					if(dp[i] == INF) {
//						std::cout << dp[i] << " " << dp[i + cur[1]] << " " << i + cur[1] << std::endl;
						dp[i] = std::min(dp[i], dp[i + cur[1]] + n);
					}
				}
			} else {
				_rep(i, 1, w[1]) {
					if(dp[i] == INF) {
						dp[i] = std::min(dp[i], dp[i + cur[1]] + n);
					}
				}
			}
			_rep(i, 1, w[1]) {
//				writesp(dp[i], '\n');
				ans = (ans + dp[i] % P) % P;
			}
			writesp(ans, '\n');
		} else {
			search_coor(1);
			writesp(ans, '\n');
		}
	}
	return 0;
}

