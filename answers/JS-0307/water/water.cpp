#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair < int , int > pii;
#define mpr make_pair
#define FS first
#define SC second
template < typename T > void UMIN(T &a,T b){a=(b<a?b:a);}
template < typename T > void UMAX(T &a,T b){a=(b>a?b:a);}
char readch(){
	char c=getchar();
	while(c==' '||c=='\n'||c=='\t'||c=='\r') c=getchar();
	return c;
}
LL readint(){
	char c=getchar();
	bool neg=0;
	while(c<'0' || c>'9'){
		if(c=='-') neg=1;
		c=getchar();
	}
	LL ret=0;
	while(c>='0' && c<='9'){
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return neg?-ret:ret;
}
const ULL ullinf=1000000000000000000ull;
int n,m;
vector < int > nx[100005];
ULL GCD(ULL a,ULL b){
	if(!b) return a;
	return GCD(b,a%b);
}
struct fuck{
	ULL a;
	int pw2;
	fuck(){
		a=0;
		pw2=0;
	}
	void incpw2(){
		while(a && !(a&1)) ++pw2,a>>=1;
	}
	fuck(ULL v){
		a=v;
		pw2=0;
		incpw2();
	}
	void decpw2(int to){
		a<<=(pw2-to);
		pw2=to;
	}
	int mod10(){
		ULL ini=a%10;
		int i;
		for(i=0;i<pw2;++i){
			ini<<=1;
			if(ini>ullinf) ini%=10;
		}
		return ini%10;
	}
	void div10(){
		if(pw2 && !(a%5)){
			--pw2;
			a/=5;
		}
		else{
			a=(a<<pw2)/10;
			pw2=0;
			incpw2();
		}
	}
};
fuck operator +(fuck A,fuck B){
	if(A.pw2<B.pw2) swap(A,B);
	A.decpw2(B.pw2);
	A.a+=B.a;
	A.incpw2();
	return A;
}
fuck operator *(fuck A,fuck B){
	A.pw2+=B.pw2;
	A.a*=B.a;
	return A;
}
fuck operator /(fuck A,fuck B){
	A.pw2-=B.pw2;
	A.a/=B.a;
	return A;
}
fuck GCD(fuck A,fuck B){
	UMIN(A.pw2,B.pw2);
	A.a=GCD(A.a,B.a);
	return A;
}
void putint(fuck V){
	if(!(V.a)){
		putchar('0');
		return;
	}
	int toput=V.mod10();
	V.div10();
	if(V.a) putint(V);
	putchar('0'+toput);
}
struct frac{
	fuck u,v; // u/v
	void simp(){
		fuck g=GCD(u,v);
		u=u/g;
		v=v/g;
	}
	frac(ULL _u=0,ULL _v=1,bool dosimp=1){
		u=fuck(_u);
		v=fuck(_v);
		if(dosimp) simp();
	}
	void divint(ULL d){
		v=v*fuck(d);
		simp();
	}
}dp[100005];
frac operator +(frac A,frac B){
	frac R;
	R.v=(A.v/GCD(A.v,B.v))*B.v;
	R.u=A.u*(R.v/A.v)+B.u*(R.v/B.v);
	R.simp();
	return R;
}
bool vis[100005];
vector < int > ord;
void dfs(int v){
	int i;
	vis[v]=1;
	for(i=0;i<(int)nx[v].size();++i){
		int u=nx[v][i];
		if(!vis[u]) dfs(u);
	}
	ord.push_back(v);
}
bool ed[100005];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	// CHECK CORNER CASES !!!
	// CHECK INITIALIZATION !!!
	// djq txdy !!!
	int i,j,k;
	n=readint();m=readint();
	for(i=0;i<n;++i){
		int sz=readint();
		nx[i].resize(sz);
		for(j=0;j<sz;++j){
			nx[i][j]=readint()-1;
		}
	}
	ord.reserve(n);
	for(i=0;i<n;++i){
		if(!vis[i]) dfs(i);
	}
	reverse(ord.begin(),ord.end());
	for(i=0;i<n;++i){
		int d=ord[i];
		if(d<m) dp[d]=dp[d]+frac(1);
		if(nx[d].empty()){
			ed[d]=1;
		}
		else{
			frac peredge=dp[d];
			peredge.divint(nx[d].size());
			for(j=0;j<(int)nx[d].size();++j){
				int u=nx[d][j];
				dp[u]=dp[u]+peredge;
			}
		}
	}
	for(i=0;i<n;++i){
		if(ed[i]){
			putint(dp[i].u);
			putchar(' ');
			putint(dp[i].v);
			putchar('\n');
		}
	}
	return 0;
}
