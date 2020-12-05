#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> g[100005];
int deg[100005];
int q[200005],f,r;
int out[200005],h;
long long gcd(long long x,long long y){
	if(x<y){
		swap(x,y);
	}
	while(y){
		long long r=x%y;
		x=y;
		y=r;
	}
	return x;
}
bool st[100005];
struct frac{
	long long a,b;
	void simplify(){
		long long d=gcd(a,b);
		a/=d;
		b/=d;
	}
	frac(long long _a=1ll,long long _b=1ll):a(_a),b(_b){
		simplify();
	}
}v[100005];
frac operator + (frac x,frac y){
	frac res=frac(x.a*y.b+y.a*x.b,x.b*y.b);
	return res;
}
frac operator += (frac &x,frac y){
	x=x+y;
	return x;
}
frac operator / (frac x,long long y){
	frac res=frac(x.a,x.b*y);
	return res;
}
frac operator /= (frac &x,long long y){
	x=x/y;
	return x;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(out,0,sizeof(out));
	h=0;
	for(int i=1;i<=n;++i){
		int sz;
		scanf("%d",&sz);
		g[i].resize(sz);
		if(sz==0){
			h++;
			out[h]=i;
		}
		for(int j=0;j<sz;++j){
			scanf("%d",&g[i][j]);
			deg[g[i][j]]++;
		}
	}
	memset(st,0,sizeof(st));
	memset(q,0,sizeof(q));
	f=1,r=0;
	for(int i=1;i<=m;++i){
		v[i]=frac(1ll,1ll);
		r++;
		q[r]=i;
		st[i]=1;
	}
	while(f<=r){
		int fr=q[f];
		f++;
		long long sz=g[fr].size();
		frac add=v[fr];
		if(sz>0){
			add/=sz;
		}
		for(int i=0;i<g[fr].size();++i){
			int u=g[fr][i];
			if(!st[u]){
				v[u]=add;
				st[u]=1;
			}
			else{
				v[u]+=add;
			}
			deg[u]--;
			if(deg[u]==0){
				r++;
				q[r]=u;
			}
		}
	}
	for(int i=1;i<=h;++i){
		int oa=v[out[i]].a,ob=v[out[i]].b;
		printf("%d %d\n",oa,ob);
	}
	return 0;
}

