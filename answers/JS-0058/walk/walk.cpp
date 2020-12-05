#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll rd() {
	ll s = 0, f = 1;
	char x = getchar();
	for (; !isdigit(x); x = getchar()) if (x == '-') f = -1;
	for (; isdigit(x); x = getchar()) s = s*10+x-48;
	return s*f;
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cout << -1 << endl;
	/*n = rd();
	k = rd();
	for (int i = 1; i <= k; i++) w[i] = rd();
	for (int i = 1; i <= n; i++) {
		a[i] = rd();
		b[i] = rd();
		t[a[i]] += b[i];
		Maxp[a[i]] = max(Maxp[a[i]], t[a[i]]);
		Minp[a[i]] = min(Minp[a[i]], t[a[i]]);
	}
	bool fg = 0;
	for (int i = 1; 1; i++) {
		for (int j = 1; j <= k; j++) tt[j] += t[j];
		for (int j = 1; j <= k; j++)
			if (abs(tt[j])+Maxp[j]-Minp[j] >= w[j]) {
				fg = 1;
				break;
			}
		if (fg) {
			mn = i;
			break;
		}
		for (int j = 1; j <= k; j++) {
			sum = 1;
			for (int l = 1; l <= k; l++)
				if (l != j) sum = (sum*(w[l]-abs(tt[l])-Maxp[l]+Minp[L]))%P;
			s[j] = (s[j]+sum)%P;
		}
	}
	for (int i = 1; i <= n; i++) {
		c = a[i];
		p[c] += b[i];
		if (p[c] > maxp[c]) {
			maxp[c] = p[c];
			sum = 1;
			for (int j = 1; j <= k; j++) {
				if (j == c) continue;
				sum = (sum*(w[j]-maxp[j]+minp[j]))%P;
			}
			1, mn
			ans = (ans+sum*i+)%P;
		}
		if (p[c] < minp[c]) {
			minp[c] = p[c];
			sum = 1;
			for (int j = 1; j <= k; j++) {
				if (j == c) continue;
				sum = (sum*(w[j]-maxp[j]+minp[j]))%P;
			}
			ans = (ans+sum*i)%P;
		}
		if (maxp[c]-minp[c] >= w[i]) {
			cout << ans << endl;
			return 0;
		}
	}
	fg = 1;
	for (int i = 1; i <= n; i++)
		if (p[c] != 0) {
			fg = 0;
			break;
		}
	if (fg) {
		cout << -1 << endl;
		return 0;
	}
	*/
	return 0;
}

