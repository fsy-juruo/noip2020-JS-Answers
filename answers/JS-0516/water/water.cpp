#include<bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

typedef long long ll;

const int MAX_N=1e5+10;
const ll MOD=1e12;

vector <int> g[MAX_N];
int deg[MAX_N];
int N,M;
queue <int> Q;
pair<ll,ll> ans[MAX_N];

pair<ll,ll> div(pair<ll,ll> p,ll val){
	ll x=p.fst%val;
	p.fst=p.fst/val;
	p.snd=(1ll*x*MOD+p.snd)/val;
	return p;
}

pair<ll,ll> add(pair<ll,ll> a,pair<ll,ll> b){
	pair<ll,ll> res;
	res.snd=a.snd+b.snd;
	res.fst=res.snd/MOD+a.fst+b.fst;
	res.snd%=MOD;
	return res;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int d; scanf("%d",&d);
		for(int j=0;j<d;j++){
			int x; scanf("%d",&x);
			x--; g[i].pb(x); deg[x]++;
		}
	}
	for(int i=0;i<M;i++){
		Q.push(i);
		ans[i].fst=36279705ll;
		ans[i].snd=600000000000ll;
	}
	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		if((int)g[x].size()==0) continue;
		pair<ll,ll> now=div(ans[x],(ll)g[x].size());
		for(int i=0;i<g[x].size();i++){
			int to=g[x][i];
			ans[to]=add(ans[to],now);
			deg[to]--;
			if(deg[to]==0){
				Q.push(to);
			}
		}
	}
	for(int i=0;i<N;i++) if(g[i].size()==0){
		pair<ll,ll> fm; fm.fst=36279705ll,fm.snd=600000000000ll;
		while(fm.snd%2ll==0&&ans[i].snd%2ll==0){
			fm=div(fm,2);
			ans[i]=div(ans[i],2);
		}
		while(ll(fm.fst+fm.snd)%3ll==0&&ll(ans[i].fst+ans[i].snd)%3ll==0){
			fm=div(fm,3);
			ans[i]=div(ans[i],3);
		}
		while(fm.snd%5ll==0&&ans[i].snd%5ll==0){
			fm=div(fm,5);
			ans[i]=div(ans[i],5);
		}	
		if(ans[i].fst!=0) printf("%lld",ans[i].fst);
		printf("%lld ",ans[i].snd);
		if(fm.fst!=0) printf("%lld",fm.fst);
		printf("%lld\n",fm.snd);
	}
	return 0;
}
