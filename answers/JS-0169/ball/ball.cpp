#include <bits/stdc++.h>
#define MAXN 15
#define MAXM 25
using namespace std;
int n,m,a[MAXN][MAXM],top[MAXN],lim;
int x[100],y[100];

bool check(){
	for(int i=1;i<=n+1;++i)
		for(int j=1;j<m;++j)
			if(a[i][j]!=a[i][j+1]) return 0;
	return 1;
}

bool dfs(int dep,int former){
	if(dep==lim) return check();
	for(int i=1;i<=n+1;++i){
		if(!top[i]) continue;
		int ball=a[i][top[i]];
		a[i][top[i]--]=0;
		for(int j=1;j<=n+1;++j){
			if(i==j || j==former || top[j]==m) continue;
			a[j][++top[j]]=ball;
			if(dfs(dep+1,i)){
				a[j][top[j]--]=0;
				x[dep]=i,y[dep]=j;
				return 1;
			}
			a[j][top[j]--]=0;
		}
		a[i][++top[i]]=ball;
	}
	return 0;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;top[i++]=m)
		for(int j=1;j<=m;++j) cin>>a[i][j];
	top[n+1]=0;
	for(lim=0;;++lim) if(dfs(0,0)) break;
	cout<<lim<<endl;
	for(int i=0;i<lim;++i) cout<<x[i]<<' '<<y[i]<<endl;
	return 0;
}
