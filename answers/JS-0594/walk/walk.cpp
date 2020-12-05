#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const int P = 1e9 + 7;
inline int read() {
	int f=1,x=0;char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) if(ch=='-') f=0;
	for(; isdigit(ch); ch=getchar()) x=x*10+ch-'0';
	return f?x:-x;
}

int n, k;
int w[20];
int a[20], b[20];
ll p=1;
ll ans;
int c[N], d[N];

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1; i <= k; i ++) {
		w[i] = read();
		p *= w[i];
	}
	for(int i = 1; i <= n; i ++)
		c[i] = read(), d[i] = read();
	for(int i = 1; i <= k; i ++)
		a[i] = 1;
	for(int i = 1; i <= p; i ++) {
		for(int j = 1; j <= k; j ++)
			b[j] = a[j];
		int j = 1;
		while(1) {
			b[c[j]] += d[j];
			ans ++;
			ans %= P;
			if(b[c[j]] <= 0 || b[c[j]] > w[c[j]]) break;
			j ++;
			if(j == n+1) j = 1;
		}
		int id = k;
		a[id] ++;
		while(a[id] > w[id]) {
			a[id] = 1;
			id --;
			a[id] ++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

