#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, cnt, head[100005], rud[100005], chud[100005], fenmu[100005], fenzi[100005];

queue<ll>q;

struct Edge{
	int to, next;
}e[200010];

void add(int u, int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

//int gcd(ll x, ll y){
//	if(y == 0)return 1;
//	if(x < y)swap(x, y);
//	if(x % y == 0) return y;
//	return gcd(y, x%y);
//}

int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= m; ++i)fenmu[i] = fenzi[i] = 1;
	for(int i = 1; i <= n; ++i){
		int d, b;
		scanf("%d", &d);
		for(int j = 1; j <= d; ++j){
			scanf("%d", &b);
			add(i, b);
			++rud[b];
			++chud[i];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!rud[i])q.push(i);
	}
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(chud[x]){
			fenmu[x] *= chud[x];
			int gys = __gcd(fenzi[x], fenmu[x]);
			fenzi[x] /= gys;fenmu[x] /= gys;
		}
		for(int i = head[x]; i; i = e[i].next){
			int y = e[i].to;
			if(fenzi[y] == fenmu[y] && fenzi[y] == 0){
				fenzi[y] = fenzi[x];
				fenmu[y] = fenmu[x];
			}
			else {
				ll fm = fenmu[x] * fenmu[y];
				ll fz = fenmu [x] * fenzi[y] + fenmu[y] * fenzi[x];
				fenmu[y] = fm / __gcd(fm, fz);
				fenzi[y] = fz / __gcd(fm, fz);
			}
			--rud[y];
			if(rud[y] == 0) q.push(y);
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!chud[i]){
			printf("%lld %lld\n", fenzi[i], fenmu[i]);
		}
	}
	fclose(stdin);fclose(stdout);
}

/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
