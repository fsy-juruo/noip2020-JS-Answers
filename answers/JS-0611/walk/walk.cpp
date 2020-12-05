#include <bits/stdc++.h>
using namespace std;

vector < int > v[500010];
long long qaq[500010], w[500010], c[500010], d[500010];
long long qwq[11];
long long Get[11][500010];
long long Get2[11][500010];
int num[11];
long long qvq = 0;
int n, k;
long long ans = 0;

void dfs(int now){
	if (now > k){
		if (qvq == LONG_LONG_MAX){
			cout << -1 << endl;
			exit(0);
		}
		else{
			ans += qvq;
			ans %= 1000000009;
		}
	}
	long long t = qvq;
	for (int i = 1; i <= w[now]; i++){
		qvq = min(qvq, min(Get[now][i], Get2[now][w[now] - i + 1]));
		dfs(now + 1);
		qvq = t;
	}
}

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= k; i++) for (int j = 1; j <= w[i]; j++) Get[i][j] = LONG_LONG_MAX;
	for (int i = 1; i <= k; i++) for (int j = 1; j <= w[i]; j++) Get2[i][j] = LONG_LONG_MAX;
	for (int i = 1; i <= n; i++){
		scanf("%lld%lld", &c[i], &d[i]);
		v[c[i]].push_back(d[i]);
		qaq[c[i]] += d[i];
	}
	for (int i = 1; i <= n; i++){
		qwq[c[i]] += d[i];
		if (qaq[c[i]] > 0){
			if (qwq[c[i]] > 0){
				for (int I = 1; I <= w[c[i]]; I++){
					Get[c[i]][I] = min(Get[c[i]][I], ((long long)(max(0ll, w[c[i]] - I + 1 - qwq[c[i]]) + qaq[c[i]] - 1) / qaq[c[i]]) * n + i);
				}	
			}
		}
		else{
			if (qwq[c[i]] > 0){
				Get[c[i]][max(1ll, w[c[i]] - qwq[c[i]] + 1)] = min(Get[c[i]][max(1ll, (long long)w[c[i]] - qwq[c[i]] + 1)], (long long)i);
			}
		}
	}
	for (int i = 1; i <= k; i++){
		qaq[c[i]] = -qaq[c[i]];
		qwq[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		qwq[c[i]] += -d[i];
		if (qaq[c[i]] > 0){
			if (qwq[c[i]] > 0){
				for (int I = 1; I <= w[c[i]]; I++){
					Get2[c[i]][I] = min(Get2[c[i]][I], ((long long)(max(0ll, w[c[i]] - I + 1 - qwq[c[i]]) + qaq[c[i]] - 1) / qaq[c[i]]) * n + i);
				}	
			}
		}
		else{
			if (qwq[c[i]] > 0){
				Get2[c[i]][max(1ll, w[c[i]] - qwq[c[i]] + 1)] = min(Get2[c[i]][max(1ll, w[c[i]] - qwq[c[i]] + 1)], (long long)i);
			}
		}
	}
	for (int i = 1; i <= k; i++){
		for (int j = 2; j <= w[i]; j++){
			Get[i][j] = min(Get[i][j], Get[i][j - 1]);
		}
	}
	for (int i = 1; i <= k; i++){
		for (int j = 2; j <= w[i]; j++){
			Get2[i][j] = min(Get2[i][j], Get2[i][j - 1]);
		}
	}
	qvq = LONG_LONG_MAX;
	dfs(1);
	cout << ans << endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
