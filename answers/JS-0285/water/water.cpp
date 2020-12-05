#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define N (100007)

long long GCD(long long gx, long long gy) {
	if (gx < gy) {
		swap(gx, gy);
	}
	if (gy == 0LL) {
		return gx;
	}
	return GCD(gx % gy, gy);
}

class FRAC {
	public:
	long long xx, yy;
	FRAC() {
		xx = 0LL;
		yy = 1LL;
	}
	FRAC operator+(const FRAC& pp) {
		FRAC res;
		res.xx = xx * pp.yy + yy * pp.xx;
		res.yy = yy * pp.yy;
		long long ggc = GCD(res.xx, res.yy);
		res.xx /= ggc;
		res.yy /= ggc;
		return res;
	}
	FRAC operator*(const FRAC& pp) {
		FRAC res;
		res.xx = xx * pp.xx;
		res.yy = yy * pp.yy;
		long long ggc = GCD(res.xx, res.yy);
		res.xx /= ggc;
		res.yy /= ggc;
		return res;
	}
};

int n,m;
int cnt[N];
FRAC Ans[N];
vector<int> v[N];

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int tmp;
		scanf("%d", &tmp);
		while (tmp--) {
			int tid;
			scanf("%d", &tid);
			v[i].push_back(tid);
			cnt[tid]++;
		}
	}
	queue<int> Q;
	for (int i = 1; i <= m; i++) {
		Ans[i].xx = 1LL;
		Ans[i].yy = 1LL;
		Q.push(i);
	}
	for (int i = m + 1; i <= n; i++) {
		Ans[i].xx = 0LL;
		Ans[i].yy = 1LL;
	}
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		int ncc = (int)(v[cur].size());
		if (ncc == 0) {
			continue;
		}
		FRAC fca;
		fca.xx = 1LL;
		fca.yy = (long long)(ncc);
		fca = fca * Ans[cur];
		for (int i = 0; i < ncc; i++) {
			int nxt = v[cur][i];
			Ans[nxt] = Ans[nxt] + fca;
			cnt[nxt]--;
			if (cnt[nxt] == 0) {
				Q.push(nxt);
			}
		}
		Ans[cur].xx = 0LL;
		Ans[cur].yy = 1LL;
	}
	for (int i = 1; i <= n; i++) {
		if ((int)(v[i].size()) == 0) {
			long long fgc = GCD(Ans[i].xx, Ans[i].yy);
			Ans[i].xx /= fgc;
			Ans[i].yy /= fgc;
			printf("%lld %lld\n", Ans[i].xx, Ans[i].yy);
		}
	}
	return 0;
}

