#include<bits/stdc++.h>
using namespace std;

template<class T> inline void readNum(T& num) {
	num = 0; register char c = getchar(); bool neg = false;
	while (!isdigit(c)) { if (c == '-') neg = true; c = getchar(); }
	while (isdigit(c)) { num = num * 10 + c - '0'; c = getchar(); }
	if (neg) num = ~num + 1;
}

#define ll long long
#define ull unsigned long long
#define CLEAR_ARRAY(x) memset(x, 0, sizeof(x))

const int N_MAX = 500005;
const int K_MAX = 11;
const int MOD = 1000000007;

int n, k;
ll ans;
pair<int, int> movements[N_MAX];
int totalMoves[K_MAX];
int w[K_MAX];
int pos[K_MAX];
int curPos[K_MAX];
int posCheck[K_MAX];
int minCheck[K_MAX];
int maxCheck[K_MAX];

void input() {
	readNum(n);
	readNum(k);
	for (register int i = 1; i <= k; ++i)
		readNum(w[i]);
	int c, d;
	for (register int i = 0; i < n; ++i) {
		readNum(c); readNum(d);
		movements[i] = make_pair(c, d);
	}
}

bool checkPlan() {
	for (register int i = 0; i < n; ++i) {
		const int c = movements[i].first; const int d = movements[i].second;
		posCheck[c] += d;
		minCheck[c] = min(minCheck[c], posCheck[c]);
		maxCheck[c] = max(maxCheck[c], posCheck[c]);
	}
	for (register int i = 1; i <= k; ++i)
		if (posCheck[i])
			return true;
	for (register int i = 1; i <= k; ++i)
		if (maxCheck[i] - minCheck[i] > w[i])
			return true;
	return false;
}

bool check() {
	for (register int i = 1; i <= k; ++i)
		if (curPos[i] < 0 || curPos[i] >= w[i])
			return false;
	return true;
}

void runSingle() {
	memcpy(curPos, pos, sizeof(pos));
	for (int i = 0;; i = (i + 1) % n) {
		curPos[movements[i].first] += movements[i].second;
		ans = (ans + 1) % MOD;
		if (!check())
			return;
	}
}

void dfs(int p) {
	if (p == k + 1)
		runSingle();
	else {
		for (int i = 0; i < w[p]; ++i) {
			pos[p] = i;
			dfs(p + 1);
		}
	}
}

void run() {
	if (!checkPlan())
		puts("-1");
	else {
		dfs(1);
		printf("%lld", ans);
	}
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	input();
	run();
	return 0;
}
