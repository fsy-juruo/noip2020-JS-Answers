#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> G[200005];
vector<int> fin;
struct num{
	int p,q;
	num(int _p,int _q){
		p = _p;
		q = _q;
	}
	num(){}
};
num w[200005];
int gcd(int x,int y){
	if(y == 0)return x;
	return gcd(y,x % y);
}
void dfs(int st){
	register int fa = 0,fb = 0;
	register int gd = 0;
	fa = w[st].p;
	fb = w[st].q * (int)G[st].size();
	gd = gcd(fa,fb);
	fa /= gd;
	fb /= gd;
	for(register int i = 0;i < G[st].size(); ++i){
		register int id = G[st][i];
		register int gys = gcd(w[id].q,fb);
		register int gbs = w[id].q * fb / gys;
		w[id].p = w[id].p * (gbs / w[id].q);
		w[id].q = gbs;
		w[id].p += fa * (gbs / fb);
		w[st] = num(0,1);
		register int ccf = gcd(w[id].p,w[id].q);
		w[id].p /= ccf;
		w[id].q /= ccf;
		dfs(id);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(register int i = 1;i <= n; ++i){
		register int d;
		scanf("%d",&d);
		if(d == 0)fin.push_back(i);
		for(register int j = 1;j <= d; ++j){
			register int a;
			scanf("%d",&a);
			G[i].push_back(a);
		}
	}
	for(register int i = 1;i <= n;++i){
		if(i <= m)w[i] = num(1,1);
		else w[i] = num(0,1);
	}
	for(register int i = 1;i <= m;++i)dfs(i);
	for(register int i = 0;i < fin.size();++i)printf("%d %d\n",w[fin[i]].p,w[fin[i]].q);
	return 0;
}
