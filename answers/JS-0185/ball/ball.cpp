#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a[100];
int mo[820000][2];
bool check(){
	for(int i=1;i<=n+1;++i){
		if(a[i].size()!=m&&a[i].size())return 0;
		for(int j=0;j<a[i].size();++j){
				if(j!=0)if(a[i][j]!=a[i][j-1])return 0;
			}
		}
	return 1;
}
void dfs(int step){
	if(step>1000)return ;
	if(check()){
		printf("%d\n",step);
		for(int i=1;i<=step;++i){
			printf("%d %d\n",mo[i][0],mo[i][1]);
		}
		exit(0);
	}
	for(int i=1;i<=n+1;++i){
		if(!a[i].size())continue;
		for(int j=1;j<=n+1;++j){
			if(i==j)continue ;
			if(a[j].size()<m){
				a[j].push_back(a[i][a[i].size()-1]);
				a[i].pop_back();
				mo[step+1][0]=i;mo[step+1][1]=j;
				dfs(step+1);
				mo[step+1][0]=0;mo[step+1][1]=0;
				a[i].push_back(a[j][a[j].size()-1]);
				a[j].pop_back();
			}
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
				int x;
				scanf("%d",&x);
				a[i].push_back(x);
		}
	}
	dfs(0);
	return 0;
}

