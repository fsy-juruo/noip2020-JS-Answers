#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MN = 5e5 + 5 , INF = 2e9;
const int mod = 998244353;

int N , K , ans , ok , w[MN] , tp[MN] , a[MN] , mx[MN] , bd[MN] , mn[MN] , mv[MN] , c[MN] , d[MN];
map < int , int > mp[MN];

inline void chkmin(int &x , int y) {
	x = min(x , y);
}
inline void chkmax(int &x , int y) {
	x = max(x , y);
}
inline void calc() {
	for (int i = 1; i <= K; ++i) bd[i] = INF;
	for (int i = 1; i <= K; ++i) {
		if (a[i] + mn[i] <= 0 || a[i] + mx[i] > w[i]) {
			bd[i] = 1;
			continue;
		} 
		if (mn[i] < 0) {
			if (mv[i] < 0) 
				chkmin(bd[i] , ((a[i] + mn[i] - 1) / (-mv[i])) + 1);
		}
		if (mx[i] > 0) {
			if (mv[i] > 0)
				chkmin(bd[i] , ((w[i] - a[i] - mx[i]) / mv[i]) + 1);
		}
		++bd[i];
	}
	int val = INF;
	for (int i = 1; i <= K; ++i) 
		chkmin(val , bd[i]);
	if (val == INF) {
		ok = false; printf("-1\n"); exit(0);
		return;
	}
	for (int i = 1; i <= K; ++i) tp[i] = a[i];
	for (int i = 1; i <= K; ++i) if (val) tp[i] += (val - 1) * mv[i];
	if (val) ans = (ans + 1ll * N * (val - 1) % mod) % mod;
	int minn = INF;
	for (int i = 1; i <= K; ++i) {
		if (mp[i].count(-tp[i])) minn = min(minn , mp[i][-tp[i]]);
		if (mp[i].count(w[i] - tp[i] + 1)) minn = min(minn , mp[i][w[i] - tp[i] + 1]);
	}
	ans = (ans + minn) % mod;
}
inline bool dfs(int now) {
	if (now > K) calc();
	else {
		for (int i = 1; i <= w[now]; ++i) {
			a[now] = i;
			dfs(now + 1);
		}
	}
}

int main() {
	 
	 #ifndef evenbao
	 freopen("walk.in" , "r" , stdin);
	 freopen("walk.out" , "w" , stdout);
	 #endif
	 
 	 scanf("%d%d" , &N , &K); 
 	 for (int i = 1; i <= K; ++i) scanf("%d" , &w[i]);
 	 for (int i = 1; i <= K; ++i) {
	  	 mx[i] = -INF , mn[i] = INF; 
		 mv[i] = 0; mp[i][0] = 0;
	  }
 	 for (int i = 1; i <= N; ++i) {
 	 	 scanf("%d%d" , &c[i] , &d[i]);	mv[c[i]] += d[i];
		 chkmax(mx[c[i]] , mv[c[i]]); chkmin(mn[c[i]] , mv[c[i]]);
		 if (!mp[c[i]].count(mv[c[i]])) mp[c[i]][mv[c[i]]] = i;
	 }
	 ok = true; ans = 0;
	 dfs(1);
     if (!ok) printf("-1\n");
	 else printf("%d\n" , ans);
	 return 0;
}

