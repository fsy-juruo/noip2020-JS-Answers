#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define N 100005
#define F first
#define S second
#define random(x) (rand()%(x))
int n,m,d[N],deg[N],t[N][5];
ll fz[N],fm[N];
queue<int> q;
inline ll gcd(ll a,ll b){
	ll c;
	while(b){
		c=b;b=a%b;a=c;
	}
	return a;
}
inline ll lcd(ll a,ll b){
	return a/gcd(a,b)*b;
}
int main(){
	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",d+i);
		for(int j=0;j<d[i];++j){
			scanf("%d",t[i]+j);
			++deg[t[i][j]];
		}
		fm[i]=1;
	}
	for(int i=1;i<=m;++i){
		fz[i]=1;
		q.push(i);
	}
	int u,v;
	ll g;
	while(!q.empty()){
		u=q.front();q.pop();
		//printf("(%d:%lld %lld)\n",u,fz[u],fm[u]);
		for(int i=0;i<d[u];++i){
			v=t[u][i];
			//printf("%d:\n",v);
			g=lcd(d[u]*fm[u],fm[v]);
			fz[v]=fz[u]*(g/(d[u]*fm[u]))+fz[v]*(g/fm[v]);
			fm[v]=g;
			g=gcd(fz[v],fm[v]);
			fz[v]/=g;fm[v]/=g;
			--deg[v];
			if(deg[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==0){
			printf("%lld %lld\n",fz[i],fm[i]);
		}
	}
	return 0;
}
