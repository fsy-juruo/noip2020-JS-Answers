#include<bits/stdc++.h>
#define filename "walk"
#define reg register
#define ll long long
#define il inline

using namespace std;

template <typename T> void fi(T &x) {
	T f = 1, c = getchar();
	x = 0;
	while(!isdigit(c)) {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}

int n, k, w[11];
int c[500010], d[500010];
int loc[11], rngchk[11], elstloc[11][1000010], frst[11], mfrst[11];
il bool cnum(int num, int x) {
	return num >= 1 && num <= w[x];
}
ll ans, MOD = 1000000007;

int main() {
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	fi(n);
	fi(k);

	for(reg int i = 1; i <= k; ++ i ) {
		fi(w[i]);
	}

	for(reg int i = 1; i <= n; ++ i ) {
		fi(c[i]);
		fi(d[i]);
//		rngchk[c[i]] += d[i];
//		frst[c[i]] = max(frst[c[i]], rngchk[c[i]]);
//		mfrst[c[i]] = min(mfrst[c[i]], rngchk[c[i]]);
	}

	for(reg int i = 1; i <= k; ++ i ) {
		rngchk[i] = -mfrst[i];
	}

	for(reg int i = 0; i < n; ++ i ) {
		rngchk[c[i]] += d[i];
		if(!elstloc[c[i]][rngchk[c[i]]]) {
			elstloc[c[i]][rngchk[c[i]]] = i + 1;
		}
	}

	for(reg int i = 1; i <= k; ++ i ) { //check impossible
		if(rngchk[i] != 0) break;
		if(i == k) {
			for(reg int j = 1; j <= k; ++ j ) {
				if(!cnum(frst[j] + mfrst[j] + 1, j)) {
					break;
				}
				if(j == k) {
					printf("-1");
					return 0;
				}
			}
		}
	}
	ans = 0;
	if(n <= 5 && k > 3) {
		if(k == 4) {
			for(reg int i1 = 1; i1 <= w[1]; ++ i1 ) {
				for(reg int i2 = 1; i2 <= w[2]; ++ i2 ) {
					for(reg int i3 = 1; i3 <= w[3]; ++ i3 ) {
						for(reg int i4 = 1; i4 <= w[4]; ++ i4 ) {
							loc[1] = i1;
							loc[2] = i2;
							loc[3] = i3;
							loc[4] = i4;
							for(int j = 1; ; j = j % n + 1) {
								loc[c[j]] += d[j];
								ans ++;
								if(!cnum(loc[c[j]], c[j])) {
									break;
								}
							}
						}
					}
				}
			}
		}
		if(k == 5) {
			for(reg int i1 = 1; i1 <= w[1]; ++ i1 ) {
				for(reg int i2 = 1; i2 <= w[2]; ++ i2 ) {
					for(reg int i3 = 1; i3 <= w[3]; ++ i3 ) {
						for(reg int i4 = 1; i4 <= w[4]; ++ i4 ) {
							for(reg int i5 = 1; i3 <= w[5]; ++ i5 ) {
								loc[1] = i1;
								loc[2] = i2;
								loc[3] = i3;
								loc[4] = i4;
								loc[5] = i5;
								for(int j = 1; ; j = j % n + 1) {
									loc[c[j]] += d[j];
									ans ++;
									if(!cnum(loc[c[j]], c[j])) {
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if(n <= 100) {
		if(k == 1) {
			for(reg int i1 = 1; i1 <= w[1]; ++ i1 ) {
				loc[1] = i1;
				for(int j = 1; ; j = j % n + 1) {
					loc[c[j]] += d[j];
					ans ++;
					if(!cnum(loc[c[j]], c[j])) {
						break;
					}
				}
			}
		}
		if(k == 2) {
			for(reg int i1 = 1; i1 <= w[1]; ++ i1 ) {
				for(reg int i2 = 1; i2 <= w[2]; ++ i2 ) {
					loc[1] = i1;
					loc[2] = i2;
					for(int j = 1; ; j = j % n + 1) {
						loc[c[j]] += d[j];
						ans ++;
						if(!cnum(loc[c[j]], c[j])) {
							break;
						}
					}
				}
			}
		}
		if(k == 3) {
			for(reg int i1 = 1; i1 <= w[1]; ++ i1 ) {
				for(reg int i2 = 1; i2 <= w[2]; ++ i2 ) {
					for(reg int i3 = 1; i3 <= w[3]; ++ i3 ) {
						loc[1] = i1;
						loc[2] = i2;
						loc[3] = i3;
						for(int j = 1; ; j = j % n + 1) {
							loc[c[j]] += d[j];
							ans ++;
							if(!cnum(loc[c[j]], c[j])) {
								break;
							}
						}
					}
				}
			}
		}
	}
//
//	if(k == 1) {
//		for(reg int i = 1; i <= w[1]; ++ i ) {
//			if(i + frst[1] <= w[1] && i + mfrst[1] >= 1) {
//				if(rngchk[1] > 0) {
////					ans +=
//				}
//				else {
//					ans = (ans + (i + mfrst[1]) / rngchk[1] * n) % MOD;
////					ans +=
//				}
//			}
//			else {
//				int tmp = INT_MAX;
//				if(i + frst[1] > w[1]) {
//					tmp = min(tmp, elstloc[1][w[1] + 1 - i - mfrst[1]]);
//				}
//				if(i + mfrst[1] < 1) {
//					tmp = min(tmp, elstloc[1][0 - i - mfrst[1]]);
//				}
//				ans = (ans + tmp) % MOD;
//			}
//		}
//	}
//	else {
//
//	}
	printf("%lld", ans % MOD);
	return 0;
}

