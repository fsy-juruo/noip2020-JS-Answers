#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline ll read() {
	ll num=0ll; char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) num=(num<<3ll)+(num<<1ll)+(ch^48), ch=getchar();
	return num;
}
inline ll gcd(ll a,ll b) { return b ? gcd(b, a%b) : a; }
struct Num {
	ll Fz, Fm;
	Num() { this->Fz=0ll; this->Fm=1ll; }
	Num operator + (Num y) {
		Num ans;
		ans.Fm =  this->Fm * y.Fm;
		ans.Fz = this->Fz * y.Fm + y.Fz * this->Fm;
		ll g= gcd(ans.Fm, ans.Fz);
		ans.Fm/=g; ans.Fz/=g; return ans;
	}
	Num operator * (Num y) {
		Num ans;
		ans.Fz=this->Fz * y.Fz; ans.Fm=this->Fm * y.Fm;
		ll g= gcd(ans.Fm, ans.Fz);
		ans.Fm/=g; ans.Fz/=g; return ans;
	}
};

const int N=1e5+7, M=5e5+7;
int n,m, c[N],len, deg[N], siz[N];
struct s { int y,nxt; } b[M];
inline void add(int x,int y) { b[++len]=(s) { y,c[x] }, c[x]=len; }
Num ans[N];
bool vis[N], tp[N];
#define rg register

inline void topsort() {
	queue<int > q;
	for(rg int i=1;i<=m;i++) ans[i].Fz=1ll, ans[i].Fm=1ll;
	for(rg int i=1;i<=n;i++) if(!deg[i]) q.push(i);
	
	while(!q.empty()) {
		int x=q.front(); q.pop();
		Num del; del.Fm=(ll) siz[x]; del.Fz=1ll;
		del=del * ans[x];
		vis[x]=true ;
		
		for(rg int i=c[x];i;i=b[i].nxt) {
			int y=b[i].y;
			if(vis[y]) continue ;
			ans[y]=ans[y] + del;
			if(--deg[y] == 0) q.push(y);
		}
	}
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	n=read(), m=read();
	for(rg int i=1;i<=n;i++) {
		int tot=read(), x=i,y; siz[i]=tot;
		if(!tot) tp[x]=true ;
		for(rg int j=1;j<=tot;j++) {
			y=read(), add(x, y); deg[y]++;
		}
	}
	
	topsort();
	
	for(rg int i=1;i<=n;i++) if(tp[i]) printf("%lld %lld\n",ans[i].Fz, ans[i].Fm);
	return 0;
}
