#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,f[100005];
struct node{ll x,y;}p[100005];
vector<ll> g[100005];
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
node pl(ll a,ll x,ll b,ll y){
	node z;z.x=(a*y+b*x);
	z.y=x*y;ll c=gcd(z.x,z.y);
	z.x=z.x/c;z.y=z.y/c;
	return z;
}
node di(ll x,ll y,ll z){
	ll a=gcd(x,z);
	node b;x=x/a;z=z/a;
	b.x=x;b.y=y*z;
	ll c=gcd(b.x,b.y);
	b.x=b.x/c;b.y=b.y/c;
	return b;
}
void bfs(ll a){
	queue<ll> q;while(!q.empty())q.pop();
	q.push(a);while(!q.empty()){
		node y;y.x=0;y.y=0;ll x=q.front();q.pop();
		if(!f[x] && p[x].x==0 && p[x].y==0 && x!=a) continue;
		if(g[x].size()) y=di(p[x].x,p[x].y,g[x].size());
		//cout<<x<<" "<<p[x].x<<" "<<p[x].y<<" "<<g[x].size()<<" "<<y.x<<" "<<y.y<<endl; 
		for(ll i=0;i<g[x].size();i++){
			//cout<<x<<endl;
			if(p[g[x][i]].x!=0 && p[g[x][i]].y!=0)
			p[g[x][i]]=pl(y.x,y.y,p[g[x][i]].x,p[g[x][i]].y);
			else p[g[x][i]]=y;
			//cout<<p[g[x][i]].x<<" "<<p[g[x][i]].y<<endl;
			q.push(g[x][i]);
		}
		if(g[x].size()){p[x].x=0;p[x].y=0;}
	}
}
int main( ){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;ll x,y;
	memset(f,0,sizeof(f));
	for(ll i=1;i<=n;i++){
		cin>>x;for(ll j=1;j<=x;j++){
			cin>>y;
			g[i].push_back(y);
		}
		if(x==0) f[i]=1;
	}
	for(ll i=1;i<=m;i++){
		p[i].x=1;p[i].y=1;bfs(i);
	}
	for(ll i=m;i<=n;i++){
		if(f[i]){
			x=gcd(p[i].x,p[i].y);
			cout<<p[i].x/x<<" "<<p[i].y/x<<endl;
		}
	}
	return 0;
}
/*
5 1
3 2 3 5
2 3 5
2 5 4
0
0
*/
