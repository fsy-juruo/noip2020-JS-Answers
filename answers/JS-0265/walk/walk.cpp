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
const ll MOD=1e9+7;
int n,K;
int w[12];
int c[500005],d[500005];
const int INF=1e9+7;
namespace solveSmall{

inline void solveSmall(){
	vector<int> pos,del,tmp,mx,mn;
	pos.resize(K,1);
	del.resize(K);
	mx.resize(K);mn.resize(K);
	REP(i,n) del[c[i]]+=d[i],mx[c[i]]=max(mx[c[i]],del[c[i]]),mn[c[i]]=min(mn[c[i]],del[c[i]]);// mn:negative
	ll ans=0;
	while(1){
		tmp=pos;
		int cnt=0;
		bool flag=0;
		REP(i,n){
			++cnt;
			tmp[c[i]]+=d[i];
			if (tmp[c[i]]>w[c[i]]||tmp[c[i]]<1){
				flag=1;break;
			}
		}
		
		if (!flag){// a single round is ok
			tmp=pos;
			int base=INF;
			rep(i,K){
				if (del[i]>0) base=min(base,(w[i]-pos[i]-mx[i])/del[i]);
				else if (del[i]<0) base=min(base,(pos[i]+mn[i]-1)/(-del[i]));
			}
			if (base==INF){
				printf("-1\n");return;
			}
			++base;
			ans+=(ll)base*n;
			rep(i,K) tmp[i]+=del[i]*base;
			cnt=0;
			REP(i,n){
				++cnt;
				tmp[c[i]]+=d[i];
				if (tmp[c[i]]>w[c[i]]||tmp[c[i]]<1){
					flag=1;break;
				}
			}
		}
		ans+=cnt;
		ans%=MOD;
		int cur=K-1;
		pos[cur]++;
		while(cur&&pos[cur]>w[cur]){
			pos[cur]=1;--cur;++pos[cur];
		}
		if (pos[cur]>w[cur]) break;
	}
	printf("%lld",ans);
}

}

namespace solve1D{
int mx[100005],mn[100005],del;
inline void solve1D(){
	del=0;
	REP(i,n){
		del+=d[i];
		mx[i]=max(mx[i-1],del);
		mn[i]=min(mn[i-1],del);
	}
	ll ans=0;
	for (int x=1;x<=w[0];++x){
		if (del==0&&x+mx[n]<=w[0]&&x+mn[n]>=1){
			printf("-1\n");return;
		}
		ll base=-1;
		if (del>0) base=(w[0]-x-mx[n])/del;
		else if (del<0) base=(x+mn[n]-1)/(-del);
		++base;
		ans+=base*n%MOD;
		int xx=x+base*del;
		int l=0,r=n;//l:can r:can't
		while(r-l>1){
			int m=l+r>>1;
			if (xx+mx[m]<=w[0]&&xx+mn[m]>=1) l=m;
			else r=m;
		}
		ans+=l+1;
	}
	ans%=MOD;
	printf("%lld\n",ans);
}

}
namespace solve2D{

inline void solve2D(){
	
}

}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	RII(n,K);
	if (n>100000){
		printf("-1\n");return 0;
	}
	rep(i,K) RI(w[i]);
	REP(i,n) RII(c[i],d[i]);
	REP(i,n) --c[i];
	
	if (n<=100) solveSmall::solveSmall();
	else if (K==1) solve1D::solve1D();
	else if (K==2) solve2D::solve2D();
	else printf("-1\n");
	
	return 0;
}
