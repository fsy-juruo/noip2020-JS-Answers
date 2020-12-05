#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &cn){
	cn=0;int sig=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')sig=-1;c=getchar();}
	while(isdigit(c)){cn=cn*10+c-48;c=getchar();}
	cn*=sig;
}
template<typename T>inline void write(T cn){
	int wei=0;
	int cx=cn%10;cn/=10;
	if(cx<0||cn<0){
		putchar('-');
		cx=0-cx;cn=0-cn;
	}
	T cm=0;
	while(cn){
		cm=cm*10+cn%10;cn/=10;
		wei++;
	}
	while(wei--){
		putchar(cm%10+48);
		cm/=10;
	}
	putchar(cx+48);
}
int pai[100001],f[100001];
struct Node{
	int pj[6];
	int num;
	long long p;
	long long q;
}g[100001];
inline void gc(long long &a,long long &b){
	long long i=5;
	while(1){
		if(i==1)return ;
		if(a%i==0&&b%i==0){
			a/=i;
			b/=i;
		}else{
			i--;
		}
	}
}
inline void go(int x){	
	f[x]=1;	
	long long fm=0;
	fm=g[x].num*g[x].q;
	long long fz=g[x].p;
	if(g[x].num!=0){
		g[x].p=0;
		g[x].q=1;	
	}
	for(int i=1;i<=g[x].num;i++){
		g[g[x].pj[i]].p=g[g[x].pj[i]].p*fm+fz*g[g[x].pj[i]].q;
		g[g[x].pj[i]].q*=fm;
		gc(g[g[x].pj[i]].p,g[g[x].pj[i]].q);
		go(g[x].pj[i]);
	}
	return;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m,pi=0;
	read(n),read(m);
	for(int i=1;i<=n;i++){
		if(i<=m)g[i].p=1;
		else g[i].p=0;
		g[i].q=1;
		int d;
		read(d);
		if(d==0){
			pi++;
			pai[pi]=i;
		}else{
			g[i].num=d;
			for(int j=1;j<=d;j++){
				int u;
				read(u);
				g[i].pj[j]=u;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(f[i])continue;
		go(i);
	}
	for(int i=1;i<=pi;i++){
		long long px=g[pai[i]].p;
		long long py=g[pai[i]].q;
		gc(px,py);
		write(px);putchar(' ');write(py);putchar('\n');
	}
	return 0;
}

