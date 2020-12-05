#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=100005;
struct edge{
	int to,nxt;
}e[N<<1];
int head[N],ecnt;
void add(int u,int v){
	e[++ecnt].to=v;
	e[ecnt].nxt=head[u];
	head[u]=ecnt;
}
int out[N],in[N],que[N],n,m;
pll sum[N];

ll getgcd(ll a,ll b){
	if(a%b) return getgcd(b,a%b);
	return b;
}

pll pluss(pll a,pll b,int c){
	ll b1=b.first,b2=b.second*c;
	ll a1=a.first,a2=a.second;
	ll u=a1*b2+a2*b1,v=a2*b2;
	if(v>inf){
		ll k=getgcd(u,v);
		u=u/k,v=v/k;
	}
	return make_pair(u,v);
}
void topo(){
	int l=0,r=0;
	for(int i=1;i<=n;i++){
		sum[i]=make_pair(0,1);
		if(in[i]==0){
			que[r++]=i;
			sum[i]=make_pair(1,1);
		}
	}
	while(l<r){
		int u=que[l++];
		//cout<<u<<" "<<sum[u].first<<" "<<sum[u].second<<endl;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			sum[v]=pluss(sum[v],sum[u],out[u]);
			in[v]--;
			if(in[v]==0) que[r++]=v;
		}
	}
	//cout<<1<<endl;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int j,u;
	for(int i=1;i<=n;i++){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&u);
			add(i,u);in[u]++;out[i]++;
		}
	}
	topo();
	for(int i=1;i<=n;i++){
		if(out[i]==0){
			ll a=sum[i].first,b=sum[i].second;
			
			ll g=getgcd(a,b);
			//cout<<a<<" "<<b<<" "<<g<<endl;
			printf("%lld %lld\n",a/g,b/g);
		}
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
