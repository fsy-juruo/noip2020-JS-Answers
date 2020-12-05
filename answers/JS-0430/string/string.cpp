#include <bits/stdc++.h>
const int INF = 1e9 + 7;
const int MAXN = 1100005;
const int T = 25;

class Solver1 {
	const static int N = 1005;
	
	int t;
	int sizes[T];
	int a[T][N];
	long long cs[T][N];
	int cnt_odd[N][N];
	int sum[N][35];
	int answer[T];
	
	public:
	
	Solver1 (int new_t, int new_sizes[T], int new_a[T][MAXN]) {
		t = new_t;
		memcpy(sizes, new_sizes, T * 4);
		for (int i = 1; i <= t; i += 1) {
			memcpy(a[i], new_a[i], sizes[i] * 4 + 8);
		}
	}
	
	void initialize() {
		memset(answer, 0, sizeof answer);
		memset(cs, 0, sizeof cs);
		for (int i = 1; i <= t; i += 1) {
			for (int j = 1; j <= sizes[i]; j += 1) {
				cs[i][j] = cs[i][j - 1] + a[i][j];
			}
		}
	}
	
	void calc_odd(int epoch) {
		memset(sum, 0, sizeof sum);
		memset(cnt_odd, 0, sizeof cnt_odd);
		for (int j = 1; j <= sizes[epoch]; j += 1) {
			for (int k = 1; k <= 26; k += 1) {
				sum[j][k] = sum[j - 1][k] + (a[epoch][j] == k);
			}
		}
		for (int i = 1; i <= sizes[epoch]; i += 1) {
			for (int j = i; j <= sizes[epoch]; j += 1) {
				for (int k = 1; k <= 26; k += 1) {
					if ((sum[j][k] - sum[i - 1][k]) % 2 == 1) {
						cnt_odd[i][j] += 1;
					}
				}
			}
		}
	}
	
	void solve() {
		for (int epoch = 1; epoch <= t; epoch += 1) {
			calc_odd(epoch);
			bool ok;
			int as = 1, ae, bs, be, rep;
			for (ae = 1; ae <= sizes[epoch] - 2; ae += 1) {
				bs = ae + 1;
				for (be = bs; be <= sizes[epoch] - 1; be += 1) {
					for (rep = 1; rep <= sizes[epoch] / be; rep += 1) {
						ok = true;
						if (be * rep >= sizes[epoch]) {
							break;
						}
						if (rep > 1) {
							if (
								cs[epoch][be * rep] - cs[epoch][be * (rep - 1)] !=
								cs[epoch][be]
							) {
								ok = false;
								break;
							}
							for (int i = be * (rep - 1) + 1; i <= be * rep; i += 1) {
								if (a[epoch][i] != a[epoch][i - be]) {
									ok = false;
									break;
								}
							}
						}
						if (!ok) {
							break;
						}
						if (cnt_odd[be * rep + 1][sizes[epoch]] >= cnt_odd[as][ae]) {
							answer[epoch] += 1;
						}
					}
				}
			}
		}
	}
	
	void print() {
		for (int epoch = 1; epoch <= t; epoch += 1) {
			printf("%d\n", answer[epoch]);
		}
	}
};

class Solver2 {
	const static int N = 33005;
	
	int t;
	int sizes[T];
	long long answer[T];
	
	public:
	
	Solver2 (int new_t, int new_sizes[T]) {
		t = new_t;
		memcpy(sizes, new_sizes, T * 4);
	}
	
	void initialize() {
		memset(answer, 0, sizeof answer);
	}
	
	void solve() {
		int p, nc;
		for (int i = 1; i <= t; i += 1) {
			for (int c = 1; c <= sizes[i] - 2; c += 1) {
				nc = sizes[i] - c;
				for (int k = 2; k <= std::sqrt(nc); k += 1) {
					if (nc % k != 0) {
						continue;
					}
					if (c % 2 == 1) {
						answer[i] += (k - 1);
					} else {
						answer[i] += (k - 1) / 2;
					}
					p = nc / k;
					if (p != k) {
						if (c % 2 == 1) {
							answer[i] += (p- 1);
						} else {
							answer[i] += (p- 1) / 2;
						}
					}
				}
				if (c % 2 == 1) {
					answer[i] += (nc - 1);
				} else {
					answer[i] += (nc - 1) / 2;
				}
			}
		}
	}
	
	void print() {
		for (int epoch = 1; epoch <= t; epoch += 1) {
			printf("%lld\n", answer[epoch]);
		}
	}
};

int t, max_size;
int sizes[T];
int a[T][MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	
	bool is_same = true;
	scanf("%d", &t);
	getchar();
	for (int i = 1; i <= t; i += 1) {
		char p;
		sizes[i] = 0;
		while (true) {
			p = getchar();
			if (p < 'a' || p > 'z') {
				break;
			}
			sizes[i] += 1;
			a[i][sizes[i]] = (int)(p) - int('a') + 1;
			if (a[i][sizes[i]] != a[i][1]) {
				is_same = false;
			}
		}
		max_size = std::max(max_size, sizes[i]);
	}
	
	if (max_size <= 1000) {
		Solver1 solver = Solver1(t, sizes, a);
		solver.initialize();
		solver.solve();
		solver.print();
	} else if (is_same) {
		Solver2 solver = Solver2(t, sizes);
		solver.initialize();
		solver.solve();
		solver.print();
	}
	return 0;
}

