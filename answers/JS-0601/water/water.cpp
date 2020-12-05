#include<bits/stdc++.h>
using namespace std;
const int N=100010;
vector<int>g[N];
long long n,m,d[N],du[N];
struct node{
	long long fz,fm;
	node(){}
	node(long long _fz,long long _fm){
		fz=_fz,fm=_fm;
	}
}dp[N];
queue<int>q;
void tp(){
	for(int i=1;i<=n;i++){
		if(du[i]==0){
			q.push(i);
			dp[i].fz=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(d[u]==0){
			continue;
		}
		int x=__gcd(dp[u].fz,d[u]);
		dp[u].fz/=x;
		dp[u].fm*=d[u]/x;
		for(int i=0;i<g[u].size();i++){
			x=dp[u].fm*dp[g[u][i]].fm/__gcd(dp[u].fm,dp[g[u][i]].fm);
			dp[g[u][i]].fz=dp[u].fz*(x/dp[u].fm)+dp[g[u][i]].fz*(x/dp[g[u][i]].fm);
			dp[g[u][i]].fm=x;
			x=__gcd(dp[g[u][i]].fz,dp[g[u][i]].fm);
			dp[g[u][i]].fz/=x;
			dp[g[u][i]].fm/=x;
			du[g[u][i]]--;
			if(du[g[u][i]]==0){
				q.push(g[u][i]);
			}
		}
	}
}
void in(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		for(int j=1;j<=d[i];j++){
			int a;
			cin>>a;
			g[i].push_back(a);
			du[a]++;
		}
		dp[i].fm=1;
	}
}
void solve(){
	tp();
}
void out(){
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			cout<<dp[i].fz<<" "<<dp[i].fm<<endl;
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	in();
	solve();
	out();
	return 0;
}
