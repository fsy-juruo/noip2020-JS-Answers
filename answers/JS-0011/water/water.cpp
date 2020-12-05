#include <cstdio>
#include <vector>
#include <algorithm>
//	I love CCF!	(?
//	Let me AK!	(AK T1 is enough to me
using namespace std;
typedef unsigned long long ak;

ak gcd(ak a, ak b) {
	return b == 0 ? a : gcd(b, a % b);
}

inline ak lcf(ak a, ak b) {
	return a / gcd(a, b) * b;
}

class divin {
private:
	ak up, down;
public:
	divin(ak _u = 0, ak _d = 1) {
		up = _u, down = _d;
		simple();
	}
	inline void set(ak _u, ak _d) {
		up = _u, down = _d;
		simple();
	}
	inline void simple() {
		register ak sim = gcd(up, down);
		if(sim != 1) {
			up /= sim;
			down /= sim;
		}
	}
	inline void print() {
		printf("%llu %llu\n", up, down);
	}
	divin operator + (divin add) {
		if(add.down == down) {
			return divin(add.up + up, down);
		}
		else {
			ak fac = lcf(add.down, down);
			return divin(add.up * (fac / add.down) + up * (fac / down), fac);
		}
	}
	void operator = (divin eq) {
		up = eq.up;
		down = eq.down;
		simple();
	}
	divin operator / (int x) {
		return divin(up, down * x);
	}
};

divin d[100001];

inline void read(int &x) {
	x = 0;
	register char ch = getchar();
	do {
		x = (x << 3) + (x << 1) + (ch ^ '0');
		ch = getchar();
	} while(ch >= '0' && ch <= '9');
}

int n, m;
vector<int> a[100001], endd;

void sol(int x) {
	register int son = a[x].size();
	if(son == 0) {
		return;
	}
	divin send = (son == 1? d[x] : d[x] / son);
	for(register int i = 0; i < son; ++i) {
		d[a[x][i]] = d[a[x][i]] + send;
	}
	d[x].set(0, 1);
	for(register int i = 0; i < son; ++i) {
		sol(a[x][i]);
	}
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	read(n), read(m);
	for(register int i = 1; i <= n; ++i) {
		int tot;
		read(tot);
		if(tot == 0) {
			endd.push_back(i);
			continue;
		}
		for(register int j = 1; j <= tot; ++j) {
			int tar;
			read(tar);
			a[i].push_back(tar);
		}
	}
	for(register int i = 1; i <= m; ++i) {
//		d[i].set(1, 1);
		a[0].push_back(i);
	}
	d[0] = m;
	sol(0);
	int sons = endd.size();
	for(register int i = 0; i < sons; ++i) {
		d[endd[i]].print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
