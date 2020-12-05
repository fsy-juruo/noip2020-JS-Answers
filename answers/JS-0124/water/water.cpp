#include<bits/stdc++.h>
typedef int MRT;
#define int long long
using namespace std;
int n, m, in[500010], out[500010], fp[500010], fq[500010], t, x;
vector<int> v[500010], outs;
inline int read() {
	int n; char c;
	while(!isdigit(c = getchar())); n = c - '0';
	while( isdigit(c = getchar()))  n = n * 10 + c - '0';
	return n;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void frac_add(int &p1, int &q1, int p2, int q2) {
	int p3 = p1 * q2 + p2 * q1, q3 = q1 * q2;
	int t = gcd(p3, q3);
	p1 = p3 / t, q1 = q3 / t;
}
MRT main() {
	freopen("water.in",  "r", stdin);
	freopen("water.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		v[i].resize(out[i] = read());
		for(int j = 0; j < out[i]; j++) in[v[i][j] = read()]++;
		if(!out[i]) outs.push_back(i);
	}
	queue<int> q; 
	for(int i = 1; i <= n; i++) {
		fq[i] = 1;
		if(!in[i]) q.push(i), fp[i] = 1;
	}
	while(!q.empty()) {
		t = q.front(), q.pop();
		for(int i = 0; i < v[t].size(); i++) {
			x = v[t][i];
			frac_add(fp[x], fq[x], fp[t], fq[t] * out[t]);
			if(--in[x] == 0) q.push(x);
		}
	}
	for(int i = 0; i < outs.size(); i++) {
		t = gcd(fp[outs[i]], fq[outs[i]]);
		printf("%lld %lld\n", fp[outs[i]] / t, fq[outs[i]] / t);
	}
}

