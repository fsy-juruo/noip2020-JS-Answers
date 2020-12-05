#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXN = 100005, MAXD = 10;

struct node {
	long long a, b;
	int d, to[MAXD];
	bool isBegin, isFinal;
};

int n, m;
node nodes[MAXN];

long long gcd(long long a, long long b) {
	return a % b == 0 ? b : gcd(b, a % b);
}

void Update(int k) {
	int g = gcd(nodes[k].a, nodes[k].b);
	nodes[k].a /= g; nodes[k].b /= g;
}

void Add(int from, int to) {
	nodes[to].a = nodes[from].a * nodes[to].b + nodes[to].a * nodes[from].b;
	nodes[to].b = nodes[from].b * nodes[to].b;
	Update(to);
}

int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		nodes[i].isBegin = true; nodes[i].isFinal = false;
		nodes[i].a = 0; nodes[i].b = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		int d, to;
		scanf("%d", &d);
		nodes[i].d = d;
		if (d == 0) nodes[i].isFinal = true;
		for (int j = 1; j <= d; j++) {
			scanf("%d", &to);
			nodes[i].to[j] = to;
			nodes[to].isBegin = false;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (nodes[i].isBegin) {
			nodes[i].a = 1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!nodes[i].isFinal) {
			nodes[i].b *= nodes[i].d; Update(i);
			for (int j = 1; j <= nodes[i].d; j++) {
				Add(i, nodes[i].to[j]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (nodes[i].isFinal) printf("%lld %lld\n", nodes[i].a, nodes[i].b);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
