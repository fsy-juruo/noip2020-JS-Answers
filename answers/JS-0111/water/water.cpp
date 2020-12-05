#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
struct shiwt {
	int v;
	int nxt;
} e[MAXN<<3];
int fst[MAXN],rd[MAXN],cd[MAXN];
int cnt,n,m;
long long gcd(long long a,long long b) {
	if(!b) return a;
	return gcd(b,a%b);
}
void add(int u,int v) {
	cnt++;
	e[cnt].v=v;
	e[cnt].nxt=fst[u];
	fst[u]=cnt;
}
long long p[MAXN],q[MAXN];// p/q
int que[MAXN],book[MAXN];
void Plus(int x,int y) {
	if(!p[y]) {
		p[y]=p[x];
		q[y]=q[x]*cd[x];
		int Gcd=gcd(p[y],q[y]);
		p[y]/=Gcd;
		q[y]/=Gcd;
		return;
	}
	p[y]=p[y]*q[x]*cd[x]+p[x]*q[y];
	q[y]=q[y]*q[x]*cd[x];
	int Gcd=gcd(p[y],q[y]);
	p[y]/=Gcd;
	q[y]/=Gcd;
}
void check(int x,int y){
	printf("%d %d:%lld %lld %lld %lld\n",x,y,p[x],q[x],p[y],q[y]);	
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&cd[i]);
		for(int j=1; j<=cd[i]; j++) {
			int x;
			scanf("%d",&x);
			add(i,x);
			rd[x]++;
		}
	}
	int h=0,t=0;
	for(int i=1; i<=m; i++) {
		p[i]=q[i]=1;
		que[t++]=i;
	}
	while(h<t) {
		int x=que[h];
		if(cd[x]) {
			for(int i=fst[x]; i; i=e[i].nxt) {
				int y=e[i].v;
				rd[y]--;
				Plus(x,y);
		//		check(x,y); 
				if(!rd[y]) que[t++]=y;
			}
		}
		h++;
	}
	for(int i=1; i<=n; i++) {
		if(!cd[i]) printf("%lld %lld\n",p[i],q[i]);
	}
	return 0;
}
