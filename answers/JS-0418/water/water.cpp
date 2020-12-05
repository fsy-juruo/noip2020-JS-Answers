#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{ll p,q;}ans[100003],start;
int n,m,a[100003][8],d[100003];
inline ll gcd(ll x,ll y){
	while(y^=x^=y^=x%=y);
	return x;
}
inline void dfs(int x,node s){
	if(d[x]==0){
		if(ans[x].q==0){ans[x]=s;return;}
		ans[x].p=(ll)ans[x].q*s.p+ans[x].p*s.q;
		ans[x].q=(ll)ans[x].q*s.q;
		ll c=gcd(ans[x].q,ans[x].p);
		ans[x].q/=c;
		ans[x].p/=c;
		return;
	}
	s.q*=d[x];
	for(int i=0;i<d[x];++i)dfs(a[x][i],s);
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	start.p=start.q=1;
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		if(d[i]==0)ans[i].p=ans[i].q=0;
		for(int j=0;j<d[i];++j)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;++i)dfs(i,start);
	for(int i=1;i<=n;++i)if(d[i]==0)printf("%lld %lld\n",ans[i].p,ans[i].q);
	return 0;
}
