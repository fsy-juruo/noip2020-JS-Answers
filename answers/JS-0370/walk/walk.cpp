#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MOD=1e9+7;
const int MAXK=10+5;
const int MAXN=5e5+5;
const int MAXL=1e6+5;
int n,k,len[MAXK];
int c[MAXN],d[MAXN];
namespace sub1{
	bool check1(){
		if(n>5) return 0;
		if(k>5) return 0;
		for(int i=1;i<=k;i++) if(len[i]>3) return 0;
		return 1;
	}
	bool check2(){
		if(n>100) return 0;
		if(k>3) return 0;
		for(int i=1;i<=k;i++) if(len[i]>10) return 0;
		return 1;
	}
	int x[MAXK],tmp[MAXK];
	int ans=0;
	void dfs(int cur){
		if(cur==k+1){
			for(int i=1;i<=k;i++) tmp[i]=x[i];
			int op=1,tim=-1;
			for(int i=1;i<=1000;i++){
				tmp[c[op]]+=d[op];
				if(tmp[c[op]]<=0||tmp[c[op]]>len[c[op]]){
					tim=i;break;
				}
				op++;if(op==n+1) op=1;
			}
			if(tim==-1){
				puts("-1");exit(0);
			}
//			for(int i=1;i<=k;i++) printf("%d ",x[i]);printf("%d\n",tim);
			ans=(ans+tim)%MOD;
			return;
		}
		for(int i=1;i<=len[cur];i++){
			x[cur]=i;dfs(cur+1);
		}
	}
	int solve(){
		dfs(1);printf("%d\n",ans);return 0;
	}
}
namespace sub2{
	bool check(){
		return (k==1)&&(len[1]<=1e5);
	}
	int l[MAXN],r[MAXN];
	int solve(){
		int cur=0;
		memset(l,63,sizeof(l));
		memset(r,63,sizeof(r));
		l[0]=r[0]=0;
		int mx=0,mn=0;
		for(int i=1;i<=n;i++){
			cur+=d[i];
			if(cur>=0) r[cur]=min(r[cur],i);
			else l[-cur]=min(l[-cur],i);
			mx=max(mx,cur);mn=min(mn,cur);
		}
		ll ans=0;
		for(int i=1;i<=len[1];i++){
			if(l[i]<1e9||r[len[1]+1-i]<-1e9){
				ans=(ans+min(l[i],r[len[1]+1-i]))%MOD;
			}
			else{
				if(cur<0){
					int need=(i+mn-1)/(-cur)+1;
					int pos=i+need*cur;
					ans=(ans+1ll*need*n%MOD)%MOD;
					ans=(ans+l[pos])%MOD;
				}
				else if(cur==0){
					puts("-1");return 0;
				}
				else{
					int need=(len[1]+1-mx-i-1)/(cur)+1;
					int pos=i+need*cur;
					ans=(ans+1ll*need*n%MOD)%MOD;
					ans=(ans+r[len[1]+1-pos])%MOD;
				}
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
}
namespace sub3{
	bool check(){
		return k<=10;
	}
	ll qpow(ll x,int e){
		ll ret=1;
		while(e){
			if(e&1) ret=ret*x%MOD;
			x=x*x%MOD;e>>=1;
		} return ret;
	}
	int l[MAXL],r[MAXL];
	ll p[MAXK][MAXL];
	void calc(int di){
		int cur=0;
		memset(l,63,sizeof(l));
		memset(r,63,sizeof(r));
		l[0]=r[0]=0;
		int mx=0,mn=0;
		for(int i=1;i<=n;i++){
			if(c[i]!=di) continue;
			cur+=d[i];
			if(cur>=0) r[cur]=min(r[cur],i);
			else l[-cur]=min(l[-cur],i);
			mx=max(mx,cur);mn=min(mn,cur);
		}
//		printf("%d %d\n",cur,l[1]);
		ll ans=0;
		for(int i=1;i<=len[di];i++){
			if(l[i]<1e9||r[len[di]+1-i]<1e9){
				p[di][i]=min(l[i],r[len[di]+1-i]);
			}
			else{
				if(cur<0){
					int need=(i+mn-1)/(-cur)+1;
					int pos=i+need*cur;
					p[di][i]=1ll*need*n+l[pos];
				}
				else if(cur==0){
					p[di][i]=1e18;
				}
				else{
					int need=(len[di]+1-mx-i-1)/(cur)+1;
					int pos=i+need*cur;
					p[di][i]=1ll*need*n+r[len[di]+1-pos];
				}
			}
		}
	}
	pair<ll,int> pp[10000005];
	int ppcnt=0,num[MAXK],mul=1,inv[MAXL];
	int solve(){
		for(int i=1;i<MAXL;i++) inv[i]=qpow(i,MOD-2);
		for(int i=1;i<=k;i++) calc(i);
		for(int i=1;i<=k;i++) mul=1ll*mul*len[i]%MOD;
		bool flg=1;
		for(int i=1;i<=k;i++){
			ll mx=0;
			for(int j=1;j<=len[i];j++) mx=max(mx,p[i][j]);
			flg&=(mx==1e18);
		}
		if(flg){puts("-1");return 0;}
		int ans=0;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=len[i];j++){
				pp[++ppcnt]=mp(p[i][j],i);
			}
		}
		sort(pp+1,pp+ppcnt+1);
		for(int i=1;i<=ppcnt;i++){
			if(pp[i].fi==1e18) continue;
			int x=pp[i].se;
			mul=1ll*mul*inv[len[x]-num[x]]%MOD;
//			printf("%d\n",mul);
			ans=(ans+1ll*(pp[i].fi%MOD)*mul%MOD)%MOD;
			num[x]++;mul=1ll*mul*(len[x]-num[x])%MOD;
		}
		printf("%d\n",ans);
		return 0;
	}
}
int main(){
	freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=k;i++) read(len[i]);
	for(int i=1;i<=n;i++) read(c[i]),read(d[i]);
	if(sub1::check1()||sub1::check2()) return sub1::solve();
//	if(sub2::check()) return sub2::solve();
	return sub3::solve();
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

7 1
10
1 -1
1 1
1 -1
1 -1
1 1
1 1
1 1

3 3
1000000 1000000 1000000
1 1
2 1
3 1

10 10
1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1 

5 1
5
1 1
1 -1
1 1
1 -1
1 -1
*/
