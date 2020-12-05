#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=500010,MAXK=11,MOD=1e9+7;
ll n,k,ans,tot;
ll w[MAXK];
//pair move[MAXN],to[MAXN];//first:w second:step;
struct node{
	ll a[MAXK];
	void in(int w,int step){
		a[w]=step;
		return ;
	}
	node pl(node b){
		node sum;
		for(ll i=1;i<=k;i++) sum.a[i]=a[i]+b.a[i];
		return sum;
	}
	bool imgu(){
		for(int i=1;i<=k;i++){
			if(a[i]>w[i]||a[i]<1) return false;
		}
		return true;
	}
	void pf(){
		printf("(");
		for(int i=1;i<=k;i++) printf(",%lld",a[i]);
	}
}move[MAXN],to[MAXN],ww[(1<<MAXK)],c;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(ll j=1;j<1<<k;j++){
			if(j&(1<<(i-1))) ww[j].a[i]=w[i]; 
		} 
	}
	for(ll j=1;j<1<<k;j++){
		ww[j].pf();
	} 
	for(ll i=1;i<=n;i++){
		ll w,step;
		scanf("%lld%lld",&w,&step);
		move[i].in(w,-step);
		to[i]=to[i-1].pl(move[i]);
	}
	printf("-1\n");
	return 0;
	for(ll i=1;i<=n;i++){
		for(int j=0;j<(1<<k);j++){
			c=to[i].pl(ww[j]);
			if(!c.imgu()) continue;
			int q=i;
			c.pf();
			printf(":%d\n",q);
			c=c.pl(to[n]);
			while(c.imgu()){
				c.pf();
				q+=n;
				printf(":%d\n",q);
				c=c.pl(to[n]);
				
			}
			ans=(ans+((q-1)*q/2%MOD))%MOD;
			tot=(((tot+q)%MOD)-1)%MOD;
		}
	}
	ll ctot=1;
	for(ll i=1;i<=k;i++) ctot=ctot*w[i]%MOD;
	//if(tot!=ctot) printf("-1");
	//else 
	printf("%d\n",ans);
	return 0;
}
