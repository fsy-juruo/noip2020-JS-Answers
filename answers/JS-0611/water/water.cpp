#include <bits/stdc++.h>
using namespace std;

struct chtholly{
	long long x, y;
}node[100010];
int n, m;

void Plus(int k, chtholly a){
	long long Lcm = a.y * node[k].y / __gcd(node[k].y, a.y);
//	cout << Lcm << endl;
	node[k].x *= Lcm / node[k].y;
	node[k].y = Lcm;
	node[k].x += a.x * (Lcm / a.y);
	long long GcD = __gcd(node[k].x, node[k].y);
	node[k].x /= GcD;
	node[k].y /= GcD;
}

chtholly Tme(int k, int y){
	chtholly awa;
	awa.x = node[k].x;
	awa.y = node[k].y * y;
	long long GcD = __gcd(awa.x, awa.y);
	awa.x /= GcD;
	awa.y /= GcD;
	return awa;
}

int to[100010][11], qaq[100010];
int vis[100010], stk[100010], top = 0;
int rd[100010];

void dfs(int qwq){
	for (int i = 1; i <= qaq[qwq]; i++){
		rd[to[qwq][i]]++;
		if (!vis[to[qwq][i]]){
			vis[to[qwq][i]] = 1;
			dfs(to[qwq][i]);
		}
	}
}

int topo(int s){
	for (int i = 1; i <= n; i++){
		rd[i] = 0;
		vis[i] = 0;
	}
	node[s].x = 1;
	vis[s] = 1;
	dfs(s);
//	for (int i = 1; i <= n; i++){
//		cout << rd[i] << " ";
//	}
	stk[++top] = s;
	while (top){
		int v = stk[top];
		top--;
		for (int i = 1; i <= qaq[v]; i++){
			Plus(to[v][i], Tme(v, qaq[v]));
//			cout << to[v][i] << " " << node[to[v][i]].x << " " << node[to[v][i]].y << endl;
			rd[to[v][i]]--;
			if (!rd[to[v][i]]){
				stk[++top] = to[v][i];
			}
		}
		if (qaq[v]){
			node[v].x = 0;
			node[v].y = 1;	
		}
	}
}

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		node[i].x = 0;
		node[i].y = 1;
		scanf("%d", &qaq[i]);
		for (int j = 1; j <= qaq[i]; j++){
			scanf("%d", &to[i][j]);
		}
	}
	for (int i = 1; i <= m; i++){
		topo(i);
	}
//	cout << node[4].x << endl;
	for (int i = 1; i <= n; i++){
		if (node[i].x){
			printf("%lld %lld\n", node[i].x, node[i].y);
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
