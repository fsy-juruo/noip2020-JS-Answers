#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N=60,M=410;
int n,m,a[N][M],sum[N];
int cnt;
bool dfs() {
	if(sum[n+1]==m) {
		printf("%d\n",cnt);
		return true;
	}
	for(int i=1;i<=n+1;i++) {
		for(int j=1;j<=n+1;j++) {
			if(i!=j&&sum[j]<m&&sum[i]>=1) {
				sum[j]++;
				a[j][sum[j]]=a[i][sum[i]];
				sum[i]--;
				cnt++;
				bool tmp=dfs();
				if(tmp) {
					printf("%d %d\n",i,j);
				}
				sum[i]++;
				a[i][sum[i]]=a[j][sum[j]];
				sum[j]--;
				cnt--;
				if(tmp) {
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		sum[i]=m;
		for(int j=1;j<=m;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	dfs();
	return 0;
}

