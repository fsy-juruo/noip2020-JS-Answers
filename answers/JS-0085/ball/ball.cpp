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
const int MAXN =50+3,MAXM=400+3;
vector <pair<int,int> > V;
int n,m,A[MAXN][MAXM],L[MAXN];
void mov(int a,int b){
//	printf("mov from %d to %d.\n",a,b);
	int la=L[a],lb=L[b]; A[b][++L[b]]=A[a][la],A[a][L[a]--]=0;
//	up(1,n+1,i){
//		up(1,L[i],j) printf("%d ",A[i][j]); puts("");
//	}
//	puts("====");
	V.push_back(make_pair(a,b));
}
int o,N[MAXN],I[MAXN],T[MAXN];
bool cmp(int a,int b){
	return N[a]<N[b];
}
void clc(int l,int w){
	up(1,l,i){
		N[i]=0,T[i]=m; dn(m,1,j) if(A[i][j]==w) ++N[i],T[i]=j;
	}
	up(1,l,i) I[i]=i;
	sort(I+1,I+1+l,cmp); int t=1;
	up(1,l,x){
		int i=I[x]; if(i==1) continue;
		while(m-L[t]<N[i]) mov(t,o);
		dn(m,T[i],j){
			if(A[i][j]==w) mov(i,t); else mov(i,o);
		}
		up(1,m+1-T[i]-N[i],j) mov(o,i);
		up(1,N[i],j)   mov(t,i);
	}
	up(1,L[o],j) mov(o,t); t=2;
	up(1,N[1],i) mov(t,o);
	dn(m,T[1],i) if(A[1][i]==w) mov(1,t); else mov(1,o);
	up(1,m+1-T[1]-N[1],i) mov(o,1);
	up(1,N[1],i) mov(t,1);
	up(1,N[1],i) mov(o,t);
	up(1,l,i){
		dn(m,1,j){
			if(A[i][j]==w) mov(i,o); else break;
		}
	}
	up(1,l-1,i){
		up(1,m,j) if(!A[i][j]) mov(l,i);
	}
	o=l;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=qread(),m=qread(),o=n+1;
	up(1,n,i) up(1,m,j) A[i][j]=qread();
	up(1,n,i) L[i]=m;
	up(1,n-1,i) clc(n-i+1,i);
	printf("%d\n",V.size());
	up(1,V.size(),i) printf("%d %d\n",V[i-1].first,V[i-1].second);
	return 0;
}
/*
Ni zuo TOUHOU MAD,hao ma ?
*ao*
*/
