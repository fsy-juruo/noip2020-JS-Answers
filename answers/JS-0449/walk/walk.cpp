#include <bits/stdc++.h>
#define REP(x,l,u) for(int x=(l);x<=(u);x++)
using namespace std;

const int MAXK=12;
const int MAXN=5e5+10;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
int W[MAXK],sigma_d[MAXK],loca[MAXK],ans=0,n,k;

struct Node{
	int c,d;
}seq[MAXN];

void dfs(int dep){
	if(dep>k){
		int loca_[MAXK];
		REP(i,1,k)loca_[i]=loca[i];
		int T=INF;
		REP(i,1,k){
			int tmp_T;
			if(sigma_d[i]==0)tmp_T=INF;
			else{
				if(sigma_d[i]>0)tmp_T=(W[i]-loca_[i])/(sigma_d[i]);
				else            tmp_T=(loca_[i]-1)/(-sigma_d[i]);
			}
			T=min(T,tmp_T);
		}
		ans=(ans+T*n)%MOD;
		REP(i,1,k)loca_[i]+=((sigma_d[i])*T);
		REP(i,1,n){
			int c=seq[i].c,d=seq[i].d;
			if(loca_[c]+d>W[c]||loca_[c]+d<1){
				break;
			}
			ans=(ans+1)%MOD;
			loca_[c]+=d;
		}
		return;
	}
	REP(i,1,W[dep]){
		loca[dep]=i;
		dfs(dep+1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	REP(i,1,k)cin>>W[i];
	REP(i,1,n){
		int c,d;scanf("%d%d",&c,&d);
		seq[i].c=c;seq[i].d=d;
		sigma_d[c]+=d;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
