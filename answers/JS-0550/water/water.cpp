#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=5e5+10,M=10;
ll n,m;
ll ver[N],nxt[N<<1],hd[N<<1],tot=0,fro[N<<1];
ll indgr[N];
queue<ll> Q;
ll lne[N],cnt=0;
ll d[N];
ll p[N],q[N];// p/q;

void Addedge(ll x,ll y){
	fro[++tot]=x;ver[tot]=y;nxt[tot]=hd[x];hd[x]=tot;
}
ll Gcd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0)return a;
	return Gcd(b,a%b);
}

void Topo(){
	for(ll i=1;i<=n;i++){
		
		q[i]=1;p[i]=0;
	}
	for(ll i=1;i<=tot;i++){
		ll v=fro[i];
		if(indgr[v]==0){
			Q.push(i);
			q[v]=1;p[v]=1;
		}
	}
		
	while(Q.size()){
		ll x=Q.front();Q.pop();
		lne[++cnt]=x;
		ll y=ver[x];
		indgr[y]=indgr[y]-1;
		if(indgr[y]==0)
			for(int i=hd[y];i;i=nxt[i]){
				Q.push(i);
			}
	}
}

void Add(ll x,ll y){
	ll qx=d[x]*q[x];
	//ll gd1=gcd(qx,q[y]);
	//ll mtp1=qx/gd,mtp2=q[y]/gd;
	p[y]=p[y]*d[x]*q[x]+p[x]*q[y];
	q[y]=q[y]*d[x]*q[x];
	
	ll gd=Gcd(p[y],q[y]);
	p[y]/=gd;q[y]/=gd;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&d[i]);
		for(ll j=1;j<=d[i];j++){
			ll v;
			scanf("%lld",&v);
			Addedge(i,v);
			indgr[v]=indgr[v]+1;
		}
	}
	
	Topo();
	for(ll i=1;i<=cnt;i++){
		ll tmp=lne[i];
		ll x=fro[tmp],y=ver[tmp];
		//cout<<x<<" "<<y<<endl;
		//cout<<p[x]<<" "<<q[x]<<" "<<p[y]<<" "<<q[y]<<endl;
		Add(x,y);
	}
	
	for(ll i=1;i<=n;i++){
		if(d[i]==0)
			printf("%lld %lld\n",p[i],q[i]);
	}

	return 0;
}

