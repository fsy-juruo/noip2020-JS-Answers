#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define dec(i,a,b) for(register int i=a;i>=b;--i)
#define il inline
typedef long long ll;
using namespace std;

il void filejudge(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
}

namespace io{
	il int read(){
		int x=0;char ch=getchar();bool f=0;
		while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
		while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return f?-x:x;
	}
}
using io::read;
struct node{
	int dth,k;
} e[500100];
int w[12],n,wsum;
const int mod=1e9+7;
ll mx[12],mn[12],nxt[12];
il void init(){
	rep(i,1,n){
		int d=e[i].dth;
		nxt[d]+=e[i].k;
		mx[d]=max(mx[d],nxt[d]);
		mn[d]=min(mn[d],nxt[d]);
	}
}
il bool ok(){
	rep(i,1,wsum) if(mx[i]-mn[i]+1>w[i] || nxt[i]!=0) return 1;
	return 0;
}
		ll ans=0;
		
il void add(ll &x,ll y){
	x+=y;
	x%=mod;
}
namespace subtask1{
	ll point[11],now[11];
	il void check2(){
		rep(i,1,n){
			int d=e[i].dth;
			now[d]+=e[i].k;
			add(ans,1);
			if(now[d]<1 || now[d]>w[d]) return;
		}		
	}
	il void check(){
		rep(i,1,wsum) now[i]=point[i];
		while(true){
			rep(i,1,wsum){
				if(now[i]+mx[i]>w[i] || now[i]+mn[i]<1){
					check2();
					return;
				}
			}
			rep(i,1,wsum) now[i]=now[i]+nxt[i];
			add(ans,n);
		}
	}
	il void dfs(int k){
		if(k>wsum){
			check();
			return;
		}
		rep(i,1,w[k]){
			point[k]=i;
			dfs(k+1);
		}
	}
	il void main(){
		dfs(1);
		printf("%lld\n",ans);
	}
}

int main(){
	filejudge();
	n=read();wsum=read();
	rep(i,1,wsum) w[i]=read();
	rep(i,1,n) e[i].dth=read(),e[i].k=read();
	init();
	if(!ok()){ puts("-1");return 0;}
	subtask1::main();
	return 0;
}
