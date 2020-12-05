#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
typedef long long ll;
int n,k,ans=0;
int w[55];
int c[500005],d[500005];
int dist[10000005],cur[55],a[55];
int solve(){
	int step=0;
	for(int i=1;i<=k;i++)a[i]=cur[i];
	for(int _=0;_<12;_++){
		for(int j=1;j<=n;j++){
			a[c[j]]+=d[j];step++;
			if(a[c[j]]<=0||a[c[j]]>w[c[j]]){
				return step;
			}
		}
	}
	puts("-1");
	exit(0);
}
void dfs(int x){
	if(x==k+1){
		ans+=solve();
		ans%=mod;
		return;
	}
	for(int i=1;i<=w[x];i++){
		cur[x]=i;dfs(x+1);
	}
}
void bfsolve(){
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&d[i]);
	ll sum=n;
	for(int i=1;i<=n;i++){
		sum*=w[i];
		if(sum>1e7)break;
	}
	if(sum<=1e7){
		bfsolve();
		return 0;
	}
	puts("-1");
	return 0;
}
