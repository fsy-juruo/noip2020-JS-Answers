#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mp make_pair
inline ll read(){
	ll x=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
inline void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10|48);
}
inline void writeln(ll x,char ch){
	write(x),putchar(ch);
}
vector<int> edge[100005];
queue<int> q;
int d[100005],e[100005];
pair<ll,ll> f[100005],tmp;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
inline pair<ll,ll> pls(pair<ll,ll> a,pair<ll,ll> b){
	pair<ll,ll> ans;
	ans.fi=a.fi*b.se+a.se*b.fi;
	ans.se=a.se*b.se;
	ll g=gcd(ans.fi,ans.se);
	return mp(ans.fi/g,ans.se/g);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n=read(),m=read(),x,u,v;
	for(int i=1;i<=n;++i){
		e[i]=read();
		f[i]=mp(0,1);
		for(int j=1;j<=e[i];++j){
			x=read();
			edge[i].push_back(x);
			++d[x];
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==0){
			q.push(i);
			f[i]=mp(1,1);
		}
	}
	while(!q.empty()){
		u=q.front();
		q.pop();
		tmp=mp(f[u].fi,f[u].se*edge[u].size());
		for(int i=0;i<edge[u].size();++i){
			v=edge[u][i];
			--d[v];
			f[v]=pls(f[v],tmp);
			if(d[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;++i){
		if(e[i]==0){
			writeln(f[i].fi,' ');
			writeln(f[i].se,'\n');
		}
	}
	return 0;
}
