#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define gc getchar
using namespace std;

inline int read(){
	int x=0,y=1;char c=gc();while(c<'0'||c>'9'){if(c=='-') y=-1;c=gc();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();return (y==1)?x:-x;
}

const int N=100005;
int n,m,in[N],out[N];
int ver[N*5],nxt[N*5],head[N],tot;

struct num{
	ll p,q;
} val[N];

inline ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

inline num add(num x,num y){
	num res;
	res.q=x.q*y.q/gcd(x.q,y.q);
	res.p=x.p*(res.q/x.q)+y.p*(res.q/y.q);
	ll tmp=gcd(res.p,res.q);
	res.p/=tmp;
	res.q/=tmp;
	return res;
}

inline num div(num x,int y){
	num res;
	ll tmp=gcd(x.p,y);
	res.q=x.q*y/tmp;
	res.p=x.p/tmp;
	return res;
}

inline void link(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;
}

queue<int> q;

inline void topsort(){
	for(int i=1;i<=n;i++){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i];
			in[y]--;
			val[y]=add(val[y],div(val[x],out[x]));
			if(in[y]==0) q.push(y);
		}
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		int x=read();out[i]=x;
		for(int j=1;j<=x;j++){
			int y=read();
			link(i,y);
			in[y]++;
		}
	}
	for(int i=1;i<=m;i++){
		val[i].p=val[i].q=1;
	}
	for(int i=m+1;i<=n;i++){
		val[i].p=0;val[i].q=1;
	}
	topsort();
	for(int i=1;i<=n;i++){
		if(out[i]==0) printf("%lld %lld\n",val[i].p,val[i].q);
	}
	return 0;
}

















