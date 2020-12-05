#include<bits/stdc++.h>
using namespace std;
int a[57][407],c[47],q[47];
struct node{
	int x,y;
}ans[820007];
int tot,n,m;
void print(int x,int y,int p,int g){
	for(int i=m;i>g;i--) ans[++tot].x=p,ans[tot].y=n+1;
	for(int i=m;i>=y;i--) ans[++tot].x=x,ans[tot].y=n+1;
	ans[++tot].x=x,ans[tot].y=p;
	ans[++tot].x=n+1;ans[tot].y=p;
	for(int i=y+1;i<=m;i++) ans[++tot].x=n+1,ans[tot].y=x;
	for(int i=g+1;i<=m;i++) ans[++tot].x=n+1,ans[tot].y=p;
}
int p(int x){
	if(x+1<=n) return x+1;
	else return 1;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		c[a[i][1]]++;
		if(c[a[i][1]]==1) q[i]=a[i][1];
	}
	for(int i=1;i<=n;i++){
		if(q[i]==0){
			for(int j=1;j<=n;j++)
			if(c[j]==0) q[i]=j,c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]!=q[j]){
				bool o=0;
				for(int k=m;k>=max(m-i+1,i);k--){
					for(int l=1;l<=n;l++){
						if(a[l][k]==q[j]){
							if(l==j) print(l,k,p(l),k),swap(a[l][k],a[p(l)][k]),l=p(l);
							print(j,i,l,k);
							swap(a[j][i],a[l][k]);o=1;
							break;
						}
					}
					if(o) break;
				}
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)
		printf("%d %d\n",ans[i].x,ans[i].y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
