#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100005;
const int INF=1000000007;

int read(){
	int x=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}
	return x*f;
}

struct frac{
	ll p,q;//p fenzi q fenmu
	frac():p(0),q(1){}
	frac(ll x):p(x),q(1){}
	frac(ll _p,ll _q):p(_p),q(_q){}
	void clean(){
		ll g=__gcd(p,q);
		p/=g;
		q/=g;
	}
	frac operator+(const frac& other){
		frac ret;
		ret.q=q*other.q;
		ret.p=q*other.p+p*other.q;
		ret.clean();
		return ret;
	}
	frac operator+=(const frac& other){
		ll newq=q*other.q;
		ll newp=q*other.p+p*other.q;
		p=newp;
		q=newq;
		clean();
		return *this;
	}
	frac operator/(const int& d){
		frac ret;
		ret.p=p;
		ret.q=q*d;
		ret.clean();
		return ret;
	}
	bool operator<(const frac& other)const{
		ll newq=q*other.q;
		ll p1=p*other.q;
		ll p2=other.p*q;
		return p1<p2;
	}
}w[maxn];

int deg[maxn];
vector<int> G[maxn];
vector<int> need_to_print;
vector<frac> ans;
int n,m;
queue<int> Q;

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=0;i<n;++i){
		int d=read();
		if(!d)need_to_print.push_back(i);
		for(int j=0;j<d;++j){
			int x=read()-1;
			deg[x]++;
			G[i].push_back(x);
		}
	}
	for(int i=0;i<m;++i)w[i]=1,Q.push(i);
	while(Q.size()){
		int now=Q.front();
		Q.pop();
		frac dd=w[now]/G[now].size();
		for(int i=0;i<G[now].size();++i){
			int v=G[now][i];
			deg[v]--;
			w[v]+=dd;
			if(!deg[v])Q.push(v);
		}
	}	
	for(int i=0;i<need_to_print.size();++i){
		printf("%lld %lld\n",w[need_to_print[i]].p,w[need_to_print[i]].q);
	}
	return 0;
}

