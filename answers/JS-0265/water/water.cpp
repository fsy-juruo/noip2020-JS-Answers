#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=1;i<=(n);++i)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)

struct frac{
	ll x,y;
	inline frac(ll X=0,ll Y=1):x(X),y(Y){}
	inline frac operator = (const frac &f){
		x=f.x;y=f.y;return *this;
	}
};
inline frac operator * (const frac &a,const frac &b){
	frac ret(a.x*b.x,a.y*b.y);
	ll d=__gcd(ret.x,ret.y);
	ret.x/=d,ret.y/=d;
	return ret;
}
inline frac operator + (const frac &a,const frac &b){
	frac ret(a.x*b.y+a.y*b.x,a.y*b.y);
	ll d=__gcd(ret.x,ret.y);
	ret.x/=d,ret.y/=d;
	return ret;
}
inline void output(const frac &a){
	printf("%lld %lld\n",a.x,a.y);
}


int n,m;
int G[100005][7];
int cnt[100005];
int deg[100005];
int que[100005],qh,qt;
frac flow[100005];
bool is_sink[100005];

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	RII(n,m);
	REP(i,n){
		RI(cnt[i]);
		rep(j,cnt[i]){
			RI(G[i][j]);++deg[G[i][j]];
		}
	}
	qh=qt=0;
	REP(i,n) if (!deg[i]) que[qt++]=i,flow[i]=frac(1,1);
	while(qh!=qt){
		int u=que[qh++];
		
		if (cnt[u]==0){
			is_sink[u]=1;continue;
		}
		frac tmp=flow[u]*frac(1,cnt[u]);
		for (int i=0;i<cnt[u];++i){
			int v=G[u][i];
			flow[v]=flow[v]+tmp;
			--deg[v];
			if (!deg[v]) que[qt++]=v;
		}
	}
	REP(i,n) if (is_sink[i]) output(flow[i]);
	
	return 0;
}
