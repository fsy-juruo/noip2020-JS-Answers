//NOIP 2020 rp ++
//CCF姥爷机爱我一回 
//希望这题多拿点分
/*
	
	--YFZ 
	
*/ 
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

struct ff{
	long long x, y;
	ff(){}
	ff(long long xx, long long yy){
		x = xx; y = yy;
	}
};

ff f(ff a){
	long long g = __gcd(a.x, a.y);
	return ff(a.x / g, a.y / g);
}

ff work(ff a, ff b){
	long long y = a.y * b.y;
	long long x = a.x * b.y + b.x * a.y;
	return ff(f(ff(x, y)));
}

int n, m;
int d[N];
vector<int> g[N];
ff nd[N];

void dfs(int now, ff a){
	if(d[now] == 0){
		nd[now] = work(nd[now], a);
		return;
	}
	for(int j = 0; j < g[now].size(); j++){
		dfs(g[now][j], ff(a.x, a.y * d[now]));
	}
}

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		nd[i].x = 0; nd[i].y = 1;
		scanf("%d", &d[i]);
		for(int j = 0; j < d[i]; j++){
			int temp;
			scanf("%d", &temp);
			g[i].push_back(temp);
		}
	}
	for(int i = 1; i <= m; i++){
		nd[i].x = nd[i].y = 1;
		if(d[i] == 0){
			continue;
		}
		for(int j = 0; j < g[i].size(); j++){
			dfs(g[i][j], ff(1, d[i]));
		}
	}
	for(int i = 1; i <= n; i++){
		if(d[i] == 0){
			cout << nd[i].x << " " << nd[i].y << endl;
		}
	}
	return 0;
}
