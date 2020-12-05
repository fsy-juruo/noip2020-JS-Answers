#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define Fre(name) freopen(#name".in", "r", stdin),\
				  freopen(#name".out", "w", stdout)
using namespace std;

const LL N = 5e5 + 55, K = 11, Mod = 1e9 + 7;

LL n, k;

struct node { //Ïà¶Ô×ø±ê 
	LL w[K];
	const node operator+(node b) {
		for (LL i = 1; i <= k; ++i)
			w[i] += b.w[i];
	}
	bool empty() {
		for (LL i = 1; i <= k; ++i)
			if (!w[i]) return false;
		return true;
	}
}place, walkpath, maxwp;

int main() {
	Fre(walk);
	cin >> n >> k;
	for (LL i = 1; i <= k; ++i)
		cin >> place.w[i];
	for (LL i = 1; i <= n; ++i) {
		LL c, d;
		cin >> c >> d;
		walkpath.w[c] += d;
		maxwp.w[c] = max(maxwp.w[c], walkpath.w[c]);
	}
	if (walkpath.empty()) {
		for (int i = 1; i <= k; ++i)
			if (place.w[i] < maxwp.w[i]) goto Break;
		cout << "-1" << endl;
	}
	Break:;
	
	return 0;
}

