#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)

typedef long long LL;
const int N = 100000 + 10, M = N * 10 + 10;

template <typename Tp> void read(Tp &x){
	x = 0; int op = 1; char ch = getchar();
	while(!isdigit(ch)){ if(ch == '-') op = -1; ch = getchar(); }
	while(isdigit(ch)){ x = x*10+ch-'0'; ch = getchar(); } x *= op;
}
template <typename Tp> void CMax(Tp &x, Tp y){ if(y > x) x = y; }
template <typename Tp> void CMin(Tp &x, Tp y){ if(y < x) x = y; }

int n, m;
int head[N], to[M], nxt[M], din[N], dout[N], tot;


void add(int x, int y){
	to[++ tot] = y; 
	nxt[tot] = head[x]; head[x] = tot;
	din[y] ++; dout[x] ++;
}

LL gcd(LL x, LL y){
	if(y == 0) return x;
	return gcd(y, x % y);
}

struct Node{
	LL p, q;
	Node(){ p = 0; q = 1; }
	Node(LL _p, LL _q) : p(_p), q(_q) {}
	Node operator + (const Node &b){
		LL fz = p * b.q + q * b.p, fm = q * b.q;
		LL g = gcd(fz, fm);
		return Node(fz / g, fm / g);
	}
} wt[N];

queue<int> Q;

void topo(){
	for(int i = 1; i <= n; ++ i){
		if(!din[i]){
			Q.push(i);
			wt[i] = Node(1, 1);
		}
	}
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		Node now = wt[x]; now.q = 1ll * now.q * dout[x];
		for(int i = head[x]; i; i = nxt[i]){
			int y = to[i]; din[y] --;
			wt[y] = now + wt[y];
			if(!din[y]) Q.push(y);
		}
	}
}


int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	read(n); read(m);
	int d, a;
	for(int i = 1; i <= n; ++ i){
		read(d);
		while(d -- ){
			read(a);
			add(i, a);
		}
	}
	topo();
	for(int i = 1; i <= n; ++ i){
		if(!dout[i]){
			LL g = gcd(wt[i].p, wt[i].q);
			printf("%lld %lld\n", wt[i].p / g, wt[i].q / g);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

