#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;

int n,m;
vector <int> g[N];
queue <int> q;
int fm[N] , fz[N];


int read() {
	char ch = getchar();
	int sum = 0 , w = 1;
	while(! isdigit(ch)) {
		if(ch == '-') {
			w = -1;
		}
		ch = getchar();
	}
	while(isdigit(ch)) {
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum * w;
}

int gcd(int a , int b) {
	if(a < b) {
		swap(a , b);
	}
	if(a == b || b == 0) {
		return a;
	}
	return gcd(a % b , b);
}
void add(int x , int a , int b) {
	int lcm = fm[x] / gcd(fm[x] , a) * a;
	fz[x] *= lcm / fm[x];
	fm[x] = lcm;
	fz[x] += b * (lcm / a);
}
void solve() {
	memset(fz , 0 , sizeof(fz));
	fz[m] = 1;
	q.push(m);
	while(! q.empty()) {
		int x = q.front();
		q.pop();
		if(fz[x] == 0) {
			continue;
		}
		int siz = g[x].size();
		for(int i=0; i<siz; ++i) {
			add(g[x][i] , fm[x] * siz , fz[x]);
			q.push(g[x][i]);
		}
		if(siz) {
			fz[x] = 0;
		}
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read() , m = read();
	for(int i=1; i<=n; ++i) {
		int c , d;
		c = read();
		fm[i] = 1;
		for(int j=1; j<=c; ++j) {
			d = read();
			g[i].push_back(d);
		}
	}
	solve();
	for(int i=1; i<=n; ++i) {
		if(fz[i] != 0) {
			int gc = gcd(fz[i] , fm[i]);
			printf("%d %d\n",fz[i] / gc , fm[i] / gc);
		}
	}
	return 0;
}

