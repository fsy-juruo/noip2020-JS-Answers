#include<bits/stdc++.h>
#define MAXN 820005
using namespace std;
int pathx[MAXN],pathy[MAXN],now[55][405],n,m,head[55],to_d[55],ans,cnt,f;
int depth;
bool check()
{
	for(int i=1;i<=n;i++)
	if(to_d[i]!=m && to_d[i]) return false;
	return true;
}
void exchange(int x,int y)
{
	if(to_d[x]==head[x]) to_d[x]--;
	if((to_d[y]==head[y] && now[x][head[x]]==now[y][1]) || !head[y]) to_d[y]++;
	now[y][++head[y]]=now[x][head[x]];
	now[x][head[x]]=0; head[x]--;
}
void dfs(int d)
{
	if(check()){
		ans=d-1; f=1;
		return;
	}
	if(d>depth) return;
	for(int i=1;i<=n+1;i++){
		for(int j=n+1;j>=1;j--)
	 	if(i!=j && head[i]>0 && head[j]<m){
	 		exchange(i,j);
	 		pathx[d]=i; pathy[d]=j;
	 		dfs(d+1);
	 		exchange(j,i);
	 		if(f) return;
	 	}
	}
	 
	 return;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++) scanf("%d",&now[i][j]);
	for(int i=1;i<=n;i++) head[i]=m;
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 if(now[i][j]==now[i][1]) to_d[i]++;
	 else break;
	f=0;
	for(depth=0;depth<=MAXN-5;depth++){
		dfs(1);
		if(f) break;
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d %d\n",pathx[i],pathy[i]);
	return 0;
}
