#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxd = 10;
int n,m;
int d[maxn],a[maxn][maxd];
int p[maxn],q[maxn];
void dfs(int x){
	if(d[x]==0){
		return ;
	}
	for(int k=1;k<=d[x];k++){
		if(p[a[x][k]]>0){
			p[a[x][k]] = p[a[x][k]]*d[x]*q[x]+q[a[x][k]]*p[x];
			q[a[x][k]] = q[a[x][k]]*d[x]*q[x];
			for(int i=min(p[a[x][k]],q[a[x][k]]);i>=1;i--){
				if(p[a[x][k]]%i==0 && q[a[x][k]]%i==0){
					p[a[x][k]] /= i;
					q[a[x][k]] /= i;
					break;
				}
			}
		}else{
			p[a[x][k]]=1;
			q[a[x][k]]=d[x]*q[x];
		}
		dfs(a[x][k]);
	}
	p[x]=0;q[x]=1;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		p[i]=0;
		q[i]=1;
	}
	for(int i=1;i<=m;i++)
		p[i]=1;
	for(int i=1;i<=m;i++)	
		dfs(i);
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			printf("%d %d\n",p[i],q[i]);
		}
	}
	return 0;
}
