// wish to get a better mark

#include<bits/stdc++.h>
#define re register int
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

using namespace std;

inline int rd(){
	int fl=1,x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}

inline void wr(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10),putchar('0'+(x%10));
	else putchar(x+'0');
}

// ---------- IO ---------- //

const int N=1e5+5;
int n,m,hd[N],a[N],cnt,vst[N],sum[N],deg[N];
ll p[N],q[N];

inline ll gcd(ll x,ll y){
	if(y==0ll) return x;
	return gcd(y,x%y);
}

struct edge{int t,nxt;}e[N<<3];

inline void add(int x,int y){e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;}

vector<int> topo;

inline bool dfs(int x){
	vst[x]=-1;
	for(re i=hd[x];i;i=e[i].nxt){
		if(vst[e[i].t]==-1) return 0;
		if(vst[e[i].t]==0){if(!dfs(e[i].t)) return 0;}
	}
	vst[x]=1;topo.pb(x);
	return 1;
}

// ---------- Graph ---------- //

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=rd();m=rd();
	for(re i=1;i<=n;i++){
		sum[i]=rd();int x;q[i]=1;
		for(re j=0;j<sum[i];j++) x=rd(),add(i,x),deg[x]++;
	}
	for(re i=1;i<=n;i++) if(!deg[i]) p[i]=1;
	for(re i=1;i<=n;i++) if(!vst[i]) dfs(i);
	for(re i=n-1;i>=0;i--){
		for(re j=hd[topo[i]];j;j=e[j].nxt){
			ll awa=gcd(q[topo[i]],q[e[j].t]);
			p[e[j].t]=q[topo[i]]/awa*sum[topo[i]]*p[e[j].t]+q[e[j].t]/awa*p[topo[i]];
			q[e[j].t]*=sum[topo[i]]*q[topo[i]]/awa;
			ll x=gcd(p[e[j].t],q[e[j].t]);
			p[e[j].t]/=x;q[e[j].t]/=x;
		}
	}
	for(re i=1;i<=n;i++) if(!sum[i]) wr(p[i]),putchar(' '),wr(q[i]),puts("");
	return 0;
}

// ---------- Main ---------- //

