#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
int rdi(){
	int a=0,b=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')b=-1,ch=getchar();
	while(ch>='0'&&ch<='9')a=a*10+ch-'0',ch=getchar();
	return a*b;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int n,m;
int d[100010];
int nxt[100010][10];
int ord[100010],pos;
//vector<int>pre[100010];
bool vis[100010];
void dfs(int x){
	vis[x]=1;
	for(int i=1;i<=d[x];i++){
		int to=nxt[x][i];
		if(vis[to])continue;
		dfs(to);
	}
	ord[++pos]=x;
}
struct Node{
	int x,y;//x/y
	void init(int xx,int yy){
		x=xx,y=yy;
	}
	void yue(){
		int tp=gcd(x,y);
		x/=tp,y/=tp;
	}
	void add(int tx,int ty){
		int resy=y/gcd(y,ty)*ty;
		int resx=resy/y*x+resy/ty*tx;
		x=resx,y=resy;
		yue();
	}
	void add(int t){
		x+=y*t;
	}
//	void add(Node t){
//		add(t.x,t.y);
//	}
}dp[100010];
signed main(){
#ifndef OFFLINE
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
#endif
	n=rdi();
	m=rdi();
//	cin>>n>>m;
	for(int i=1;i<=n;i++){
		d[i]=rdi();
//		cin>>d[i];
//		cout<<i<<endl;
		for(int j=1;j<=d[i];j++){
			nxt[i][j]=rdi();
//			cin>>nxt[i][j];
//			pre[nxt[i][j]].pb(i);
		}
	}
//	cout<<114514<<endl;
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int i=1;i<=n;i++)dp[i].init(0,1);
	for(int i=1;i<=m;i++)dp[i].add(1);
	reverse(ord+1,ord+pos+1);
//	for(int i=1;i<=n;i++)cout<<ord[i]<<' ';
//	puts("");
	for(int i=1;i<=n;i++){
		int x=ord[i];
		for(int j=1;j<=d[x];j++){
			int to=nxt[x][j];
			dp[to].add(dp[x].x,dp[x].y*d[x]);
		}
	}
	for(int i=1;i<=n;i++)if(d[i]==0){
		cout<<dp[i].x<<' '<<dp[i].y<<endl;
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
1 3 2 5 4
*/
