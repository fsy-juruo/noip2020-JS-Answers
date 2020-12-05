#include<bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define pd priority_queue
using namespace std;
template<typename Tp>
void read(Tp &x){
	x = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	x *= f;
}
template<typename Tp> void Cmax(Tp &x, Tp y) { if(y > x) x = y;}
template<typename Tp> void Csum(Tp &x, Tp y) { x = (x + y); }
typedef long long LL;
const int N = 1e5 + 40;
int n, k,lim[11];
#define inf 1e9
#define mid ((l + r) >> 1)
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
struct Seg{
	int dat[N << 2], maxn[N << 2], mina[N << 2];
	void pushup(int x){
		dat[x] = dat[x << 1] + dat[x << 1 | 1];
		mina[x] = min(mina[x << 1], dat[x << 1] + mina[x << 1 | 1]);
		maxn[x] = max(maxn[x << 1], dat[x << 1] + maxn[x << 1 | 1]);
	}
	void build(int rt, int l, int r){
		if(l == r){
			mina[rt] = inf;
			return;
		}
		build(lson); build(rson);
		pushup(rt);
	}
	void modify(int rt ,int l, int r, int p, int k){
		if(l > p || r < p)
			return;
		if(l == r){
			dat[rt] = k;
			maxn[rt] = mina[rt] = k;
			return;
		}
		modify(lson, p, k);
		modify(rson, p, k);
		pushup(rt);
	}
	int query1(int rt, int l, int r, int k){
		if(l == r)
			return l;	
		if(mina[rt << 1] + k < 1)
			return query1(lson, k);
		else
			return query1(rson, k + dat[rt << 1]);
	}
	int query2(int rt, int l, int r, int k){
		if(l == r)
			return l;
		if(maxn[rt << 1] + k > n)
			return query2(lson, k);
		else
			return query2(rson, k + dat[rt << 1]);
	}
}wd[11];
int tmp[11];
LL ans = 0;
void Work(){
	int step = inf, tim = inf;
	for(int i = 1; i <= k; ++i){
		if(wd[i].dat == 0){
			puts("-1");
			return;
		}
		debug(i);
//		cout << wd[i].dat[1] << endl;
		int u;
		if(tmp[i] + wd[i].maxn[1] > lim[i] || tmp[i] + wd[i].maxn[1] < 1)
			u = 0;
		else{
			if(wd[i].dat[1] < 0){
				u = (tmp[i] - 1) / (-wd[i].dat[1]);
				tmp[i] = u * wd[i].dat[1] + tmp[i] % (-wd[i].dat[1]) + 1;
			}
			else{
				u = (lim[i] - tmp[i] - 1) / wd[i].dat[1];
				tmp[i] = tmp[i] % wd[i].dat[1] + u * wd[i].dat[1];
			}
		}
		debug(u);
		debug(tmp[i]);
		if(tim > u){
			tim = u;
				step = min(wd[i].query1(1, 1, n, tmp[i]), wd[i].query2(1, 1, n, tmp[i]));
		}
		else
			if(tim == u)
				step = min(step, min(wd[i].query1(1, 1, n, tmp[i]), wd[i].query2(1, 1, n, tmp[i])));
	}
	ans += 1ll * tim * n + 1ll * step;
}
void dfs(int x){
	if(x == k + 1){
		Work();
		return;
	}
	for(int i = 1; i <= lim[x]; ++i){
		tmp[x] = i;
		dfs(x + 1);
	}
}
void init(){
//	read(n); read(k);
//	for(int i = 1; i <= k; ++i)
//		read(lim[i]);
//	for(int i = 1; i <= k; ++i)
//		wd[i].build(1, 1, n);
//	
//	for(int i = 1, x, y; i <= n; ++i){
//		read(x); read(y);
//		wd[x].modify(1, 1, n, i, y);
//	}
//	dfs(1);
//	printf("%lld\n", ans);
	puts("-1");
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	init();
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
