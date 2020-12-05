#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;

int n, m, cnt[55], col[55][405];
int tpos;
bool ext[55];

vector<int> C;
vector<PII> ans;

void gsplit(int cc, int f, int u, int v)
{
	for(; cnt[f] > 0; cnt[f] --) {
		if(col[f][cnt[f]] == cc) {
			ans.push_back(MP(f, u));
			col[u][++ cnt[u]] = cc;
		} else {
			ans.push_back(MP(f, v));
			col[v][++ cnt[v]] = col[f][cnt[f]];
		}
	}
}
int gcount(int cc, int f)
{
	int ret = 0;
	rep1(i, cnt[f]) ret += col[f][i] == cc;
	return ret;
}
void gupds(int u, int v, int sizu)
{
	while(cnt[u] > sizu) {
		ans.push_back(MP(u, v));
		col[v][++ cnt[v]] = col[u][cnt[u] --];
	}
}

bool gg[55];
void solve(int cc)
{
	vector<int> hv;
	rep1(i, n + 1) if(i != tpos && !ext[i]) hv.push_back(i);
	
	int ccnt = gcount(cc, hv[0]);
	gupds(hv[1], tpos, m - ccnt);
	gsplit(cc, hv[0], hv[1], tpos);
	gupds(tpos, hv[0], ccnt);
	gupds(hv[1], hv[0], m - ccnt);
	gupds(tpos, hv[1], 0);
	gupds(hv[0], tpos, gcount(cc, hv[1]));
	gsplit(cc, hv[1], tpos, hv[0]);
	tpos = hv[1];
	int gpos = hv[0];
	
	rep1(i, n + 1) gg[i] = ext[i];
	gg[gpos] = gg[tpos] = true;
	
	rep1(i, n + 1) if(!gg[i]) {
		gupds(gpos, tpos, m - gcount(cc, i));
		gsplit(cc, i, gpos, tpos);
		gg[i] = true;
		gpos = tpos; tpos = i;
	}
	
	
	rep1(i, n + 1) if(!ext[i] && i != tpos)
	gupds(i, tpos, m - gcount(cc, i));
	
	ext[tpos] = true;
	tpos = hv[0];
	
	rep1(i, n + 1) if(!ext[i] && i != tpos)
	gupds(tpos, i, cnt[tpos] - m + cnt[i]);
}

int main()
{
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	rep1(i, n) {
		cnt[i] = m;
		rep1(j, m) {
			scanf("%d", &col[i][j]);
			C.push_back(col[i][j]);
		}
	}
	sort(C.begin(), C.end());
	C.resize(unique(C.begin(), C.end()) - C.begin());
	rep1(i, n) rep1(j, m) col[i][j] = upper_bound(C.begin(), C.end(), col[i][j]) - C.begin();
	
	tpos = n + 1;
	rep1(i, n - 1) solve(i);
	
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
