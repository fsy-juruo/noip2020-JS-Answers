#include<bits/stdc++.h>
using namespace std;
#define son first
#define mom second
typedef pair<int, int> Pii;
const int MAXN = 1e5 + 200;
Pii nod[MAXN];
vector <int> to[MAXN], que;
int ru[MAXN];
int n, m;
int gcd(int a, int b){
	if(a % b == 0) return b;
	else return gcd(b, a % b);
}
int gca(int a, int b) {return a / gcd(a, b) * b;}
void chu(Pii &t){
	int tmp = gcd(max(t.mom, t.son), min(t.mom, t.son));
	t.son /= tmp;
	t.mom /= tmp;
}
Pii div(Pii t, int k){
	chu(t);
	int tmp = gcd(max(t.son, k), min(t.son, k));
	k /= tmp, t.son /= tmp; 
	t.mom *= k;
	return t;
}
void jia(Pii &a, Pii b){
	int maxn = max(a.mom, b.mom), minn = min(a.mom, b.mom);
	if(a.mom == b.mom){
		a.son += b.son;
		return;
	}
	int ma = gca(maxn, minn);
	int ta = ma / a.mom, tb = ma / b.mom;
	a.mom = ma, a.son = (a.son * ta) + (b.son * tb);
}
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i(1); i <= n; ++ i){
		nod[i].son = 0, nod[i].mom = 1;
		int d;
		scanf("%d", &d);
		while(d --){
			int a;
			scanf("%d", &a);
			to[i].push_back(a);
			++ ru[a];
		}
	}
	for(int i(1); i <= n; ++ i){
		if(ru[i]) continue;
		nod[i].son = 1;
		que.push_back(i);
	}
	for(int i(0); i != que.size(); ++ i)
		for(int j(0); j != to[que[i]].size(); ++ j){
			-- ru[to[que[i]][j]];
			if(!ru[to[que[i]][j]]) que.push_back(to[que[i]][j]);
		}
	for(int i(0); i != que.size(); ++ i){
		int l = to[que[i]].size();
		if(l == 0) continue;
		Pii t = div(nod[que[i]], l);
		for(int j(0); j != l; ++ j){
			jia(nod[to[que[i]][j]], t);
			chu(nod[to[que[i]][j]]);
		}
	}
	for(int i(1); i <= n; ++ i)
		if(to[i].size() == 0)
			printf("%d %d\n", nod[i].son, nod[i].mom);
	return 0;
}
