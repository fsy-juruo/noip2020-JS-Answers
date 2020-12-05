#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F) {
	F = 0; int R = 1; char CH = getchar();
	for(; !isdigit(CH); CH = getchar()) if(CH == '-') R = -1;
	for(; isdigit(CH); CH = getchar()) F = F * 10 + CH - 48;
	F *= R;
}
const int N = 5e5 + 10;
int di[N], n, wi[N], bs[N], ci[N], ti[N], lmax[N], rmax[N], prev[N], k, to;
int qw(int x, int c) {
	return (x % prev[c + 1]) / prev[c]; 
}
int walk(int x, int c) {
	return x + prev[ci[c]] * di[c];
}
int walka(int x, int c) {
	to = qw(x, ci[c]);
	to += di[c];
	if(to > wi[ci[c]] || to < 1) return false;
	return true;
}
int check(int x) {
	for(int i = 1 ; i <= k; i++)
		if(qw(x, i) < 1 || qw(x, i) > wi[i]) return false;
	return true;
}
int solve(int x) {
	if(bs[x] != -1) return bs[x];
	int xi = x;
	for(int i = 1; i <= n; i++) {
		//x = walk(x, i);
		if(!walka(x, i)) {
			bs[xi] = i;
			return bs[xi];
		}
		x = walk(x, i);
	}
	bs[xi] = n + solve(x);
	return bs[xi];
} 
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	read(n), read(k); prev[1] = 1;
	for(int i = 1; i <= k; i++) read(wi[i]), prev[i + 1] = prev[i] * (wi[i] + 1);
	for(int i = 1; i <= n; i++) {
		read(ci[i]), read(di[i]);
		ti[ci[i]] += di[i];
		lmax[ci[i]] = max(lmax[ci[i]], -ti[ci[i]]);
		rmax[ci[i]] = max(rmax[ci[i]], ti[ci[i]]);
	}
	int flag = 0;
	for(int i = 1; i <= k; i++)
		if(ti[i] != 0) {
			flag = 1;
			break;
		}
	if(!flag) {
		for(int i = 1; i <= k; i++)
			if(lmax[i] + rmax[i] + 1 > wi[i]) {
				flag = 1; break;
			}
		if(!flag) {
			puts("-1");
			return 0;
		}
	}
	memset(bs, -1, sizeof(bs));
	int maxx = 0, minn = 0;
	for(int i = 1; i <= k; i++)
		maxx += wi[i] * prev[i], minn += 1 * prev[i];
	int res = 0;
	for(int i = minn; i <= maxx; i++)
		if(check(i))
		res += solve(i);
	cout << res << endl;
	return 0;
}

