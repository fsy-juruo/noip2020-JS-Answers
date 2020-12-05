#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<vector>
#include<queue>
#include<cctype>
#define ll long long
using namespace std;
const int N=2e6;
ll n,m,d[N],cia[N],nxt[N],ver[N],head[N],tot,deg[N];
inline void add(ll x,ll y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
ll gcd(ll a,ll b){
	return b==0 ? a : gcd(b,a%b);
}
struct fra{
	ll son,mot;
	fra(){
		son=0;
		mot=1;
	}
	void yue(){
		if(son==0)
			return;
		ll tmp=gcd(son,mot);
		son/=tmp;
		mot/=tmp;
	}
	void add(fra ads){
		ll tmp=mot*ads.mot/gcd(mot,ads.mot);//LCM
		ll t1=tmp/mot,t2=tmp/ads.mot;
		mot=tmp;
		son=son*t1+ads.son*t2;
		yue();
	}
}lsq[N];
inline fra make_frac(ll x,ll y){
	fra tmp;
	tmp.son=x;
	tmp.mot=y;
	return tmp;
}
queue<ll>q;
vector<ll>outp;
inline void tuopu(){
	while(!q.empty()){
		ll x=q.front();
		q.pop();
		fra t1=lsq[x];
		t1.mot*=d[x];
		for(ll i=head[x];i;i=nxt[i]){
			ll y=ver[i];
			lsq[y].add(t1);
			deg[y]--;
			if(!deg[y])
				q.push(y);
		}
	}
}
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
			f=-1;
		ch=getchar();	
	}
	while(isdigit(ch)){
		ret=10*ret+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	//scanf("%lld%lld",&n,&m);
	n=read();
	m=read();
	for(ll i=1;i<=n;i++){
		//scanf("%lld",&d[i]);
		d[i]=read();
		if(!d[i])
			outp.push_back(i);
		for(ll j=1;j<=d[i];j++){
			//scanf("%lld",&cia[j]);
			cia[j]=read();
			deg[cia[j]]++;
			add(i,cia[j]);
		}
	}
	for(ll i=1;i<=m;i++)
		lsq[i].son=1;
	for(ll i=1;i<=n;i++){
		if(!deg[i])
			q.push(i);
	}
	tuopu();
	for(ll i=0;i<outp.size();i++)
		printf("%lld %lld\n",lsq[outp[i]].son,lsq[outp[i]].mot);
	return 0;
}
