#include<bits/stdc++.h>
#define MAXN 500005
#define ll long long
#define MOD 1000000007
using namespace std;
ll A[15],now[15],x[15];
ll ans,w[15];
int n,k,c[MAXN],d[MAXN],maxn[15],minn[15];
bool vis[15];
bool check(ll value,int i)
{
	if(value<=0 || value>w[i]) return false;
	return true;
}
void dfs(int depth)
{
	if(depth>k){
		bool flag=1,f=1;
		for(int i=1;i<=k;i++) x[i]=now[i];
		ll Num=0;
		while(1){
			Num++;
			for(int j=1;j<=k;j++)
			if(!check(x[j]+maxn[j],j) || !check(x[j]+minn[j],j)){
				f=0; break;
			}
			if(Num>=MOD) Num%=MOD;
			if(!f){
				Num--;
				ans+=Num*n;
				if(ans>=MOD) ans%=MOD;
				break;
			}
			for(int j=1;j<=k;j++) x[j]+=A[j];
		}
		for(int i=1;i<=n;i++){
			x[c[i]]+=(ll)d[i];
			if(!check(x[c[i]],c[i])) flag=0;
			ans++;
			if(ans>=MOD) ans%=MOD;
			if(!flag) break;
		}
	}
	for(int i=1;i<=w[depth];i++){
		now[depth]=i;
		dfs(depth+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		A[c[i]]+=(ll)d[i];
		if(!vis[c[i]]){
			maxn[c[i]]=minn[c[i]]=(ll)d[i];
			vis[c[i]]=1;
		}
		else{
			maxn[c[i]]=maxn[c[i]]>A[c[i]]?maxn[c[i]]:A[c[i]];
			minn[c[i]]=minn[c[i]]<A[c[i]]?minn[c[i]]:A[c[i]];
		}
	}
	int lf=0;
	for(int i=1;i<=k;i++)
	if(A[i]==0 && maxn[i]<w[i] && minn[i]>-w[i]) lf++;
	if(lf==k){
		printf("-1");
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
