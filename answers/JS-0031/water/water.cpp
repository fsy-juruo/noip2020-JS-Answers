#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	int num = 0;
	while (isdigit(c))
		num = num*10-'0'+c, c=getchar();
	return num;
}
void write(long long num) {
	if (!num) putchar('0');
	int res[30], tot = 0;
	while (num) res[++tot] = num%10, num /= 10;
	for (int i = tot; i >= 0; i--) putchar(res[tot]+'0');
}
long long gcd(long long a, long long b) {
	return b ? gcd(b, a % b) : a;
}
const long long base = 604661760000000000ll;
int nxt[100001][6], deg[100001];
long long res[100001];
int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	int n;
	n = read(), read();
	for (int i = 1; i <= n; i++) {
		nxt[i][0] = read();
		for (int j = 1; j <= nxt[i][0]; j++)
			nxt[i][j] = read(), ++deg[nxt[i][j]];
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!deg[i]) q.push(i), res[i] = base;
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int i = 1; i <= nxt[u][0]; i++) {
			res[nxt[u][i]] += res[u]/nxt[u][0];
			--deg[nxt[u][i]];
			if (!deg[nxt[u][i]]) q.push(nxt[u][i]);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!nxt[i][0]) {
			long long tmp = gcd(res[i], base);
			cout << res[i]/tmp << ' ' << base/tmp << endl;
		}
}
