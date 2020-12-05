#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=gc();int neg=1;
	for(;!isdigit(c);c=gc())if(c=='-')neg=-1;
	for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+c-'0';
	x*=neg;
}
struct fenshu{
	ll a,b;
};
const int maxn=1e5+10;
ll n,m;
vector<ll> G[maxn];
ll in[maxn];
fenshu cnt[maxn];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll maxx(ll a,ll b){
	return a*b/gcd(a,b);
}
fenshu yue(fenshu x){
	int g=gcd(x.a,x.b);
	return (fenshu){x.a/g,x.b/g};
}
fenshu div(fenshu x,int d){
	return yue((fenshu){x.a,x.b*d});
}
fenshu add(fenshu x,fenshu y){
	return yue((fenshu){x.a*y.b+x.b*y.a,x.b*y.b});
}
void dfs(fenshu c,ll u,ll fa){
//	printf("%d %d/%d\n",u,c.a,c.b);
	if(G[u].size()==0){
		cnt[u]=add(cnt[u],c);
	}
	for(int i=0;i<(ll)G[u].size();i++){
		int v=G[u][i];
		if(v==fa)continue;
		dfs(div(c,G[u].size()),v,u);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	int num,input;
	for(int i=1;i<=n;i++){
		read(num);
		cnt[i]=(fenshu){0,1};
		for(int j=1;j<=num;j++){
			read(input);
			G[i].push_back(input);
			in[input]++;
		}
	}
	for(int i=1;i<=m;i++){
		dfs((fenshu){1,1},i,0);
	}
	for(int i=1;i<=n;i++){
		if(G[i].size()==0){
			printf("%llu %llu\n",cnt[i].a,cnt[i].b);
		}
	}
	return 0;
}

