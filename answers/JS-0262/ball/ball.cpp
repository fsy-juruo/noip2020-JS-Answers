#include<bits/stdc++.h>
using namespace std;
int n,m,s,dis[100005];
bool vis[100005];
struct node{int to,dis;};
struct edge{int dis,pos;
	bool operator <(const edge x)const{
		return dis<x.dis;
	}
};
vector<node> g[100005];
priority_queue<edge> q;
void dij(){
	for(int i=1;i<=n;i++) dis[i]=2147483647;
	memset(vis,0,sizeof(vis));dis[s]=0;
	while(!q.empty()) q.pop();q.push((edge){0,s});
	while(!q.empty()){
		edge e=q.top();q.pop();
		int x=e.pos;vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			if(dis[g[x][i].to]>dis[x]+g[x][i].dis){
				dis[g[x][i].to]=dis[x]+g[x][i].dis;
				if(!vis[g[x][i].to]) q.push((edge){dis[g[x][i].to],g[x][i].to});
			}
		}
	}
}
int main( ){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m>>s;int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		g[x].push_back((node){y,z});
	}
	dij();
	for(int i=1;i<=n;i++) cout<<dis[i]<<endl;return 0;
}
