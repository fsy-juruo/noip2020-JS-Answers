#include<bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define pd priority_queue
#define int long long
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
int head[N], Next[N], ver[N], tot;
int deg[N], n, m, udeg[N];
int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
}
struct node{
	int id, fz, fm;
}mess[N];
void sieve(node &x, node a){
	if(x.fm == 0){
		x.fz = a.fz;
		x.fm = a.fm;
	}
	else{
		int z = a.fm * x.fm;
		int w = x.fz * a.fm + a.fz * x.fm;
		int g = gcd(z, w);
		x.fz = w / g;
		x.fm = z / g;
	}
}
node merge(node x, int t){
	x.fm *= t;
	int z = gcd(x.fm, x.fz);
	return (node){x.id, x.fz / z, x.fm / z};
}
queue<node> Q;
void add(int a, int b){
	ver[++tot] = b;
	Next[tot] = head[a];
	head[a] = tot;
}
vector<int> v;
void Work(){
	while(Q.size()){
		node p = Q.front();
		Q.pop();
		int x = p.id;
		for(int i = head[x]; i; i = Next[i]){
			int y = ver[i];
			deg[y]--;
			sieve(mess[y], merge(p, udeg[x]));
			if(!deg[y])
				Q.push(mess[y]);
		}
	}
	for(unsigned int y = 0; y < v.size(); ++y)
		printf("%lld %lld\n", mess[v[y]].fz, mess[v[y]].fm);
}
void init(){
	read(n); read(m);
	for(int i = 1, x; i <= n; ++i){
		if(i <= m)
			mess[i] = (node){i, 1, 1};
		else
			mess[i] = (node){i, 0, 0};
		read(udeg[i]);
		if(udeg[i] == 0)
			v.pb(i);
		for(int j = 1, y; j <= udeg[i]; ++j){
			read(y);
			add(i, y);
			deg[y]++;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(!deg[i])
			Q.push(mess[i]);
	Work();
}
signed main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	init();
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
