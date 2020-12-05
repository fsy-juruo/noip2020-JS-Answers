#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5,mod=1e9+7;
ll n,k,ans,a[12],c[N],d[N],w[12],dp[12][N*2];
ll gao(int x,ll y){
	if(y==0)return 0;
	if(y*a[x]<=0)return 1e15;
	return y/a[x];
}
void dfs(int x,ll b[12]){
	if(x>k){
		ll sum=1e15,res=0;
/*		for(int i=1;i<=k;i++){
			ll u=N-b[i],v=N+w[i]-b[i];
			sum=min(sum,min(gao(i,b[i]),gao(i,w[i]-b[i])));
//			sum=min(sum,min(dp[i][u],dp[i][v]));
		}*/
		sum=0;
//		sum=max(0ll,sum-10);
		ll g[12];
		for(int i=1;i<=k;i++)
			g[i]=b[i];
		for(int i=1;i<=k;i++)
			g[i]+=sum*a[i];
		for(;;res++){
			bool y=true;
			for(int i=1;i<=k;i++)
				if(g[i]>w[i] or g[i]<1){
					y=false;
					break;
				}
			if(!y)break;
			g[c[res%n+1]]+=d[res%n+1];
		}
		ans=(ans+res+sum*n)%mod;
		return ;
	}
	for(int i=1;i<=w[x];i++){
		b[x]=i;
		dfs(x+1,b);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&c[i],&d[i]);
		a[c[i]]+=d[i];
	}
	for(int i=1;i<=k;i++){
		ll x=a[i];
		dp[i][N]=0;
		if(x==0)continue;
		if(x>0){
			for(int j=1;j*x<=w[i]+10;j++)
				dp[i][N+j*x]=1;
			for(int j=1;j<=w[i]-10;j++){
				if(dp[i][j+N]>1e15)dp[i][j+N]=0;
				dp[i][j+N]+=dp[i][j-1+N];
			}
			continue;
		}
		for(int j=1;j*x>=-w[i]-10;j++)
			dp[i][N+j*x]=1;
		for(int j=1;j<=w[i]+10;j++){
			if(dp[i][N-j]>1e15)dp[i][N-j]=0;
			dp[i][N-j]+=dp[i][N-j+1];
		}
	}
	ll b[12];
	memset(b,0,sizeof(b));
	for(int i=1;i<=w[1];i++){
		b[1]=i;
		dfs(2,b);
	}
	printf("%lld",ans);
	return 0;
}
//I AK IOI
/*
3 2
3 3
1 1
2 -1
1 1
*/
