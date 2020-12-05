#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F *= R;
}
const int M = 1e5 + 10;
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
struct node{
	long long fz, fm;
	void tf() {
		long long gi = gcd(fz, fm);
		fz /= gi, fm /= gi;
	}
	friend node operator * (const node &a, const node &b) {
		if(a.fz == 0 || b.fz == 0) {
			node ti; ti.fz = 0; ti.fm = 1;
			return ti;
		}
		long long gx = gcd(a.fz, b.fm), gy = gcd(a.fm, b.fz);
		node res; res.fz = (a.fz / gx) * (b.fz / gy);
		res.fm = (a.fm / gy) * (b.fm / gx);
		return res;
	}
	friend node operator + (const node &a, const node &b) {
		if(a.fz == 0) return b;
		if(b.fz == 0) return a;
		node res; long long gi = gcd(a.fm, b.fm);
		res.fm = a.fm / gi * b.fm;
		res.fz = b.fm / gi * a.fz + a.fm / gi * b.fz;
		res.tf();
		return res;
	}
	void print() {
		cout << fz << " " << fm << endl;
	}
}wt[M];
node make_node(int fz, int fm) {
	node ti; ti.fz = fz, ti.fm = fm;
	return ti;
}
const int N = 1e6 + 10;
int now, fst[N], nxt[N], num[N], rd[M], n, m, flag[M], cd[N];
void add(int u, int v) {
	nxt[++now] = fst[u], fst[u] = now, num[now] = v;
}
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n), read(m); int di, u, v;
	for(int i = 1; i <= n; i++) {
		read(di); if(di == 0) flag[i] = 1; cd[i] = di;
		for(int j = 1; j <= di; j++)
			read(v), add(i, v), rd[v]++;
	}
	stack<int> qi;
	for(int i = 1; i <= m; i++)
		wt[i] = make_node(1, 1);
	for(int i = m + 1; i <= n; i++)
		wt[i] = make_node(0, 1);
	for(int i = 1; i <= n; i++)
		if(rd[i] == 0) qi.push(i);
	while(!qi.empty()) {
		int pi = qi.top(); qi.pop();
		node ad = make_node(1, cd[pi]) * wt[pi];
		for(int i = fst[pi]; i; i = nxt[i]) {
			wt[num[i]] = wt[num[i]] + ad;
			rd[num[i]]--;
			if(rd[num[i]] == 0) qi.push(num[i]);
		}
	}
	for(int i = 1; i <= n; i++)
		if(flag[i]) wt[i].print();
	return 0;
}

