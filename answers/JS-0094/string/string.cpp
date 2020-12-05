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

const int maxS = (1 << 20) + 1;
char B[maxS];
int len, F[maxS], Fsuf[maxS], buk[26], nxt[maxS];

struct BIT {
	int a[maxS];
	void init() {memset(a, 0, sizeof(a));}
	int lowbit(int x) {return x & (-x);}
	void add(int x, int delta) {
		for(; x <= len; x += lowbit(x)) a[x] += delta;
	}
	int query(int x) {
		int ans = 0;
		for(; x; x -= lowbit(x)) ans += a[x];
		return ans;
	}
} wjpakioi;

struct Position {
	int pos, val;
} ccf[maxS], qaq[maxS];
bool cmp(Position A, Position B) {
	return A.val < B.val;
}
int getnxt() {
	nxt[1] = 0;
	for(int i = 2, j = 0; i <= len; i++) {
		while(j && (B[i] != B[j + 1])) {
			j = nxt[j];
		}
		if(B[i] == B[j + 1]) ++j;
		nxt[i] = j;
//		std::cout << len << std::endl;
	}
}

bool check(int len, int Len) {
	if(Len == len) return true;
	_rep(i, Len + 1, len) {
		if(B[(i - 1) % Len + 1] != B[i]) return false;
	}
	return true;
}

void calF() {
	memset(buk, 0, sizeof(buk));
	int cnt = 0;
	_rep(i, 1, len) {
		int Flg = B[i] - 'a';
		cnt += (buk[Flg] & 1 ? -1 : 1); buk[Flg]++;
		F[i] = cnt;
	}
	memset(buk, 0, sizeof(buk)); cnt = 0;
	_per(i, len, 1) {
		int Flg = B[i] - 'a';
		cnt += (buk[Flg] & 1 ? -1 : 1); buk[Flg]++;
		Fsuf[i] = cnt;
	}
}
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int T; read(T);
	while(T--) {
		scanf("%s", B + 1); len = strlen(B + 1); //std::cout << len << std::endl;
//		std::cout << len << std::endl;
		calF(); 
		LL tot_ans = 0;
		if(len <= 100) { 
			_rep(i, 1, len) { // enumerate C
				int lenn = i - 1, ans = 0; 
				if(!lenn) continue;
				_rep(Len, 1, lenn) {
					if(F[Len] <= Fsuf[i]) ans++;
					if(lenn % Len) continue;
					if(check(lenn, Len)) {
						tot_ans += ans;
						if(F[Len] <= Fsuf[i]) tot_ans--;
//						printf("C = %d, Len = %d is valid, answer = %d, partial_ans = %d\n", i, Len, tot_ans, ans);
					}
				}
			}
			writesp(tot_ans, '\n');
		} else {
			getnxt();
			wjpakioi.init();
			// i - nxt[i] : smallest unit
			_rep(i, 1, len) {
				ccf[i].pos = qaq[i].pos = i; ccf[i].val = Fsuf[i];
				qaq[i].val = F[i];
			}
			std::sort(qaq + 1, qaq + len + 1, cmp);
			std::sort(ccf + 1, ccf + len + 1, cmp);
			int LastVal = -1, ptr = 1;
			LL ans = 0;
			_rep(i, 1, len) {
				if(LastVal < ccf[i].val) {
					while(ptr <= len && qaq[ptr].val <= ccf[i].val) {
						wjpakioi.add(qaq[ptr].pos, 1);
						++ptr;
					}
					LastVal = ccf[i].val;
				}
//				_rep(j, 1, len) {
//					std::cout << wjpakioi.query(j) << " ";
//				}
//				puts("");
//				std::cout << ccf[i].pos << "/ ";
				int xc = ccf[i].pos - 1;
				if(!xc) continue;
				int l = (xc - nxt[xc]);
				if(xc / (xc - nxt[xc]) != 1 && xc % (xc - nxt[xc]) == 0) {
					int poss = xc / (xc - nxt[xc]);
					_rep(q, 1, poss) {
						if(poss % q) continue;
						ans = ans + 1ll * wjpakioi.query(q * l - 1);
					}
				} else {
					ans = ans + wjpakioi.query(xc - 1);
				}
//				std::cout << ans << "\n";
			}
			writesp(ans, '\n');
//			_rep(i, 1, len) {
//				if(i / (i - nxt[i]) != 1 && i % (i - nxt[i]) == 0) {
//					printf("%d %d %d %d\n", i, nxt[i], i / (i - nxt[i]), i % (i - nxt[i]));
//				}
//			}
//			int k = B[1] - 'a', t2 = 1;
//			_rep(i, 2, len) {
//				if(B[i] - 'a' != k) {
//					t2 = 0; break;
//				}
//			}
//			if(t2) {
//				
//			} else {
//				
//			}
//		}
//		getnxt();
//		_rep(i, 1, len) {
//			if(i % (i - nxt[i]) == 0 && i / (i - nxt[i]) != 1) {
//				printf("%d %d %d\n", nxt[i], i - nxt[i], i / (i - nxt[i]));
//			}
		}
	}
	return 0;
}
