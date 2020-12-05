#include<bits/stdc++.h>
#define LL long long
using namespace std;
inline void read(int &x){
	x = 0;
	static int f; static char ch; f = 1,ch = getchar();
	while (!isdigit(ch)){ if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) x = x * 10 + ch - '0',ch = getchar();
	x *= f;
}
inline void write(int x){ if (x < 0) x = -x,putchar('-'); if (x > 9) write(x/10),x %= 10; putchar(x + '0'); }

const int N = 500005,K = 12,P = 1e9 + 7;
int n,k,w[K],c[N],d[N];
namespace subtask1{
	inline bool check(){
		LL t = n;
		for (int i = 1; i <= k; ++i){ t *= w[i]; if (t > 500000) return 0; }
		return 1;
	}
	int ans,dp[N],vis[N]; bool Eternal;
	
	int ww[K];
	inline int calcid(int *t){
		int i,ret = 1;
		for (i = 1; i <= k; ++i) ret += (t[i]-1) * ww[i];
		return ret;
	}
	int q[K];
	inline void getq(int id){
		--id;
		for (int i = 1; i <= k; ++i){
			q[i] = 1 + id / ww[i],id %= ww[i];
		}
	}
	inline int DP(int x){
		if (Eternal) return 0;
		if (vis[x]) return dp[x]; vis[x] = 1;
		getq(x);
		for (int i = 1; i <= n; ++i){
			q[c[i]] += d[i];
			if (q[c[i]] < 1 || q[c[i]] > w[c[i]]){
				return dp[x] = i;
			}
		}
		int y = calcid(q);
		if (x == y) return Eternal = 1,0;
		return dp[x] = (n + DP(y)) % P;
	}
	int sumd[K];
	
	int now[K];
	inline void dfs(int dep){
		if (Eternal) return;
		if (dep > k){
			ans = (ans + DP(calcid(now))) % P;
			return;
		}
		for (int i = 1; i <= w[dep]; ++i) now[dep] = i,dfs(dep+1);
	}
	inline void solve(){
		int i; Eternal = 0;
		ww[k] = 1;
		for (i = k-1; i >= 1; --i) ww[i] = ww[i+1] * w[i+1];dfs(1);
		if (Eternal) puts("-1"); else cout << ans << '\n';
	}
}

namespace subtask2{
	inline bool check(){
		if (k > 1) return 0;
		if (w[1] > 100000) return 0;
		if (n > 100000) return 0;
		return 1;
	}
	int mx,mn,now;
	int dp[100005]; bool vis[100005];
	inline void Tag(int x,int v){
		if (!vis[x]) dp[x] = v,vis[x] = 1;
	}
	inline bool in(int x){ return 1 <= x && x <= w[1]; }
	inline int DP(int x){
		if (vis[x]) return dp[x]; vis[x] = 1;
		return dp[x] = (DP(x+now) + n) % P;
	}
	inline void solve(){
		int i;
		mx = mn = now = 0;
		for (i = 1; i <= n; ++i){
			now += d[i];
			if (mx < now){
				mx = now;
				if (in(w[1]+1-mx)) Tag(w[1]+1-mx,i);
				//pos + mx = w[1] + 1;
			}
			if (mn > now){
				mn = now;
				if (in(-mn)) Tag(-mn,i);
				//pos + mn = 0;
			}
		}
		LL ans=0;
		for (i = 1; i <= w[1]; ++i){
			if (!vis[i] && !now){ puts("-1"); return; }
			ans = (ans + DP(i)) % P;
		}
		cout<<ans<<'\n';
	//	puts("-1");
		return;
	}
}

namespace subtask3{
	inline bool check(){
		if (k != 2) return 0;
		if (max(w[2],w[1]) > 100000) return 0;
		if (n > 100000) return 0;
		return 1;
	}
	
	inline void solve(){
		puts("-1");
		return;
	}
}

int main(){
	freopen("walk.in","r",stdin); freopen("walk.out","w",stdout);
	int i;
	read(n),read(k);
	for (i = 1; i <= k; ++i) read(w[i]);
	for (i = 1; i <= n; ++i) read(c[i]),read(d[i]);
	if (subtask1::check()){ subtask1::solve(); return 0; }
	if (subtask2::check()){ subtask2::solve(); return 0; }
	puts("-1");
	return 0;
}
