#include<bits/stdc++.h>
#define lson(id) (id<<1)
#define rson(id) ((id<<1)|1)
#define pb push_back
#define fi first
#define se second
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vii;

const int maxn=100003;

int n,m,deg[maxn],d[maxn],g[maxn][13];
queue<int> q;

ll gcd(ll x,ll y){
	ll tmp;
	while(y){
		tmp=y;
		y=x%y;
		x=tmp;
	}
	return x;
}

struct frac{
	ll x,y;
	frac(){}
	frac(ll _x,ll _y){x=_x,y=_y;}
	void redu(){
		static ll g;
		g=gcd(x,y);
		x/=g;y/=g;
	}
	void DIV(ll t){
		y*=t;
		redu();
	}
//  x/y
}res[maxn];
frac add(frac x,frac y){
	frac rt;
	rt.x=x.x*y.y+x.y*y.x;
	rt.y=x.y*y.y;
	rt.redu();
	return rt;
}


int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];++j){
			scanf("%d",&g[i][j]);
			++deg[g[i][j]];
		}
	}
	for(int i=1;i<=n;++i){
		if(!deg[i]){
			q.push(i);
			res[i].x=1;
		}res[i].y=1;
	}
	int p,to;
	while(!q.empty()){
		p=q.front();q.pop();
		if(d[p])res[p].DIV(d[p]);
		for(int i=1;i<=d[p];++i){
			to=g[p][i];
			if(!--deg[to])q.push(to);
			res[to]=add(res[to],res[p]);
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==0)printf("%lld %lld\n",res[i].x,res[i].y);
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
*/


