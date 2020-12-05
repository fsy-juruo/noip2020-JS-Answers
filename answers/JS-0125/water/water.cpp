#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f,MAXN=1e5+10,EDGE=MAXN*5;
int head[MAXN],to[EDGE],nxt[EDGE],sz;
inline void add(int x,int y) {
	nxt[++sz]=head[x];
	head[x]=sz;
	to[sz]=y;
}
inline LL gcd(LL a,LL b) {
	return b==0?a:gcd(b,a%b);
}
struct frac {
	LL a,b;
	frac(LL x=0,LL y=1) {
		LL gc=gcd(x,y);
		a=x/gc;
		b=y/gc;
	}
	friend frac operator+(frac x,frac y) {
		return frac(x.a*y.b+x.b*y.a,x.b*y.b);
	}
	friend frac operator*(frac x,frac y) {
		return frac(x.a*y.a,x.b*y.b);
	}
} wat[MAXN];
int N,M,siz[MAXN],in[MAXN];
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++) {
		scanf("%d",siz+i);
		for(int j=1; j<=siz[i]; j++) {
			int v;
			scanf("%d",&v);
			add(i,v);
			in[v]++;
		}
	}
	queue<int> q;
	for(int i=1; i<=N; i++) {
		if(!in[i]) {
			wat[i]=frac(1,1);
			q.push(i);
		}
	}
	while(q.size()) {
		int x=q.front();
		q.pop();
		frac unt=wat[x]*frac(1,siz[x]);
		for(int i=head[x]; i; i=nxt[i]) {
			wat[to[i]]=wat[to[i]]+unt;
			in[to[i]]--;
			if(!in[to[i]]) {
				q.push(to[i]);
			}
		}
	}
	for(int i=1; i<=N; i++) {
		if(!siz[i]) {
			printf("%lld %lld\n",wat[i].a,wat[i].b);
		}
	}
	return 0;
}
