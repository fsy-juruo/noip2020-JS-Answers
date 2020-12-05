#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(x) cerr << #x << " = " << x << endl
template<typename T>void chkmin(T &a, T b){ a = min(a, b); }
template<typename T>void chkmax(T &a, T b){ a = max(a, b); }


const int MAXN = 1000 + 10;
int fread(void){
	char ch = getchar(); int ret = 0, opt = 1;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') opt = -1;
	for(; isdigit(ch); ch = getchar()) ret = ret * 10 + ch - '0';
	return  ret * opt;
}
int n, k;
namespace Subtask1{
int w[MAXN], pos[MAXN];
bool check(void){
	for(int i = 1; i <= k; ++ i)
		if(pos[i] < 1 || pos[i] > w[i]) return false;
	return true;
}
int c[MAXN], d[MAXN], tmp[MAXN];
int go(void){
	for(int i = 1; i <= k; ++ i) pos[i] = tmp[i];
	int now = 1, ret = 0; 
	while(1){
		if(now > n) now -= n; 
		pos[c[now]] += d[now]; ++ ret;
		if(!check()) return ret;
		++ now;
	}
	
}
int ans;
void dfs(int step){
	if(step == k + 1){
		//for(int i = 1; i <= k; ++ i) printf("%d ", tmp[i]);
		//cout << endl;
		ans += go(); return;
	}
	for(int i = 1; i <= w[step]; ++ i) tmp[step] = i, dfs(step + 1);
}
int tst[MAXN];
inline bool judge(void){
	for(int i = 1; i <= n; ++ i) tst[c[i]] += d[i];
	for(int i = 1; i <= k; ++ i)
		if(tst[i] != 0) return true;
	return false;
}
void work(void){
	for(int i = 1; i <= k; ++ i) w[i] = fread();
	for(int i = 1; i <= n; ++ i) c[i] = fread(), d[i] = fread();
	if(!judge()){
		printf("-1"); return;
	} 
	dfs(1); printf("%d", ans);
}
	
}

inline void init(void){
	n = fread(), k = fread();
}

inline void work(void){
	Subtask1::work();
}

int main(){
	freopen("walk.in", "r", stdin); freopen("walk.out", "w", stdout);
	init(); work();
	fclose(stdin); fclose(stdout);
	return 0;
}

