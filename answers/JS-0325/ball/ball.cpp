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

const int N_MAX = 55;
const int M_MAX = 405;
const int DEP_MAX = 820000;
const int MOD = 19491001;

int n, m;

struct state {
	int val[N_MAX][M_MAX];
	int tops[N_MAX];
	vector<pair<int, int> > ops;
	int dep;
	
	state() {}
	state(const state& s): ops(s.ops), dep(s.dep) {
		memcpy(val, s.val, sizeof(val));
		memcpy(tops, s.tops, sizeof(tops));
	}
	
	void move(int x, int y) {
		val[y][tops[y]++] = val[x][--tops[x]];
		val[x][tops[x]] = 0;
		ops.push_back(make_pair(x + 1, y + 1));
	}
	
	bool check() const {
		int mcnt = 0;
		for (register int i = 0; i <= n; ++i)
			if (tops[i] == m)
				++mcnt;
		if (mcnt != n)
			return false;
		for (register int i = 0; i <= n; ++i) {
			if (!val[i][0])
				continue;
			for (register int j = 1; j < m; ++j)
				if (val[i][j] != val[i][0])
					return false;
		}
		return true;
	}
	
	void print() const {
		register int len = ops.size();
		printf("%d\n", len);
		for (register int i = 0; i < len; ++i)
			printf("%d %d\n", ops[i].first, ops[i].second);
	}

	ull getHash() const {
		ull ans = 0;
		for (register int i = 0; i <= n; ++i)
			for (register int j = 0; j < m; ++j)
				ans = ans * MOD + val[i][j];
		return ans;
	}
};

state ori;
set<ull> st;
int downs[N_MAX];
int shouldPut[N_MAX];

void input() {
	readNum(n);
	readNum(m);
	for (register int i = 0; i < n; ++i) {
		for (register int j = 0; j < m; ++j)
			readNum(ori.val[i][j]);
		ori.tops[i] = m;
	}
}

void preprocess() {
	for (int i = 0; i < n; ++i) {
		int clr = ori.val[i][0];
		downs[i] = 1;
		for (int j = 1; j < m; ++j)
			++downs[i];
	}
	for (int i = 0; i < n; ++i) {
		int maxpos = -1;
		int maxval = 0;
		for (int j = 0; j < n; ++j) {
			if (ori.val[j][0] == i) {
				if (downs[j] > maxval) {
					maxval = downs[j];
					maxpos = j;
				}
			}
		}
		shouldPut[i] = maxpos;
	}
}

void run() {
	queue<state> que;
	que.push(ori);
	while (!que.empty()) {
		state& s = que.front();
		if (st.count(s.getHash())) {
			que.pop();
			continue;
		}
		st.insert(s.getHash());
		
		if (s.check()) {
			s.print();
			return;
		}
		for (register int i = 0; i <= n; ++i) {
			if (s.tops[i] == 0)
				continue;
			const int curClr = s.val[i][s.tops[i] - 1];
			if (shouldPut[curClr] == i && s.tops[i] - 1 <= downs[i])
				continue;
			for (register int j = 0; j <= n; ++j) {
				if (i == j || s.tops[j] == m)
					continue;
				state cur = s;
				cur.move(i, j);
				++cur.dep;
				if (cur.dep <= DEP_MAX)
					que.push(cur);
			}
		}
		que.pop();
	}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	input();
	run();
	return 0;
}
