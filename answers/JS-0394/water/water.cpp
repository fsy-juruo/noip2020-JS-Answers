#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 1e5 + 10;

int n , m;
LL p[N] , q[N];
int rd[N];
bool ps[N];
int d[N];
LL g;

template <typename T> void read(T &x) {
	x = 0; T f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	x *= f;
}

template <typename T> void chkmax(T &x , T y) {x = x > y ? x : y; }
template <typename T> void chkmin(T &x , T y) {x = x < y ? x : y; }

template <typename T> void print(T x) {
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void write(T x , char c) {
	if (x < 0) {x = -x; putchar('-'); }
	print(x);
	putchar(c);
}

struct node{
	int nxt , t;
} edge[N * 5];
int Head[N] , cnt;

void addedge(int u , int v) {
	edge[++cnt].nxt = Head[u];
	edge[cnt].t = v;
	Head[u] = cnt;
}

queue < int > dl;

LL gcd(LL a , LL b) {
	if (b) return gcd(b , a % b);
	return a;
}

void add(int x , int y) {
	g = gcd(p[x] , p[y]);
	LL l = p[y];
	p[y] = (p[x] / g) * p[y];
	q[y] = q[x] * (l / g) + q[y] * (p[x] / g);
	g = gcd(p[y] , q[y]);
	p[y] /= g; q[y] /= g;
	return;
}

void SPFA() {
	for (int i = 1; i <= n; i++) if (!rd[i]) dl.push(i);
	while(!dl.empty()) {
		int u = dl.front(); dl.pop(); 
		if (!d[u]) continue;
		LL t = p[u] * d[u];
		g = gcd(t , q[u]);
		q[0] = q[u] / g;
		p[0] = t / g;
		for (int i = Head[u]; i; i = edge[i].nxt) {
			int v = edge[i].t;
			add(0 , v);
			rd[v]--;
			if (!rd[v]) dl.push(v);
		}
	}
}

int main() {

	freopen("water.in" , "r" , stdin);
	freopen("water.out" , "w" , stdout);

	read(n); read(m);
	
	for (int i = 1; i <= n; i++) {
		int v;
		read(d[i]);
		for (int j = 1; j <= d[i]; j++) {
			read(v);
			addedge(i , v);
			rd[v]++;
		}
		p[i] = 1;
	}
	
	for (int i = 1; i <= m; i++) q[i] = 1;
	
	SPFA();
	
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			write(q[i] , ' '); write(p[i] , '\n');
		}
	}

	return 0;

}

