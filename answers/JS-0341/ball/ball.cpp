#include <bits/stdc++.h>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("ball.in");
ofstream fout("ball.out");
typedef long long lint;
typedef vector<int> vii;
typedef vector<lint> vll;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define pb push_back
#define mp make_pair
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define rep(it, ff, ee) for (int it = (ff); it <= (ee); ++it)
#define per(it, ff, ee) for (int it = (ff); it >= (ee); --it)
int mdzz[55][405], flg[55], dis[55], flg2[55], cmdzz[55][405], Targ[55];
vector<int> opx, opy;
vector<int> nox[55], noy[55];
#define fst first
#define sed second
inline void Move(int x, int y, vii & xx, vii & yy) {
	xx.push_back(x), yy.push_back(y);
	mdzz[y][++mdzz[y][0]] = mdzz[x][mdzz[x][0]--];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	rep (i, 1, n) {
		mdzz[i][0] = m;
		rep (j, 1, m) {
			cin >> mdzz[i][j];
		}
	}
	mdzz[n + 1][0] = 0;
	per (T, n, 2) {
		pii cho = pii(20031025, 20031025);
		rep (cc, 1, n) if (!flg[cc]) {
			memcpy(cmdzz, mdzz, sizeof(mdzz));
			int tar = 0;
			pii ncho = pii(0, cc);
			rep (i, 1, n + 1) if (!flg2[i]) {
				dis[i] = 20031025;
				per (j, mdzz[i][0], 1) {
					if (mdzz[i][j] == cc) {
						dis[i] = mdzz[i][0] - j; break;
					}
				}
				if (mdzz[i][0] == 0) tar = i;
			}
			Targ[cc] = tar;
			nox[cc].clear();
			noy[cc].clear();
			rep (TT, 1, m) {
				vector<pii> vec;
				rep (i, 1, n + 1) if (!flg2[i] && i != tar) {
					vec.pb(pii(dis[i], i));
				}
				sort(all(vec));
				int tot = 0;
				rep (i, 1, SZ(vec) - 1) {
					tot += m - mdzz[vec[i].sed][0];
				}
				if (vec[0].fst > tot) {
					ncho.fst = 20031025; break;
				}
				rep (i, 1, vec[0].fst) {
					while (mdzz[vec.back().sed][0] == m) vec.pop_back();
					Move(vec[0].sed, vec.back().sed, nox[cc], noy[cc]); ++dis[vec.back().sed];
				}
				Move(vec[0].sed, tar, nox[cc], noy[cc]);
				dis[vec[0].sed] = 20031025;
				per (j, mdzz[vec[0].sed][0], 1) {
					if (mdzz[vec[0].sed][j] == cc) {
						dis[vec[0].sed] = mdzz[vec[0].sed][0] - j; break;
					}
				}
			}
			memcpy(mdzz, cmdzz, sizeof(mdzz));
			if (ncho.fst) continue;
			ncho.fst = SZ(nox[cc]);
			cho = min(cho, ncho);
			memcpy(mdzz, cmdzz, sizeof(mdzz));
		}
		rep (i, 0, cho.fst - 1) {
			Move(nox[cho.sed][i], noy[cho.sed][i], opx, opy);
		}
		flg[cho.sed] = 1;
		flg2[Targ[cho.sed]] = 1;
		pii choo = pii(20031025, 20031025);
		rep (i, 1, n + 1) if (!flg2[i]) {
			choo = min(choo, pii(mdzz[i][0], i));
		}
		int fnt = 1;
		while (choo.fst--) {
			while (fnt == choo.sed || mdzz[fnt][0] == m) ++fnt;
			Move(choo.sed, fnt, opx, opy);
		}
	}
	pii choo = pii(20031025, 20031025);
	rep (i, 1, n + 1) if (!flg2[i]) {
		choo = min(choo, pii(mdzz[i][0], i));
	}
	int fnt = 1;
	while (choo.fst--) {
		while (fnt == choo.sed || mdzz[fnt][0] == m) ++fnt;
		Move(choo.sed, fnt, opx, opy);
	}
	cout << SZ(opx) << endl;
	rep (i, 0, SZ(opx) - 1) {
		cout << opx[i] << ' ' << opy[i] << endl;
	}
	return 0;
}
