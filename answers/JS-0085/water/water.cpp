#include<bits/stdc++.h>
#define up(l,r,i) for(int i=l,END##i=r;i<=END##i;++i)
#define dn(r,l,i) for(int i=r,END##i=l;i>=END##i;--i)
using namespace std;
typedef unsigned int u32;
typedef long long    i64;
typedef unsigned long long u64;
i64 qread(){
	i64 r=0,w=1; char c;
	while(!isdigit(c=getchar())) w=(c=='-'?-1:1); r=c-'0';
	while( isdigit(c=getchar())) r=r*10+c-'0';
	return r*w;
}
const int MAXN =1e5+3,MAXM=5e5+3;
struct GRAPH{
	int nxt[MAXM*2],ver[MAXM*2],head[MAXN],tot;
	void add(int a,int b){
		ver[++tot]=b,nxt[tot]=head[a],head[a]=tot;
	}
}G;
int n,m,C[MAXN],D[MAXN]; queue <int> Q;
struct Node{
	i64 x,y;
	Node(i64 _x=0,i64 _y=1):x(_x),y(_y){}
	Node operator +(Node t){
		i64 a=t.y*x+t.x*y,b=y*t.y,d=__gcd(a,b);
		return Node(a/d,b/d);
	}
}S[MAXN];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=qread(),m=qread(); up(1,n,i){
		int d=qread(); D[i]=d; up(1,d,j){
			int v=qread(); ++C[v]; G.add(i,v);
		}
	}
	up(1,m,i) S[i].x=1,S[i].y=1,Q.push(i);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		if(!D[u]) continue; S[u].y*=D[u];
		for(int i=G.head[u];i;i=G.nxt[i]){
			int v=G.ver[i]; S[v]=S[v]+S[u];
			if((--C[v])==0) Q.push(v);
		}
	}
	up(1,n,i) if(!D[i]) printf("%lld %lld\n",S[i].x,S[i].y);
	return 0;
}
/*
Ni zuo TOUHOU MAD,hao ma ?
*ao*
*/
