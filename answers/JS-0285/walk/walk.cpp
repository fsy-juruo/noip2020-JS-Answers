#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define MOD (1000000007LL)

int n, k;
vector<int> w;
vector<pair<int, int> > wk;

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int tmp;
		scanf("%d", &tmp);
		w.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		wk.push_back(make_pair(t1, t2));
	}
	if (k == 1) {
		long long Ans = 0LL;
		map<int, int> mp;
		int curx = 0;
		for (int i = 0; i < n; i++) {
			curx += wk[i].second;
			if (mp.find(curx) == mp.end()) {
				mp[curx] = i;
			}
		}
		for (int xx = 0; xx < w[0]; xx++) {
			int ll = xx + 1;
			int rr = w[0] - xx;
			if (mp.find(ll) == mp.end()) {
				if (mp.find(rr) == mp.end()) {
					printf("-1\n");
					return 0;
				}
				else {
					Ans += mp[rr];
				}
			}
			else {
				if (mp.find(rr) == mp.end()) {
					Ans += mp[ll];
				}
				else {
					Ans += min(mp[ll], mp[rr]);
				}
			}
		}
		printf("%lld\n", Ans % MOD);
		return 0;
	}
	else if (n <= 100) {
		vector<int> curpos;
		for (int i = 0; i < k; i++) {
			curpos.push_back(0);
		}
		long long Ans = 0LL;
		while (true) {
			vector<int> ppos;
			for (int i = 0; i < k; i++) {
				ppos.push_back(curpos[i]);
			}
			int bbreak = 0;
			for (int ccnt = 0; ccnt <= n + 1; ccnt++) {
				for (int i = 0; i < n; i++) {
					ppos[wk[i].first - 1] += wk[i].second;
					if (ppos[wk[i].first - 1] < 0 || ppos[wk[i].first - 1] >= w[wk[i].first - 1]) {
						bbreak = 1;
						break;
					}
					Ans++;
					Ans %= MOD;
				}
				if (bbreak) {
					break;
				}
			}
			if (!bbreak) {
				printf("-1\n");
				return 0;
			}
			int nxt = k - 1;
			while (nxt >= 0 && curpos[nxt] == w[nxt] - 1) {
				nxt--;
			}
			if (nxt == -1) {
				break;
			}
			curpos[nxt]++;
			for (int i = nxt + 1; i < k; i++) {
				curpos[i] = 0;
			}
		}
		printf("%lld\n", Ans);
		return 0;
	}
	else {
		printf("-1\n");
		return 0;
	}
	return 0;
}

