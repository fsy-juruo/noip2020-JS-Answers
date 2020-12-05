#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
struct fenshu{ll p,q;};
fenshu add(fenshu a,fenshu b){
	ll l=lcm(a.q,b.q);
	a.p=l/a.q*a.p,a.q=l;
	b.p=l/b.q*b.p;
	a.p+=b.p;
	ll g=gcd(a.p,a.q);
	a.p/=g,a.q/=g;
	return a;
}
fenshu mul(fenshu a,int b){
	a.q*=b;
	ll g=gcd(a.p,a.q);
	a.p/=g,a.q/=g;
	return a;
}
vector<int>g[100004];
fenshu ans[100004],cur[100004];
int A[100004],cnt,d[100004];
bool vis[100004];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<g[x].size();i++)if(!vis[g[x][i]])dfs(g[x][i]);
	A[++cnt]=x;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]),g[i].resize(d[i]);
		for(int j=0;j<d[i];j++)scanf("%d",&g[i][j]);
		ans[i].p=0,ans[i].q=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)cur[j].p=0,cur[j].q=1;
		cur[i].p=1,cur[i].q=1;
		for(int j=n;j;j--){
			int x=A[j];
			if(d[x]>0){
				cur[x]=mul(cur[x],d[x]);
				for(int k=0;k<d[x];k++)cur[g[x][k]]=add(cur[g[x][k]],cur[x]);
				cur[x].p=0,cur[x].q=1;
			}else ans[x]=add(ans[x],cur[x]);
		}
	}
	for(int i=1;i<=n;i++)if(d[i]<1)
		printf("%lld %lld\n",ans[i].p,ans[i].q);
}
