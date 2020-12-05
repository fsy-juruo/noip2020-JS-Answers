#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+1;

inline int read() { char ch=getchar(); int f=1; while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
	int x=0; while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar(); return x*f;}

int n,m,du[N]; bool vis[N];
pair<ll,ll> dis[N],flow[N];
vector<int> G[N],GG[N];
vector<int> last; int tim[N];
queue<pair<int,int> > q; bool none[N];
int dfn[N];

inline ll gc(ll n,ll m) {return !m?n:gc(m,n%m);}

inline pair<ll,ll> yf(pair<ll,ll> p) {
	ll a=p.first,b=p.second,c=gc(a,b);
	a/=c; b/=c;
	return make_pair(a,b);
}

inline pair<ll,ll> jiafa(pair<ll,ll> p,pair<ll,ll> q) {
	ll a=p.first,b=p.second,c=q.first,d=q.second;
	ll fm=b*d/gc(b,d);
	ll fz=fm/b*a+fm/d*c;
	return yf(make_pair(fz,fm));
}

inline pair<ll,ll> mx(pair<ll,ll> p,pair<ll,ll> q) {
	ll a=p.first,b=p.second,c=q.first,d=q.second;
	return a*b>b*c?p:q;
}

inline void bfs() {
	int t=1;
	while(!q.empty()) {
		int u=q.front().second; pair<ll,ll> p1=flow[u];
		int tnew=q.front().first; 
	/*	if(tnew>t) {
			t=tnew;
			flow[u]=mx(flow[u],dis[u]);
		}*/
		q.pop();
//		printf("!%d %d %d %d\n",u,p1.first,p1.second,tnew);
//		for(int u=1;u<=n;u++) printf("%d %d %d/%d %d/%d\n",u,tim[u],dis[u].first,dis[u].second,flow[u].first,flow[u].second);
		p1.second*=du[u]; p1=yf(p1);
		for(int i=0;i<G[u].size();i++) {
			int v=G[u][i];
			if(tim[v]==tim[u]) {
				flow[v]=jiafa(flow[v],p1); dis[v]=jiafa(dis[v],p1);
				if(!none[v]) q.push(make_pair(tnew+1,v));
			}
			else { 
//				pair<ll,ll> p2=dis[v];
//				pair<ll,ll> p3=jiafa(p1,p2);
				if(!none[v] /*&& !vis[v]*/) q.push(make_pair(tnew+1,v));
//				vis[v]=1;
				dis[v]=jiafa(dis[v],p1); flow[v]=jiafa(flow[v],p1); tim[v]=tnew+1;
			}
		} flow[u]=make_pair(0ll,1ll);
	}
}

inline void dfs(int x,int p) {
//	printf("%d %d\n",x,p);
	if(!none[x] && dfn[x]<p && dfn[x]) return;
	dfn[x]=p;
	for(int i=0;i<GG[x].size();i++)
		dfs(GG[x][i],p-1);
}

inline bool cmp(int x,int y) {
	return dfn[x]>dfn[y];
}

int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) {
		int x=read(); du[i]=x;
		if(!x) last.push_back(i),none[i]=1,dfn[i]=n;
		while(x--) {
			int y=read();
			G[i].push_back(y);
			GG[y].push_back(i);
		} dis[i].first=0; dis[i].second=1;
		flow[i].first=0; flow[i].second=1;
		if(i<=m) dis[i].first=1,flow[i].first=1;
	} for(int i=0;i<last.size();i++) dfs(last[i],n);
//	for(int i=1;i<=n;i++) printf("%d ",dfn[i]); puts("");
	for(int i=1;i<=m;i++) q.push(make_pair(1,i)),vis[i]=1,tim[i]=1;
	for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end(),cmp);
	bfs();
	for(int i=0;i<last.size();i++) {
		int u=last[i];
		pair<ll,ll> p=mx(dis[u],flow[u]);
		printf("%d %d\n",p.first,p.second/*,flow[u].first,flow[u].second*/);
	}
/*	for(int i=1;i<=n;i++) {
		int u=i;
		pair<ll,ll> p=mx(dis[u],flow[u]);
		printf("%d %d\n",p.first,p.second/*,flow[u].first,flow[u].second);
	}*/
	return 0;
}

