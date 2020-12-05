#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define Fre(name) freopen(#name".in", "r", stdin),\
				  freopen(#name".out", "w", stdout)
using namespace std;

const int N = 1e5 + 55, M = 1e7 + 55;

int gcd(int m, int n) {
	return (m == 0) ? n : gcd(n % m, m);
}

int lcm(int m, int n) {
	return m / gcd(m, n) * n;
}

struct SepNum {
	int SepSon, SepMoth;
	SepNum(int n = 0, int m = 1) {
		SepSon = n;
		SepMoth = m;
	}
	void Set(int n = 0, int m = 1) {
		this -> SepSon = n; this -> SepMoth = m;
	}
	void ReFresh() {
		int t = gcd(this -> SepSon, this -> SepMoth);
		this -> SepSon /= t;
		this -> SepMoth /= t;
	}
}Ans[N];


SepNum equal(SepNum &a, SepNum b)  {
	a.SepSon = b.SepSon;
	a.SepMoth = b.SepMoth;
	return a;
}
SepNum add(SepNum a, SepNum b){
	int l = lcm(a.SepMoth, b.SepMoth);
	SepNum c;
	c.Set(a.SepSon * (l / a.SepMoth) + b.SepSon * (l / b.SepMoth), l);
	return c;
}

SepNum addequal (SepNum &a, SepNum b)  {
	equal(a, add(a, b));
	return a;
}

int n, m, In[N];
vector < int > nxt[N];
bool in[N];

struct node {
	int x;
};

void bfs(vector < int > s) {
	queue < node > q;
	for (vector < int > :: iterator it = s.begin(); it != s.end(); ++it) {
		Ans[*it].Set(1, 1);
		q.push({*it});
		in[*it] = true;
	}
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		SepNum dw;
		dw.Set(Ans[now.x].SepSon, Ans[now.x].SepMoth * nxt[now.x].size());
		Ans[now.x].Set();
		in[now.x] = false;
		dw.ReFresh();
		for (vector < int > :: iterator it = nxt[now.x].begin(); it != nxt[now.x].end(); ++it) {
			addequal(Ans[*it], dw);
			Ans[*it].ReFresh();
			if (!in[*it] && !nxt[*it].empty()) {
				q.push({*it});
				in[*it] = true;
			}
		}
	}
}

int main() {
	Fre(water);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int d;
		cin >> d;
		for (int j = 1; j <= d; ++j) {
			int v;
			cin >> v;
			nxt[i].push_back(v);
			++In[v];
		}
	}
	vector < int > s;
	for (int i = 1; i <= n; ++i) {
		if (!In[i]) {
			s.push_back(i);
		}
	}
	bfs(s);
	for (int i = 1; i <= n; ++i) {
		if (nxt[i].empty()) {
			Ans[i].ReFresh();
			cout << Ans[i].SepSon << " " << Ans[i].SepMoth << endl;
		}
	}
	return 0;
}

