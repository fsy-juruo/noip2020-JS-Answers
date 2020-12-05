//#   # #####  #### #   # ####  #####
// # #    #   #     ##  # #   #   #
//  #     #    ###  # # # ####    #
//  #   # #       # #  ## #       #
//  #    ##   ####  #   # #     #####
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
	while(b){
		a=a%b;
		swap(a,b);
	}
	return a;
}

int n,m;
vector<int> g[100005],topo;
bool vis[100005],nr[100005];
ll p[100005],q[100005];

void dfs(const int& x){
	vis[x]=true;
	for(int i=0;i<g[x].size();i++){
		const int& y=g[x][i];
		if(!vis[y]){
			dfs(y);
		}
	}
	topo.push_back(x);
}

int main(){

	ios_base::sync_with_stdio(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		static int d;
		cin>>d;
		while(d--){
			static int j;
			cin>>j;
			g[i].push_back(j);
			nr[j]=true;
		}
		q[i]=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	for(int it=n-1;it>=0;it--){
		const int& x=topo[it];
		if(!nr[x])p[x]=1;
		if(g[x].empty())continue;
		ll deg=g[x].size(),cp=p[x]/gcd(p[x],deg),cq=q[x]*(deg/gcd(p[x],deg));
		for(int i=0;i<g[x].size();i++){
			const int& y=g[x][i];
			ll nq=cq/gcd(cq,q[y])*q[y],np=cp*(nq/cq);
			p[y]=p[y]*(nq/q[y])+np;
			q[y]=cq/gcd(cq,q[y])*q[y];
			ll d=gcd(p[y],q[y]);
			p[y]/=d;
			q[y]/=d;
		}
	}
	for(int i=1;i<=n;i++)if(g[i].empty()){
		if(p[i]==0)q[i]=1;
		cout<<p[i]<<' '<<q[i]<<'\n';
	}

	return 0;
}
