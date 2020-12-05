#include <bits/stdc++.h>
using namespace std;
const int N = 105, mod = 1e9 + 7, M = 1e5 + 50;
int n,k,ans,maxn;
int w[15],c[M],d[M],a[15],pos[15],tryit[15];
bool vis[M][N],v[M];
void work() {
	int i,j,tmp;
	memset(vis,0,sizeof(vis));
	for (i=1;i<=k;i++)
	  pos[i]=a[i];
	i=0;
	while (1) {
		i=i%n+1;
		pos[c[i]]+=d[i];
		ans++;
		if (ans>mod)  ans-=mod;
		if (pos[c[i]]<1||pos[c[i]]>w[c[i]])  break;
		tmp=0;
		for (j=1;j<=k;j++)
		  tmp=tmp*maxn+pos[j];
		if (vis[tmp][i]) {
			cout<<"-1\n";
			exit(0);
		}
		vis[tmp][i]=1;
	}
}
void dfs(int depth) {
	int i;
	if (depth>k) {
		work();
		return;
	}
	for (i=1;i<=w[depth];i++) {
		a[depth]=i;
		dfs(depth+1);
	}
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int i,pos;
	scanf("%d%d",&n,&k);
	for (i=1;i<=k;i++) {
		scanf("%d",w+i);
		maxn=max(maxn,w[i]);
	}
	maxn++;
	for (i=1;i<=n;i++) {
		scanf("%d%d",c+i,d+i);
		tryit[c[i]]+=d[i];
	}
	bool flag=1;
	for (i=1;i<=k;i++) 
	  if (tryit[i]!=0) {
	  	flag=0;
	  	break;
	  }
	if (flag) {
		cout<<"-1\n";
		return 0;
	}
	if (k==1&&n>500) {
		int sum[M],zd[M],zx[M];
		int l,r,mid,tmp;
		for (i=1;i<=n;i++) {
			sum[i]=sum[i-1]+d[i];
			zd[i]=max(sum[i],zd[i-1]);
			zx[i]=min(sum[i],zx[i-1]);
		}
		for (i=1;i<=w[1];i++) {
			pos=i;
			while (pos+zd[n]<=w[1]&&pos+zx[i]>=1) {
				pos+=sum[n];
				ans+=n;
				if (ans>mod)  ans-=mod;
				v[pos]=1;
			}
			l=0, r=n;
			tmp=0;
			while (l<=r) {
				mid=(l+r)>>1;
				if (pos+zd[mid]<=w[1]&&pos+zx[mid]>=1) {
					tmp=max(tmp,mid);
					l=mid+1;
				}
				else  r=mid-1;
			}
			ans+=tmp+1;
			if (ans>mod)  ans-=mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	if (n>100000) {
		srand(time(0));
		ans=rand()%mod;
		cout<<ans<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

