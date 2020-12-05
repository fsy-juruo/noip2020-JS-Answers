#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
const ll N=1e5+10;
ll n,m,in[N],d[N];
vector<ll>g[N];
queue<ll>q;
ll gcd(ll a,ll b){
	return !b?a:gcd(b,a%b);
}
struct fen{
	ll x,y;
	fen(){
		y=1;
	}
	fen operator/(const ll p)const{
		fen a;
		a.y=y*p;
		a.x=x;
		ll t=gcd(a.y,a.x);
		a.y/=t,a.x/=t;
		return a;
	}
	fen operator+(const fen p)const{
		fen a;
		ll g=gcd(y,p.y);
		ll bei=y*p.y/g;
		ll xx1=bei/y*x,xx2=bei/p.y*p.x;
		a.x=xx1+xx2;
		a.y=bei;
		ll t=gcd(a.y,a.x);
		a.y/=t,a.x/=t;
		return a;
	}
};
fen f[N];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		d[i]=read();
		for(ll j=1,a;j<=d[i];j++){
			a=read();
			g[i].push_back(a);in[a]++;
		}
	}
	for(ll i=1;i<=n;i++)
		if(!in[i])q.push(i),f[i].x=f[i].y=1;
	while(!q.empty()){
		ll u=q.front();q.pop();
		for(ll i=0;i<g[u].size();i++){
			ll v=g[u][i];
			f[v]=f[v]+f[u]/d[u];
			if(!--in[v])q.push(v);
		}
	}
	for(ll i=1;i<=n;i++)
		if(!d[i])cout<<f[i].x<<" "<<f[i].y<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

