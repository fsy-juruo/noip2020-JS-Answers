#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

const int MAXK = 11, MAXN = 500005, MOD = 1e9+7;
long long n, k, w[MAXK], pos[MAXK], pos_now[MAXK], steps[MAXN][2], ans;
bool flag = true, returned = false;

bool OK() {
	int p = 1;
	pos[p]++;
	while (pos[p] > w[p]) {
		if (p > k) return true;
		pos[p] = 1;
		p++;
		pos[p]++;
	}
	return false;
}

bool Returned() {
	for (int i = 1; i <= k; i++) {
		if (pos_now[i] != 0) return false;
	}
	return true;
}

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	
	scanf("%lld %lld", &n, &k);//cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &w[i]);//cin >> w[i];
		pos[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &steps[i][0], &steps[i][1]);//cin >> steps[i][0] >> steps[i][1];
	}
	
	for (int i = 1; i <= n; i++) {
		pos_now[steps[i][0]] += steps[i][1];
	}
	if (Returned()) returned = true;
	
	pos[1] = 0;
	while (flag && !OK()) {
		memset(pos_now, 0, sizeof(pos_now));
		for (int i = 1; true; i++) {
			if (i > n) i = 1;
			pos_now[steps[i][0]] += steps[i][1];
			ans = (ans + 1) % MOD;
			int axis = steps[i][0];
			if (pos[axis] + pos_now[axis] < 1 || pos[axis] + pos_now[axis] > w[axis]) break;
			if (returned && i == n) {
				ans = -1;
				flag = false;
				break;
			}
		}
	}
	
	printf("%lld\n", ans);//cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
