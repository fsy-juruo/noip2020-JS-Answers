/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for(int i = 0; i < (a); ++i)
#define cont(i, a) for(int i = 1; i <= (a); ++i)
#define circ(i, a, b) for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for(int i = (a); (c) > 0 ? (i <= (b)) : (i >= (b)); i += c)
#define foreach(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); ++it)
#define pub push_back
#define pob pop_back
#define mak make_pair
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

const int bl = 8;
int n, m;
vector<pair<int, int> > op;
vector<int> a[55];

void inline move(int f, int t) {
	if(f == t) return;
	assert(SZ(a[f]));
	a[t].pub(a[f].back()); a[f].pob(); assert(SZ(a[t]) <= m);
	op.pub(mak(f, t));
}

bool inline inr(int x, int l, int r) {
	return x >= l && x <= r;
}

void inline debug(int col) {
	loop(i, SZ(a[col])) cerr<<a[col][i]<<' ';
	cerr<<endl;
}

int main() {
	#ifndef HCl10
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	cont(i, n) cont(j, m) {
		int val;
		scanf("%d", &val);
		a[i].pub(val);
	}
	int bls = (n + bl - 1) / bl;
	cont(B, bls - 1) {
		int L = bl * (B - 1) + 1, R = min(bl * B, n);
		vector<int> zh, ln;
		circ(i, L, n) {
			int cnt1 = 0, cnt2 = 0, rev = 0, cnt;
			loop(j, m) if(inr(a[i][j], L, R)) ++cnt1; else ++cnt2;
			cnt = cnt1;
			if(cnt1 > cnt2) rev = 1, swap(cnt1, cnt2);
			if(i != n) {
				while(SZ(a[n]) > m - cnt1) move(n, n + 1);
				while(SZ(a[n]) < m - cnt1) move(n + 1, n);
				while(SZ(a[i])) {
					if(inr(a[i].back(), L, R)) {
						if(rev) move(i, n + 1);
						else move(i, n);
					} else {
						if(rev) move(i, n);
						else move(i, n + 1);
					}
				}
				if(i >= L && i <= R) {
					if(rev) cont(j, cnt2) move(n + 1, i);
					else cont(j, cnt1) move(n, i);
					if(rev) cont(j, cnt1) move(n, i);
					else cont(j, cnt2) move(n + 1, i);
					zh.pub(cnt);
				} else {
					if(rev) cont(j, cnt1) move(n, i);
					else cont(j, cnt2) move(n + 1, i);
					if(rev) cont(j, cnt2) move(n + 1, i);
					else cont(j, cnt1) move(n, i);
					ln.pub(cnt);
				}
			} else {
				while(SZ(a[n + 1])) move(n + 1, n);
				while(SZ(a[n - 1]) > m - cnt1) move(n - 1, n + 1);
				while(SZ(a[n - 1]) < m - cnt1) move(n + 1, n - 1);
				while(SZ(a[i])) {
					if(inr(a[i].back(), L, R)) {
						if(rev) move(i, n + 1);
						else move(i, n - 1);
					} else {
						if(rev) move(i, n - 1);
						else move(i, n + 1);
					}
				}
				if(i >= L && i <= R) {
					if(rev) cont(j, cnt2) move(n + 1, i);
					else cont(j, cnt1) move(n - 1, i);
					if(rev) cont(j, cnt2) move(n - 1, i);
					else cont(j, cnt1) move(n + 1, i);
					zh.pub(cnt);
				} else {
					if(rev) cont(j, cnt1) move(n - 1, i);
					else cont(j, cnt2) move(n + 1, i);
					if(rev) cont(j, cnt1) move(n + 1, i);
					else cont(j, cnt2) move(n - 1, i);
					ln.pub(cnt);
				}
				while(SZ(a[n + 1])) move(n + 1, n - 1);
			}
		}
		int nl = L, nr = R + 1;
		int sm = 0;
		while(nl <= R) {
			int rm = 0;
			loop(i, zh[nl - L]) move(nl, n + 1);
			while(ln[nr - R - 1] <= zh[nl - L]) {
				loop(i, ln[nr - R - 1]) move(nr, nl), ++rm;
				zh[nl - L] -= ln[nr - R - 1];
				ln[nr - R - 1] = 0;
				++nr;
			}
			loop(i, zh[nl - L]) move(n + 1, nl);
			loop(i, ln[nr - R - 1]) move(nr, n + 1);
			loop(i, zh[nl - L]) move(nl, nr);
			loop(i, zh[nl - L]) move(n + 1, nl);
			ln[nr - R - 1] -= zh[nl - L];
			loop(i, ln[nr - R - 1]) move(n + 1, nr);
		}
	}
	cont(B, bls) {
		int L = bl * (B - 1) + 1, R = min(bl * B, n);
		if(L == R) continue;
		circ(i, L, R - 1) {
			circ(j, i, R) {
				int cnt1 = 0, cnt2 = 0, rev = 0, cnt;
				loop(k, m) if(inr(a[j][k], i, i)) ++cnt1; else ++cnt2;
				cnt = cnt1;
				if(cnt1 > cnt2) rev = 1, swap(cnt1, cnt2);
				int sh = j + 1;
				if(sh == R + 1) {
					if(i == L) sh = i;
					else sh = L - 1;
				}
				while(SZ(a[sh]) > m - cnt1) move(sh, n + 1);
				while(SZ(a[sh]) < m - cnt1) move(n + 1, sh);
				
				while(SZ(a[j])) {
					if(inr(a[j].back(), i, i)) {
						if(rev) move(j, n + 1);
						else move(j, sh);
					} else {
						if(rev) move(j, sh);
						else move(j, n + 1);
					}
				}
				if(j == i) {
					if(rev) cont(j, cnt2) move(n + 1, i);
					else cont(j, cnt1) move(sh, i);
					if(rev) {
						cont(j, cnt1) move(sh, i);
					} else cont(j, cnt2) move(n + 1, i);
				} else {
					int us = sh, ul = n + 1;
					if(rev) swap(us, ul);
					while(a[i].back() != i) move(i, j);
					cont(k, cnt) move(us, i);
					
					cont(k, m - cnt) {
						if(SZ(a[j]) < m) move(ul, j);
						else move(ul, i);
					}
				}
				while(SZ(a[n + 1])) if(SZ(a[sh]) < m) move(n + 1, sh); else move(n + 1, j);
				int cc = 0;
				while(a[i].back() != i) move(i, n + 1), ++cc;
				while(cc--) move(j, i);
				while(SZ(a[n + 1])) move(n + 1, j);
			}
		}
	}
	printf("%d\n", SZ(op));
	loop(i, SZ(op)) printf("%d %d\n", op[i].first, op[i].second);
	return 0;
}
