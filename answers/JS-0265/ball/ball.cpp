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
int N,m;
int in[55][405];
vector<pii> a[55];
vector<pii> ans;
inline void shrink(vector<pii> &v){
	vector<pii> old=v;
	v.clear();
	int cnt=old[0].S;
	int n=old.size();
	for (int i=1;i<n;++i){
		if (old[i].F==old[i-1].F) cnt+=old[i].S;
		else{
			v.pb(mp(old[i-1].F,cnt));cnt=old[i].S;
		}
	}
	v.pb(mp(old[n-1].F,cnt));
}
inline void solve2(){
	if (a[1].size()==1){
		printf("0\n");return;
	}
	REP(u,2){
		int v=3-u;
		while(a[u].size()>2){
			int n=a[u].size();
			rep(i,a[u][n-1].S) ans.pb(mp(u,3));
			rep(i,a[u][n-2].S) ans.pb(mp(v,3));
			rep(i,a[u][n-2].S) ans.pb(mp(u,v));
			rep(i,a[u][n-3].S) ans.pb(mp(u,3));
			rep(i,a[u][n-2].S) ans.pb(mp(v,u));
			rep(i,a[u][n-3].S) ans.pb(mp(3,u));
			rep(i,a[u][n-2].S) ans.pb(mp(3,v));
			rep(i,a[u][n-1].S) ans.pb(mp(3,u));
			swap(a[u][n-2],a[u][n-3]);
			shrink(a[u]);
		}
	}
	
	if (a[1][1].F==a[2][1].F){
		rep(i,a[1][1].S) ans.pb(mp(1,3));
		rep(i,a[2][1].S) ans.pb(mp(2,3));
		rep(i,a[1][0].S) ans.pb(mp(1,2));
	}
	else{
		rep(i,a[1][1].S) ans.pb(mp(1,3));
		rep(i,a[2][1].S) ans.pb(mp(2,1));
		rep(i,a[2][0].S) ans.pb(mp(2,3));
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].F,ans[i].S);
}
int cap[55];
inline void solveBig(){
	int emp=N+1;
	int lst=N;
	REP(col,N-1){// get color i ready
		REP(u,lst){
			while(1){
				int fst=-1,sum=0,n=a[u].size();
				if (n==1) break;
				sum+=a[u][n-1].S;
				for (int i=(int)n-2;i>=0;--i){
					if (a[u][i].F==col){
						fst=i;break;
					}
					else sum+=a[u][i].S;
				}
				if (fst==-1) break;// no such color in u beneath the top
				// move to the top
				int tmp=(u==1? lst:u-1);
				rep(i,a[u][fst].S) ans.pb(mp(tmp,emp));
				rep(i,sum) ans.pb(mp(u,emp));
				rep(i,a[u][fst].S) ans.pb(mp(u,tmp));
				rep(i,sum) ans.pb(mp(emp,u));
				rep(i,a[u][fst].S) ans.pb(mp(tmp,u));
				rep(i,a[u][fst].S) ans.pb(mp(emp,tmp));
				pii pr=a[u][fst];
				for (int i=fst;i+1<n;++i) a[u][i]=a[u][i+1];
				a[u][n-1]=pr;
				shrink(a[u]);
			}
		}
		// go to emp
		memset(cap,0,sizeof(cap));
		REP(u,lst){
			int n=a[u].size();
			if (a[u][n-1].F==col){
				rep(i,a[u][n-1].S) ans.pb(mp(u,emp));
				cap[u]=a[u][n-1].S;
				a[u].pop_back();
			}
		}
		// lst -= 1
		REP(u,lst-1) rep(i,cap[u]) ans.pb(mp(lst,u));// fill
		lst--;emp--;
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].F,ans[i].S);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	RII(N,m);
	if (N==1){
		printf("0\n");return 0;
	}
	REP(i,N){
		REP(j,m) RI(in[i][j]);
		int cnt=1;
		for (int j=2;j<=m;++j){
			if (in[i][j]==in[i][j-1]) ++cnt;
			else{
				a[i].pb(mp(in[i][j-1],cnt));cnt=1;
			}
		}
		a[i].pb(mp(in[i][m],cnt));
	}
	
	if (N==2) solve2();
	else solveBig();
	return 0;
}
