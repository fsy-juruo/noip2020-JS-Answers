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
const int MAXN =(1<<20)+3,P=13331;
u64 H[MAXN],T[MAXN],N[30],ans; int C[256+3],W[MAXN],n,m=MAXN-1,t,c; char S[MAXN];
int ppc(int x){
	return C[(x>>24)&255]+C[(x>>16)&255]+C[(x>>8)&255]+C[x&255];
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	up(0,255,i) C[i]=C[i>>1]+(i&1); T[0]=1; up(1,m,i) T[i]=T[i-1]*P;
	dn(qread(),1,TTT){
		while(!isalpha(c=getchar())); S[++n]=c;
		while( isalpha(c=getchar()))  S[++n]=c;
		up(1,n,i) W[i]=W[i-1]^(1<<(S[i]-'a')),H[i]=H[i-1]*P+S[i];
		t=ppc(W[n]);
		up(1,n-1,i){
			int w=W[i],_w=W[n]^W[i],a=ppc(_w),b=t;
			if(i>1) for(int j=1;i*j<n;++j){
				if(H[i*j]-H[i*j-i]==H[i]*T[i*j-i]) ans=ans+N[(j&1)?a:b];
				else break;
			}
			up(ppc(w),26,j) ++N[j];
		}
		printf("%llu\n",ans),ans=n=0;
		memset(N,0,sizeof(N));
	}
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab


Ni zuo TOUHOU MAD,hao ma ?
*ao*
*/
