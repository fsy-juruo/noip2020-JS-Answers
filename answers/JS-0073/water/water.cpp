#include <bits/stdc++.h>
using namespace std;
ifstream fin("water.in");
ofstream fout("water.out");
typedef long long ll;
const int N=1e5+8;
int n,m,d[N],in[N];
vector<int> g[N];
ll fz[N],fm[N];
ll gcd(ll a,ll b){
	ll c;
	while(b) c=a,a=b,b=c%b;
	return a;
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
void add(ll &zfz,ll &zfm,ll xfz,ll xfm,ll yfz,ll yfm){
	zfm=lcm(xfm,yfm);
	ll xmul=zfm/xfm,ymul=zfm/yfm;
	xfz*=xmul,yfz*=ymul;
	zfz=xfz+yfz;
	ll gc=gcd(zfz,zfm);
	zfz/=gc,zfm/=gc;
}
void toposort(){
	queue<int> q;
	for(int i=1;i<=m;++i) fz[i]=1;
	for(int i=1;i<=n;++i) fm[i]=1;
	for(int i=1;i<=n;++i)
		if(!in[i]) q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ll gc=gcd(fz[u],d[u]);
		ll nfz=fz[u]/gc,nd=d[u]/gc;
		ll nfm=fm[u]*nd;
		for(int i=0;i<d[u];++i){
			int v=g[u][i];
			--in[v];
			add(fz[v],fm[v],fz[v],fm[v],nfz,nfm);
			if(!in[v]) q.push(v);
		}
	}
}
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;++i){
		fin>>d[i];
		g[i].resize(d[i]);
		for(int j=0;j<d[i];++j){
			fin>>g[i][j];
			++in[g[i][j]];
		}
	}
	toposort();
	for(int i=1;i<=n;++i)
		if(!d[i]) fout<<fz[i]<<' '<<fm[i]<<'\n';
	return 0;
}
