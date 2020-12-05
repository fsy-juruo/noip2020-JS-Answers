#include <bits/stdc++.h>
using namespace std;
ifstream fin("ball.in");
ofstream fout("ball.out");
typedef pair<int,int> pii;
const int N=18,M=28;
int n,m,col[N][M],cnt[N];
deque<pii> q;
bool check(){
	for(int i=1;i<=n+1;++i){
		if(!cnt[i]) continue;
		if(cnt[i]!=m) return 0;
		int c=col[i][1];
		for(int j=1;j<=m;++j)
			if(col[i][j]!=c) return 0;
	}
	return 1;
}
void dfs(int p){
	if(p>=50) return;
	if(check()){
		fout<<p<<'\n';
		int ss=q.size();
		for(int i=0;i<ss;++i)
			fout<<q[i].first<<' '<<q[i].second<<'\n';
		exit(0);
	}
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=n+1;++j){
			if(i==j) continue;
			if(cnt[i]&&cnt[j]<m){
				col[j][++cnt[j]]=col[i][cnt[i]];
				--cnt[i];
				q.push_back(pii(i,j));
				dfs(p+1);
				q.pop_back();
				col[i][++cnt[i]]=col[j][cnt[j]];
				--cnt[j];
			}
		}
	}
}
int main(){
	fin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)
			fin>>col[i][j];
		cnt[i]=m;
	}
	dfs(0);
	
	return 0;
}
