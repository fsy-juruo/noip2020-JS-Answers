#include<bits/stdc++.h>
using namespace std;
int n,m,a[105][1005],top[105],ans,x[1000005],y[1000005];
bool check() {
	int cnt=0;
	for(int i=1; i<=n; i++)if(top[i]==m)cnt++;
	if(cnt!=n-1)return 0;
	for(int i=1; i<=n; i++) {
		if(!top[i])continue;
		for(int j=1; j<m; j++)if(a[i][j]!=a[i][j+1])return 0;
	}
	return 1;
}
void dfs(int step) {
	if(step>ans)return;
	if(check()) {
		cout<<step<<endl;
		for(int i=1; i<=step; i++)
			cout<<x[i]<<' '<<y[i]<<endl;
		exit(0);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(top[j]!=m&&top[i]&&i!=j) {
				top[j]++;
				a[j][top[j]]=a[i][top[i]];
				top[i]--;
				x[step+1]=i,y[step+1]=j;
				dfs(step+1);
				x[step+1]=0,y[step+1]=0;
				top[i]++;
				a[i][top[i]]=a[j][top[j]];
				top[j]--;
			}
		}
	}
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)scanf("%d",&a[i][j]),top[i]=m;
	n++;
	for(int i=1; i<=1000; i++) {
		ans=i;
		dfs(0);
	}
	fclose(stdin);
	fclose(stdout);
}
