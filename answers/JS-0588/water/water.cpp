#include<bits/stdc++.h>
using namespace std;
inline void read(int &x) {
	x = 0;
	register char c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
}
long long gcd(long long m,long long n) {
	if(!n)
		return m;
	return gcd(n,m % n);
}
struct node {
	int v,next;
} a[200005];
int n,m,k,cnt,head[100005];
long long fenzi[100005],fenmu[100005],d[100005];
inline void add(int u,int v) {
	a[++cnt].v = v;
	a[cnt].next = head[u];
	head[u] = cnt;
}
void dfs(int u) {
	for(register int i = head[u]; i; i = a[i].next) {
		fenzi[a[i].v] = fenzi[a[i].v] * d[u] * fenmu[u] + fenmu[a[i].v] * fenzi[u];
		fenmu[a[i].v] *= fenmu[u] * d[u];
		if(fenzi[a[i].v]) {
			register long long _gcd = gcd(fenzi[a[i].v],fenmu[a[i].v]);
			fenzi[a[i].v] /= _gcd;
			fenmu[a[i].v] /= _gcd;
		}
		dfs(a[i].v);
	}
	if(d[u]) {
		fenzi[u] = 0;
		fenmu[u] = 1;
	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);
	read(m);
	for(int i = 1; i <= n; ++i) {
		fenmu[i] = 1;
		read(k);
		d[i] = k;
		for(int j = 1; j <= d[i]; ++j) {
			read(k);
			add(i,k);
		}
	}
	for(int i = 1; i <= m; ++i) {
		fenzi[i] += fenmu[i];
		dfs(i);
	}
	for(int i = 1; i <= n; ++i)
		if(!d[i])
			if(!fenzi[i])
				printf("0 0\n");
			else
				printf("%lld %lld\n",fenzi[i],fenmu[i]);
	return 0;
}
