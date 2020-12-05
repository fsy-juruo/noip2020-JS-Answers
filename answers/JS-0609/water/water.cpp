#include<bits/stdc++.h>
using namespace std;
const long long maxn=100001;
long long fx,head[maxn],num=0;
long long p[maxn],q[maxn],son[maxn],fa[maxn],tip[maxn];
long long n,m,d,v,cnt=0;
struct edge {
	long long nxt,to;
} e[maxn<<2];
inline void add(long long from,long long to) {
	e[++num].nxt=head[from];
	e[num].to=to;
	head[from]=num;
}
inline long long gcd(long long a,long long b) {
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
inline void count(long long pg,long long qg,long long fro,long long to) {
	if(pg!=0){
	long long pt=p[fro];
	long long qt=son[fro]*q[fro];
	long long p1,p2,gbs;
	gbs=max(qg,qt)*gcd(qg,qt);
	p1=pg*gbs/qg;
	p2=pt*gbs/qt;
	pg=p1+p2;
	qg=gbs;
	p[to]=pg;
	q[to]=qg;
	}
	else{
		p[to]=1;
		q[to]=son[fro]*q[fro];
	}
}
inline void dfs(long long x) {
	for(int i=head[x]; i; i=e[i].nxt ) {
		count(p[e[i].to],q[e[i].to],x,e[i].to);
		dfs(e[i].to);
	}
}

inline long long read() {
	int f=1, x=0;
	char ch;
	do {
		ch=getchar();
		if(ch=='-')f=-1;
	} while(ch<'0'||ch>'9');
	do {
		x=x*10+ch-'0';
		ch=getchar();
	} while(ch>='0'&&ch<='9');
	return f*x;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int u=1; u<=n; u++) {
		d=read();
		son[u]=d;
		for(int i=1; i<=d; i++) {
			v=read();
			add(u,v);
			fa[v]++;
		}
	}
	for(int i=1; i<=n; i++) {
		if(fa[i]==0) {
			p[i]=1;
			q[i]=1;
			dfs(i);
		}
		if(son[i]==0)
			tip[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++){
    fx=gcd(p[tip[i]],q[tip[i]]);
	p[tip[i]]=p[tip[i]]/fx;
	q[tip[i]]=q[tip[i]]/fx;
    cout<<p[tip[i]]<<" "<<q[tip[i]]<<'\n';
	}
	return 0;
}
