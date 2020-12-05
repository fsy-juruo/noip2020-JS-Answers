#include<bits/stdc++.h>
#define N 100005
#define ll long long
#define F(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
struct st{ll x,y;}a[N],z;
ll n,m,k[N],v,as[N],si=0;
vector<ll>g[N];
ll gcd(ll a,ll b){
	while(b){ll t=a%b;a=b;b=t;}
	return a;
}
st add(st p,st q){
	if(!p.x&&!p.y)return q;
	if(!q.x&&!q.y)return p;
	ll t=p.y/gcd(p.y,q.y)*q.y;
	p.x*=t/p.y;q.x*=t/q.y;
	return (st){p.x+q.x,t};
}
st dfs(ll t){
	if(a[t].x&&a[t].y)return a[t];
	int se=g[t].size()-1;st l=(st){0,0};
	F(i,0,se){z=dfs(g[t][i]);z.y*=k[g[t][i]];l=add(l,z);}
	a[t]=l;return l;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(0);cin>>n>>m;F(i,1,n){
		cin>>k[i];if(k[i]>0)F(j,1,k[i])
		{cin>>v;g[v].push_back(i);}
		else as[++si]=i;
	}
	F(i,1,m)a[i]=(st){1,1};F(i,1,si){
		ll w=as[i];a[w]=dfs(w);
		ll rt=gcd(a[w].x,a[w].y);
		cout<<a[w].x/rt<<' '<<a[w].y/rt<<endl;
	}
	return 0;
}
