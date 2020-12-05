#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read(){
	int res=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0',c=getchar();
	return res;
}

ll gcd(ll x,ll y){
	if(x==0||y==0) return 1;
	if(x<y) swap(x,y);
	ll z=x%y;
	while(z){
		x=y;
		y=z;
		z=x%y;
	}
	return y;
}
struct fen{
	ll x,y;
};
const fen yi=(fen){1,1};
const fen ling=(fen){0,1};
inline void yue(fen &x){
	if(x.x==0){
		x=ling;
		return;
	}
	ll k=gcd(x.x,x.y);
	x.x/=k;
	x.y/=k;
}
inline fen add(fen x,fen y){
	ll k=x.y*y.y/gcd(x.y,y.y);
	ll xx=k/x.y;
	ll yy=k/y.y;
	x.x=x.x*xx+y.x*yy;
	x.y=k;
	yue(x);
	return x;
}

#define N 100005
#define M 500005
int n,m,st[15];
struct node{
	int to,next;
}g[M];
int tot,head[N];
inline void addedge(int x,int y){
	g[++tot].to=y;
	g[tot].next=head[x];
	head[x]=tot;
}
fen a[N];
int in[N],out[N];
queue<int> q;

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		int d=read();
		out[i]=d;
		while(d--){
			int y=read();
			addedge(i,y);
			in[y]++;
		}
	}
	for(int i=1;i<=m;i++) a[i]=yi;
	for(int i=m+1;i<=n;i++) a[i]=ling;
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int num=0;
		for(int i=head[x];i;i=g[i].next){
			num++;
			int y=g[i].to;
			in[y]--;
			if(!in[y]) q.push(y);
		}
		if(!num) continue;
		a[x].y*=num;
		yue(a[x]);
		for(int i=head[x];i;i=g[i].next){
			int y=g[i].to;
			a[y]=add(a[x],a[y]);
		}
		a[x]=ling;
	}
	for(int i=1;i<=n;i++){
		if(!out[i]){
			printf("%lld %lld\n",a[i].x,a[i].y);
		}
	}
	return 0;
}
