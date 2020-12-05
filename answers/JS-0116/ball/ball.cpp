#include<bits/stdc++.h>
using namespace std;
const int N=55,M=405;
int n,m,a[N][M],f1[N],f2[N];
void Print(int x) {
	for(int i=1;i<=x;i++) {
		cout<<f1[i]<<" "<<f2[i]<<"\n";
	}
}
bool check() {
	for(int i=1;i<=n;i++) {
		if(a[i][0]!=m) return false;
		for(int j=2;j<=a[i][0];j++) {
			if(a[i][j]!=a[i][j-1]) return false;
		}
	}
	return true;
}
void dfs(int dep,int x,int y) {
	if(check()) {
		Print(dep-1);
		exit(0);
	}
	if(dep>10) return;
	for(int i=1;i<=n+1;i++) {
		for(int j=1;j<=n+1;j++) {
			if(j==x && i==y) continue;
			if(i==j) continue;
			if(a[i][0]==m) continue;
			if(a[j][0]==1) continue;
			a[i][a[i][0]+1]=a[j][a[j][0]];
			a[i][0]++,a[j][0]--;
			f1[dep]=j,f2[dep]=i;
			dfs(dep+1,i,j); 
			a[i][0]--,a[j][0]++;
		}
	}
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		a[i][0]=m;
		for(int j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	dfs(1,0,0);
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
