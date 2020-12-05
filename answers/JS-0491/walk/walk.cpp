#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
typedef unsigned long long ull;
typedef long long ll;
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); i++)

int read() {
	char ch = getchar();
	int s = 1, w = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') s = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {w = w * 10 + ch - '0'; ch = getchar();}
	return s * w;
}

int n, k, w[maxn], d[maxn];
int ws[maxn], wdmax[maxn];

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read(), k = read();
	rep(i, 1, k) w[i] = read();
	/*rep(i, 1, n) {
		int c = read();
		d[c] = read();
		ws[c] = ws[c] + d[c];
		wdmax[c] = max(wdmax[c], ws[c]);
	}/*
	/*rep(i, 1, k) {
		if(ws[i] != 0 || wdmax[i] > w[i]) break;
		cout << "-1" << endl;
		return 0;
	}*/
	cout << "-1" << endl;
	return 0;
}
