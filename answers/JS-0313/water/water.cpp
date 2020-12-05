#include<bits/stdc++.h>
#define ull unsigned long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pii pair<unsigned long long,unsigned long long>
//rp++!
using namespace std;
vector<int> g[100005];
int in[100005],out[100005];
int now[100005],vis[100005];
struct nod{
	ull p,q;
};
nod ans[100005],rans[100005];
int n,m;
nod calc(nod a,nod b){
	nod ret;
	ull ha=__gcd(a.q,b.q);
	ret.q=a.q/ha*b.q;
	ret.p=b.q/ha*a.p+
		  a.q/ha*b.p;
	ha=__gcd(ret.p,ret.q);
	ret.p/=ha;
	ret.q/=ha;
	return ret;
}
nod times(nod a,int num){
	ull ha=__gcd(a.p,(ull)num);
	a.p/=ha;
	a.q=num/ha*a.q;
	return a;
}
void dfs(int v){
	for(int i=0;i<(int)g[v].size();i++){
		int to=g[v][i];
		now[to]++;
		if(vis[to]) continue;
		vis[to]=1;
		dfs(to);
	}
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int ha=q.front();
		q.pop();
		nod ooo=times(rans[ha],g[ha].size());
		for(int i=0;i<(int)g[ha].size();i++){
			int to=g[ha][i];
			--now[to];
			rans[to]=calc(rans[to],ooo);
			if(!now[to]){
				q.push(to);
			}
		}
	}
}
int main(){
	//remember to use freopen!
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(in,0,sizeof(in));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		out[i]=x;
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			g[i].pb(y);
			in[y]++;
		}
	}
	for(int i=1;i<=n;i++){
		ans[i].p=0;
		ans[i].q=1;
	}
	for(int i=1;i<=n;i++){
		if(!in[i]){
			for(int j=1;j<=n;j++){
				rans[j].p=0;
				rans[j].q=1;
			}
			memset(vis,0,sizeof(vis));
			memset(now,0,sizeof(now));
			vis[i]=1;
			rans[i].p=1;
			dfs(i);
			bfs(i);
			for(int j=1;j<=n;j++)
				ans[j]=calc(rans[j],ans[j]);
		}
	}
	for(int i=1;i<=n;i++)
		if(!out[i])
			printf("%lld %lld\n",ans[i].p,ans[i].q);
	return 0;
}
//remember to use long long or unsigned long long
//remember to clear the...array?
//remember to read problems carefully
//think carefully before writing
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
