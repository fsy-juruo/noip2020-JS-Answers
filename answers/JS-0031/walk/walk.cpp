#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int read() {
	char c = getchar();	
	while (c != '-' && !isdigit(c)) c = getchar();
	int neg = 0, num = 0;
	if (c == '-') neg = 1, c = getchar();
	while (isdigit(c))
		num = num*10-'0'+c, c=getchar();
	return neg?-num:num;
}
int power(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		n >>= 1;
	}
	return ans;
}
int w[11], c[500001], d[500001], vol = 1, ans;
int lb[11], rb[11], ml[11], mr[11], res[12];
void work(int n, int k) {
	for (int i = 1; i <= n && vol; i++) {
		ans = (ans + vol) % mod;
		lb[c[i]] -= d[i], rb[c[i]] -= d[i];
		ml[c[i]] = max(ml[c[i]], lb[c[i]]);
		mr[c[i]] = min(mr[c[i]], rb[c[i]]);
		vol = 1;
		for (int j = 1; j <= k; j++) {
			if (mr[j] < ml[j]) vol = 0;
			else vol = 1ll*vol*(mr[j]-ml[j]+1)%mod;
		}
	}
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int n, k;
	n = read(), k = read();
	for (int i = 1; i <= k; i++) w[i] = read(), vol = 1ll*vol*w[i]%mod;
	for (int i = 1; i <= n; i++) c[i] = read(), d[i] = read();
	for (int i = 1; i <= k; i++) lb[i] = ml[i] = 1, rb[i] = mr[i] = w[i];
	work(n, k);
	if (!vol) {
		cout << ans << endl;
		return 0;
	}
	int dir[11], tmp = 0;
	for (int i = 1; i <= k; i++) {
		dir[i] = lb[i]-1;
		if (dir[i]) tmp = 1;
	}
	if (!tmp) {
		puts("-1");
		return 0;
	}
	int maxn = 0x3f3f3f3f;
	for (int i = 1; i <= k; i++)
		if (dir[i]) maxn = min(maxn, (mr[i]-ml[i])/abs(dir[i]));
	for (int t = 0; t <= k+1; t++) work(n, k), res[t] = ans;
	if (!vol) {
		cout << ans << endl;
		return 0;
	}
	ans = 0, maxn -= 2;
	for (int i = 0; i <= k+1; i++) {
		int tmp = 1;
		for (int j = 0; j <= k+1; j++)
			if (j != i) tmp = 1ll*tmp*(mod+maxn+1-j)%mod*power(mod+i-j, mod-2)%mod;
		ans = (ans + 1ll*tmp*res[i])%mod;
	}
	vol = 1;
	for (int i = 1; i <= k; i++) {
		lb[i] += dir[i]*(maxn-k), rb[i] += dir[i]*(maxn-k);
		if (dir[i] > 0) ml[i] += dir[i]*(maxn-k);
		if (dir[i] < 0) mr[i] += dir[i]*(maxn-k);
		vol = 1ll*vol*(mr[i]-ml[i]+1)%mod;
	}
	work(n, k);
	cout << ans << endl;
}
