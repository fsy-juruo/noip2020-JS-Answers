#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[200005];
int d[200005];
int f[200005];
int w[200005];
int ch[200005];
int bg[200005];
int sml[200005];
int nw[200005];
int n, k, ans;
void dfs(int dep) {
	if(dep > k) {
		int l = 0, u = 0;
		memcpy(a, f, sizeof(a));
		while(1) {
			if(l == n) l = 1;
			else l++;
			a[c[l]] += d[l];
			u++;
			if(a[c[l]] < 1 || a[c[l]] > w[c[l]]) {
				ans += u;
				if(ans >= 1000000007) ans -= 1000000007;
				return ;
			}
		}
	}
	for(int i = 1; i <= w[dep]; i++) {
		f[dep] = i;
		dfs(dep + 1);
	}
	return ;
}
int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= k; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i] >> d[i];
		ch[c[i]] += d[i];
	}
	bool flag = 0;
	for(int i = 1; i <= k; i++) {
		if(ch[i]) {
			flag = 1;
			break;
		}
	}
	if(!flag) {
		memset(sml, 0x3f, sizeof(sml));
		for(int i = 1; i <= n; i++) {
			nw[c[i]] += d[i];
			sml[c[i]] = min(sml[c[i]], nw[c[i]]);
			bg[c[i]] = max(bg[c[i]], nw[c[i]]);
		}
		flag = 0;
		for(int i = 1; i <= k; i++) {
			if(bg[i] - sml[i] >= w[i]) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			cout << -1 << endl;
			return 0;
		}
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}

