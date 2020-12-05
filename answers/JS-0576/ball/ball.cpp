#include<bits/stdc++.h>
#include<vector>
#define N 820001
#define gc getchar()
using namespace std;
int c[N][2];
int n,m;
bool f=0;
vector<int> g[52];
inline int r(){
	int y=0;
	char c=gc;
	while(!isdigit(c))c=gc;
	while(isdigit(c))y=(y<<1)+(y<<3)+c-48,c=gc;
	return y;
}
inline bool check(){
	for(int i=1;i<=n+1;i++){
		if(g[i].empty())continue;
		register int s=g[i].front();
		for(int j=1;j<g[i].size();j++){
			if(s!=g[i][j])return 0;
		}
	}
	return 1;
}
//inline bool xin(int x){
//	for(int i=2;i<=x/2;++i){
//		register bool fl=1;
//		register int z=x-i-1;
//		for(int j=x-1;j>=x-z;--j){
//			if(c[j][0]!=c[j-i][0]||c[j][1]!=c[j-i][1]){
//				fl=0;
//			}
//		}
//		if(fl)return 1;
//	}
//	return 0;
//}
void dfs(int x,int li,int lj){
	if(x>=20000||f)return;
	if(check()){
		printf("%d\n",x-1);
		for(int i=1;i<x;i++){
			printf("%d %d\n",c[i][0],c[i][1]);
		}
		f=1;
		return;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			if(i==j||g[i].empty()||g[j].size()==m||li==i&&lj==j)continue;
			c[x][0]=i;
			c[x][1]=j;
			g[j].push_back(g[i].back());
			g[i].pop_back();
			dfs(x+1,i,j);
			g[i].push_back(g[j].back());
			g[j].pop_back();
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=r(),m=r();
	for(int i=1;i<=n;i++){
		register int l;
		for(int j=1;j<=m;j++)l=r(),g[i].push_back(l);
	}
	dfs(1,0,0);
	return 0;
}
/*
2 3
1 1 2
2 1 2

*/
