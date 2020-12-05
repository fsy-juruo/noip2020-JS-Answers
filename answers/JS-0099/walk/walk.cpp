#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,w[12];
int p[12][100004];
int Mi[12][100004],Mx[12][100004];
int cur[12];
ll ans;
bool check(int i,ll t){
	if(cur[i]+Mi[i][min(1ll*n,t)]<1)return 1;
	if(cur[i]+Mx[i][min(1ll*n,t)]>w[i])return 1;
	if(t<=2*n&&t>n&&p[i][n]<0){
		ll tim=t/n;
		ll tt=t-tim*n;
		ll pp=tim*p[i][n]+cur[i];
		pp+=Mi[i][tt];
		if(pp<1)return 1;
	}
	if(t<=2*n&&t>n&&p[i][n]>0){
		ll tim=t/n;
		ll tt=t-tim*n;
		ll pp=tim*p[i][n]+cur[i];
		pp+=Mx[i][tt];
		if(pp>w[i])return 1;
	}
	if(t>2*n&&p[i][n]<0){
		ll tim=t/n-1;
		ll tt=t-tim*n;
		ll pp=tim*p[i][n]+cur[i];
		pp+=min(Mi[i][n],p[i][n]+Mi[i][tt-n]);
		if(pp<1)return 1;
	}
	if(t>2*n&&p[i][n]>0){
		ll tim=t/n-1;
		ll tt=t-tim*n;
		ll pp=tim*p[i][n]+cur[i];
		pp+=max(Mx[i][n],p[i][n]+Mx[i][tt-n]);
		if(pp>w[i])return 1;
	}
	return 0;
}
void solve(){
	bool infi=1;
	ll num=1e11;
	for(int i=1;i<=K;i++){
		if(p[i][n]!=0||cur[i]+Mi[i][n]<1||cur[i]+Mx[i][n]>w[i]){
			infi=0;
			ll l=-1,r=1e11;
			while(r>l+1){
				ll mi=(l+r)/2;
				if(check(i,mi))r=mi;
				else l=mi;
			}
			num=min(num,r);
		}
	}
	if(infi){
		puts("-1");exit(0);
	}
	ans+=num;
}
void dfs(int x){
	if(x>K){
		solve();return;
	}
	for(int i=1;i<=w[x];i++){
		cur[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&K);
	for(int i=1;i<=K;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int c,d;scanf("%d%d",&c,&d);
		for(int j=1;j<=K;j++)p[j][i]=p[j][i-1];
		p[c][i]+=d;
		for(int j=1;j<=K;j++)Mi[j][i]=min(Mi[j][i-1],p[j][i]),Mx[j][i]=max(Mx[j][i-1],p[j][i]);
	}
	dfs(1);
	printf("%lld",ans);
}
