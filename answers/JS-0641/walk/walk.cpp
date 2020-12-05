#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n,k,w[105],c[500005],d[500005],pre[500005][5],a[105],Max1[15][500005],Max2[15][500005],now[105];
long long ans;
bool flag;
void update() {
	int Min1,Min2,Min;
	Min1=Min2=Min=1e9;
	for(int i=1; i<=k; i++)now[i]=a[i];
	for(int i=1; i<=k; i++) {
		int p1,p2;
		p1=lower_bound(Max1[i]+1,Max1[i]+n+1,w[i]-now[i]+1)-Max1[i];
		p2=lower_bound(Max2[i]+1,Max2[i]+n+1,now[i])-Max2[i];
		Min1=min(Min1,p1);
		Min2=min(Min2,p2);
	}
	if(Min1==n+1&&Min2==n+1) {
		for(int i=1; i<=k; i++) {
			if(pre[n][i]>0)
				Min=min(Min,(w[i]-now[i]-Max1[i][n])/pre[n][i]+1);
			else if(pre[n][i]<0)
				Min=min(Min,(now[i]-Max2[i][n]-1)/(-pre[n][i])+1);
			else continue;
		}
		ans+=((ll)n*Min)%mod;
		ans%=mod;
		for(int i=1; i<=k; i++)now[i]+=Min*pre[n][i];
	} else {
		ans+=min(Min1,Min2);
		ans%=mod;
		return;
	}
	for(int i=1; i<=k; i++) {
		int p1,p2;
		p1=lower_bound(Max1[i]+1,Max1[i]+n+1,w[i]-now[i]+1)-Max1[i];
		p2=lower_bound(Max2[i]+1,Max2[i]+n+1,now[i])-Max2[i];
		Min1=min(Min1,p1);
		Min2=min(Min2,p2);
	}
	ans+=min(Min1,Min2);
	ans%=mod;
	return;
}
void dfs(int step) {
	if(step==k+1) {
		update();
		return;
	}
	for(int i=1; i<=w[step]; i++) {
		a[step]=i;
		dfs(step+1);
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; i++)scanf("%d",&w[i]);
	for(int i=1; i<=n; i++)scanf("%d%d",&c[i],&d[i]);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++)pre[i][j]=pre[i-1][j];
		pre[i][c[i]]+=d[i];
	}
	for(int i=1; i<=k; i++)flag|=pre[n][i];
	if(!flag) {
		for(int i=1; i<=k; i++)
			if(Max1[i][n]+Max2[i][n]>=w[i])flag=1;
		if(!flag) {
			cout<<-1<<endl;
			return 0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=k; j++) {
			Max1[j][i]=max(Max1[j][i-1],pre[i][j]);
			Max2[j][i]=max(Max2[j][i-1],-pre[i][j]);
		}
	}
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}
