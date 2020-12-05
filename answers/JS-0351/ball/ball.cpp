#include <bits/stdc++.h>
#define ll long long
#define re register
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int maxn=50+5;
const int maxm=400+5;
const int maxstep=820000+5;
//const int INF=;
struct record {
	int from,to;
}path[maxstep];
int n,m,a[maxn][maxm],top[maxn];
bool check(){
	for(re int i=1;i<=n+1;i++){
		for(re int j=2;j<=top[i];j++){
			if(a[i][j]!=a[i][1]) return false; 
		}
	}
	return true;
}
void print(int step){
	printf("%d\n",step);
	for(re int i=1;i<step;i++){
		printf("%d %d\n",path[i].from,path[i].to);
	}
	exit(0);
}
void dfs(int step){
	//printf("1\n");
	if(step>820000) return;
	if(check()){
		print(step);
	}
	for(re int i=1;i<=n+1;i++){
		if(!top[i]) continue;
		for(re int j=1;j<=n+1;j++){
			if(i==j || top[j]>=m) continue;
			path[step].from=i;
			path[step].to=j;
			a[j][++top[j]]=a[i][top[i]--];
			dfs(step+1);
			a[i][++top[i]]=a[j][top[j]--];
			path[step].from=0;
			path[step].to=0;
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++){
		top[i]=m;
		for(re int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1);
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
