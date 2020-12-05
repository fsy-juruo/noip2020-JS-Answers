#include<bits/stdc++.h>
#define N 12
#define M 30
#define L 1005
using namespace std;
typedef long long ll;
int n,m,top[N],a[N][M<<2],ans[L][2],inf,cnt;
bool vis[N],flag;
int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
bool check(int x){
	for(int i=2;i<=m;i++)
		if(a[x][i]!=a[x][1])
			return 0;
	return 1;
}
void dfs(int step,int tot,int las1,int las2){
//	printf("tot:%d\n",tot);
	if(step>inf)return;
	if(tot==n){
		cnt=step-1;
		flag=1;
		return;
	}
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n+1;j++){
			if(i==las2&&j==las1)continue;
			if(i==j)continue;
			if(las2==i)continue;
			if(top[i]>0){
				if(vis[i]&&top[i]>m){
					top[j]++;
					swap(a[j][top[j]],a[i][top[i]]);
					top[i]--;
					if((!vis[j])&&check(j)){
						vis[j]=1;
						dfs(step+1,tot+1,i,j);
						vis[j]=0;
					}
					else dfs(step+1,tot,i,j);
					if(flag){
						ans[step][0]=i;
						ans[step][1]=j;
						return;
					}
					top[i]++;
					swap(a[j][top[j]],a[i][top[i]]);
					top[j]--;
				}
				else {
					top[j]++;
					swap(a[j][top[j]],a[i][top[i]]);
					top[i]--;
					if((!vis[j])&&check(j)){
						vis[j]=1;
						dfs(step+1,tot+1,i,j);
						vis[j]=0;
					}
					else dfs(step+1,tot,i,j);
					if(flag){
						ans[step][0]=i;
						ans[step][1]=j;
						return;
					}
					top[i]++;
					swap(a[j][top[j]],a[i][top[i]]);
					top[j]--;
				}
			}
		}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	inf=n*m*10;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)top[i]=m;
	dfs(1,0,0,0);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}

