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
const int MAXN =5e5+3,MAXM=10+3,MOD=1e9+7,TWO=5e8+4;
int n,k,K[MAXM],C[MAXN],D[MAXN],L[MAXM],R[MAXM],T[MAXM];
int pwr(int a,int b){
	int t=a,r=1; while(b){
		if(b&1) r=1ll*r*t%MOD; t=1ll*t*t%MOD,b>>=1;
	}
	return r;
}
u64 ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=qread(),k=qread();
	up(1,k,i) K[i]=qread(),L[i]=1,R[i]=K[i];
	up(1,n,i) C[i]=qread(),D[i]=qread();
	for(int x=1;;++x){
		int i=(x-1)%n+1;
		int c=C[i],d=D[i],w=K[c],t=1; T[c]+=d;
		up(1,k,j) if(j!=c) t=1ll*t*(R[j]-L[j]+1)%MOD;
		int nl=max(L[c],-T[c]+1),nr=min(R[c],w-T[c]);
		if(nl!=L[c]){
			int w=min(abs(nl-L[c]),R[c]-L[c]+1);
			ans=(ans+1ll*t%MOD*(1+w)*w%MOD*TWO%MOD)%MOD;
		} else if(nr!=R[c]){
			int w=min(abs(nr-R[c]),R[c]-L[c]+1);
			ans=(ans+1ll*t%MOD*(1+w)*w%MOD*TWO%MOD)%MOD;
		}
		if(nl>nr) break; L[c]=nl,R[c]=nr;
		ans=(ans+1ll*t*(R[c]-L[c]+1)%MOD*abs(d)%MOD)%MOD;
		if(x%n==0){
			up(1,k,j) if(T[j]!=0) goto nxt;
			puts("-1"); return 0;
			nxt:;
		}
		
	}
	printf("%llu\n",ans);
	return 0;
}
/*
Ni zuo TOUHOU MAD,hao ma ?
*ao*
*/
