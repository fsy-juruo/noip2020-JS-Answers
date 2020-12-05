#include<bits/stdc++.h>
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template<typename T> void fw(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) fw(x/10);
	putchar(x%10+48);
}
template<typename T> void fwk(T x){fw(x);putchar(' ');}
template<typename T> void fwl(T x){fw(x);puts("");}
const int N=5e5+10,K=20;
const long long P=1e9+7;
int stp[K][N];
int siz[K],teststat[K],startstat[K];
struct Note{
	int c,d;
	inline void Cin(){fr(c),fr(d);}
}rawstp[N];
int n,k;
long long ans;
inline bool insiz(){
	for(int i=1;i<=k;i++)
		if(teststat[i]<=0||teststat[i]>siz[i])return 0;
	return 1;
}
inline int try1(){
	for(int i=1;i<=k;i++)
		teststat[i]=startstat[i];
	for(int i=1;i<=n;i++){
		teststat[rawstp[i].c]+=rawstp[i].d;
		if(insiz)continue;
		return i-1;
	}
	return n;
}
inline bool check(){
	for(int i=1;i<=k;i++){
		if(stp[i][n]!=0)return 0;
	}
	return 1;
}
inline void work(){
	int t=INT_MAX;
	int tt=try1();
	if(tt<n){
		ans=(ans+tt)%P;
		return;
	}
	if(check()){
		puts("-1");
		exit(0);
	}
	for(int i=1;i<=k;i++)
		teststat[i]=startstat[i];
	for(int i=1;i<=n&&insiz();i++){
		teststat[rawstp[i].c]+=rawstp[i].d;
		ans++;
		ans%=P;
		if(i==n)i=0;
	}
}
inline void dfs(int p){
	if(p==k+1){
		work();
		return;
	}
	for(int i=1;i<=siz[p];i++){
		startstat[p]=i;
		dfs(p+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	fr(n);fr(k);
	for(int i=1;i<=k;i++){
		fr(siz[i]);
	}
	for(int i=1,c,d;i<=n;i++){
		rawstp[i].Cin();
		for(int j=1;j<=k;j++)
			stp[j][i]=stp[j][i-1];
		stp[rawstp[i].c][i]+=d;
	}
	
	dfs(1);
	fwl(ans);
	return 0;
}

