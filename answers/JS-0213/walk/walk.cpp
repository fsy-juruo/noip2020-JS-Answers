#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define rep(i,j,k) for (i=j;i<=k;i++)
#define ll long long
using namespace std;
const ll MOD = 1000000007;
ll ans,d[100005],mn[100005],mx[100005],w[6],o[6],p[6],p1[6],a[6],ci;
int x[100005],T,t,i,j,k,idx,n,m;
void check(){
	int i;
	rep(i,1,m) p1[i]=p[i];
	rep(i,1,n){
		p1[x[i]]+=d[i];
		if (p1[x[i]]>w[x[i]]||p1[x[i]]<1) break;
	}
	ans=(ans+i)%MOD;
}
void dfs(int dep){
	if (dep>m){
		int i,t=1,ci=1e9;
		while (1==1){
			rep(i,1,m)
				if (p[i]+mx[i]>w[i]||p[i]+mn[i]<1){t=0;continue;}
			if (t==0) break;
			if (T==0) {ans=-1;return;}
			rep(i,1,m){
				if (a[i]>0)
					ci=min((ll)ci,(w[i]-p[i]-mx[i])/a[i]);
				if (a[i]<0)
					ci=min((ll)ci,(p[i]-mn[i]-1)/(0-a[i]));
			}
			rep(i,1,m) p[i]=p[i]+a[i]*ci;
			ans=(ans+n*ci)%MOD;
			break;
		}
		check();
	}
	int i;
	if (ans==-1) return;
	rep(i,1,w[dep]) p[dep]=i,dfs(dep+1);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%lld",&w[i]);
	rep(i,1,m) mx[i]=-1e15,mn[i]=1e15;
	rep(i,1,n){
		scanf("%d%lld",&x[i],&d[i]);
		a[x[i]]+=d[i];
		mx[x[i]]=max(mx[x[i]],a[x[i]]);
		mn[x[i]]=min(mn[x[i]],a[x[i]]);
	}
	T=0;
	rep(i,1,m) if (a[i]!=0) T=1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
