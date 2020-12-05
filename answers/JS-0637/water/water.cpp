#include<bits/stdc++.h>
#define N 100010
#define ll long long 
#define DEBUG printf("vzyx and tqzer AK!\n")

using namespace std;

inline ll read() {
	ll w=1,x=0;
	char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return w*x;
}

int n,m,d[N],din[N];
bool vh[N];
int head[N],tot=0;
struct graph{
	int v,next;
}edge[N];
inline void add(int u,int v) {edge[++tot].v=v,edge[tot].next=head[u],head[u]=tot;}
struct node{
	ll s,m;
	#define s(x) p[x].s
	#define m(x) p[x].m
}p[N];

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
void yf(ll &s,ll &m) {
	ll g=gcd(s,m);
	s/=g,m/=g;
}
void change(int x,ll s,ll m) {
	if(!s(x)) {
		s(x)=s,m(x)=m;
		yf(s(x),m(x));
	}
	else {
		s(x)=s(x)*m+s*m(x);
		m(x)=m*m(x);
		yf(s(x),m(x));
	}
}
int h=1,t=0,q[N];
void toposort() {
	for(int i=1;i<=m;i++) q[++t]=i;
	while(h<=t) {
		int u=q[h++];
		for(int i=head[u];i;i=edge[i].next) {
			int v=edge[i].v;
			din[v]--;
			change(v,s(u),m(u)*d[u]);
			if(!din[v]) q[++t]=v;
		}
	}
}

void init() {
	for(int i=1;i<=m;i++) s(i)=m(i)=1;
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int u=1;u<=n;u++) {
		d[u]=read();
		if(!d[u]) vh[u]=true;
		for(int j=1;j<=d[u];j++) {
			int v=read();
			add(u,v);
			din[v]++;
		}
	}
	
	init();
	toposort();
	
	for(int i=1;i<=n;i++) if(vh[i]) printf("%lld %lld\n",s(i),m(i));
	
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
