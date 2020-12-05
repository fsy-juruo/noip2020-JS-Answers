#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;

#define N (52)
#define M (402)

int n,m;
vector<int> v[N];
vector<pair<int, int> > Ans;

void Clear(int id) {
	int cons = id + 1;
	while ((int)(v[id].size()) > 1) {
		while ((int)(v[cons].size()) == m) {
			cons++;
		}
		Ans.push_back(make_pair(id, cons));
		v[cons].push_back(v[id][(int)v[id].size() - 1]);
		v[id].pop_back();
	}
}

int FindTop(int did, int fid) {
	int bst = (int)v[fid].size() - 1;
	while (bst >= 0) {
		if (v[fid][bst] == v[did][0]) {
			return bst;
		}
		bst--;
	}
	return -1;
}

void RemoveCand(int frnt, int cnd, int toloc) {
	int curloc = (int)v[cnd].size() - 1;
	int cons = frnt;
	while (curloc > toloc) {
		while (true) {
			if (cons == cnd) {
				cons++;
			}
			if ((int)(v[cons].size()) == m) {
				cons++;
			}
			else {
				break;
			}
		}
		Ans.push_back(make_pair(cnd, cons));
		v[cons].push_back(v[cnd][curloc]);
		curloc--;
		v[cnd].pop_back();
	}
}

int MoveToLast(int cnd) {
	int cons = n + 1;
	while ((int)(v[cons].size()) == m) {
		cons--;
		if (cons == cnd) {
			cons--;
		}
	}
	if (cnd == cons) {
		return cons;
	}
	Ans.push_back(make_pair(cnd, cons));
	v[cons].push_back(v[cnd][(int)(v[cnd].size()) - 1]);
	v[cnd].pop_back();
	return cons;
}

void MoveBackCand(int des, int toloc, int todes) {
	int curpos = (int)(v[des].size()) - 1;
	while (curpos >= toloc) {
		Ans.push_back(make_pair(des, todes));
		v[todes].push_back(v[des][curpos]);
		v[des].pop_back();
		curpos--;
	}
}

void MoveCurrent(int des, int frm) {
	Ans.push_back(make_pair(frm, des));
	v[des].push_back(v[des][0]);
	v[frm].pop_back();
}

void MoveAll() {
	while ((int)(v[n + 1].size()) > 0) {
		Ans.push_back(make_pair(n + 1, n));
		v[n + 1].pop_back();
	}
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int tmp;
			scanf("%d", &tmp);
			v[i].push_back(tmp);
		}
	}
	for (int solved = 0; solved < n - 1; solved++) {
		Clear(solved + 1);
		int curup = 1;
		while (curup < m) {
			int candnd = solved + 2;
			int best = -1;
			while (true) {
				best = FindTop(solved + 1, candnd);
				if (best == -1) {
					candnd++;
				}
				else {
					break;
				}
			}
			RemoveCand(solved + 1, candnd, best);
			int strd = MoveToLast(candnd);
			if (strd != candnd) {
				MoveBackCand(solved + 1, curup, candnd);
			}
			if (solved + 1 != strd)			MoveCurrent(solved + 1, strd);
			curup++;
		}
	}
	MoveAll();
	printf("%d\n", (int)Ans.size());
	for (int i = 0; i < (int)Ans.size(); i++) {
		printf("%d %d\n", Ans[i].first, Ans[i].second);
	}
	return 0;
}

