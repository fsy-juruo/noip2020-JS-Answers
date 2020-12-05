#include <bits/stdc++.h>
using namespace std;
#define rg register
#define xh(i,l,r) for (rg int i=(l);i<=(r);i++)
#define read(a) scanf("%d",&(a))
#define write(a) printf("%d",(a))
#define writeln puts("")
#define qmax(a,b) ((a)<(b)?(b):(a))
#define qmin(a,b) ((a)>(b)?(b):(a))
#define Babara_is_so_cute(f) freopen(f".in","r",stdin);freopen(f".out","w",stdout);
#define Babara_is_the_best fclose(stdin);fclose(stdout);

typedef long long ll;
#define readl(a) scanf("%lld",&(a))
#define writel(a) printf("%lld",(a))

typedef vector<int> vi;
#define pb push_back

typedef pair<int,int> pii;
#define mp make_pair

const int N=1e5+5,K=10+2;
int stp[N][K],w[K],c[N],d[N],n,k;
int a[K];
ll dp[N];
ll ans=0;
bool chk=1,fl=1;// chk:all zero      fl:death repeat
const ll MOD=1e9+7;
int P=1;
void init(){
	read(n);read(k);
	if (n>1e5) {
		write(-1);writeln;
		return;
	}
	xh(i,1,k) read(w[i]);
	memset(stp,0,sizeof(stp));
	xh(i,1,n){
		read(c[i]);read(d[i]);
		xh(j,1,k){
			if (j==c[i]) stp[i][j]=stp[i-1][j]+d[i];else stp[i][j]=stp[i-1][j];
		}
	}
}
void dfs(int dep){
	int st=(dep-1)%n+1;
	a[c[st]]+=d[st];
	if (dep>n && chk) {
		fl=0;
		return;
	}
	if (a[c[st]]<1 || a[c[st]]>w[c[st]]) {
		ans=(ans+dep)%MOD;
		//write(dep);writeln;
	}
	else dfs(dep+1);
}
void chck(){
	xh(i,1,k) if (stp[n][i]!=0) chk=0;
}
void solve1(){
	xh(i,1,k) P*=w[i];
	chck();
	xh(i,1,P){
		int t=i;
		xh(j,1,k){
			a[j]=(t-1)%w[j]+1;
			t=(t-1)/w[j]+1;
		}
		//write(i);
		dfs(1);
	}
	if (fl) write(ans);else write(-1);
	writeln;
}
int ddfs(int dep){
	int st=(dep-1)%n+1;
	a[c[st]]+=d[st];
	if (dep>n && chk) {
		fl=0;
		return 0;
	}
	if (a[c[st]]<1 || a[c[st]]>w[c[st]]) {
		return dep;
		//write(dep);writeln;
	}
	else return ddfs(dep+1);
}
void solve2(){
	int l=w[1];
	int rgt=0,lft=0;
	xh(i,1,n){
		rgt=qmax(rgt,stp[i][1]);
		lft=qmin(lft,stp[i][1]);
	}
	chck();
	xh(i,l-rgt+1,l) a[1]=i,dp[i]=ddfs(1);
	xh(i,1,-lft) a[1]=i,dp[i]=ddfs(1);
	int dx=stp[n][1];
	//write(lft);write(rgt);
	if (dx==0){
		if (-lft<l-rgt) write(-1),writeln;
		else{
			xh(i,1,l) ans+=dp[i];
			write(ans);writeln;
		}
	}else if (dx<0){
		xh(i,-lft+1,l-rgt){
			dp[i]=dp[i+dx]+n;
		}
		xh(i,1,l) ans+=dp[i];
		write(ans);writeln;
	}else{
		for (rg int i=(l-rgt);i>=(-lft+1);i--){
			dp[i]=dp[i+dx]+n;
		}
		xh(i,1,l) ans+=dp[i];
		write(ans);writeln;
	}
}
void solve3(){
	write(-1);
}
int main(){
	Babara_is_so_cute("walk")
	init();
	if (n<=100)solve1();
	else if (n<=1e5 && k==1) solve2();
	else if (n<=1e5 && k==2) solve3();
	Babara_is_the_best
	return 0;
}
