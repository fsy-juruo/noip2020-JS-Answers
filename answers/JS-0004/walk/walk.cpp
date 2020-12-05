#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
const int N=5e5+1;

inline int read() { char ch=getchar(); int f=1; while(!isdigit(ch)) {if(ch=='-') f=-f; ch=getchar();}
	int x=0; while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-'0',ch=getchar(); return x*f;}

struct node {
	int x,y;
} step[N];
int n,k,w[N],kw[N],nkw[N],nnkw[N];
ll ans=0;

inline bool outside() {
	for(int i=1;i<=k;i++)
		if(nkw[i]<=0 || nkw[i]>w[i]) return 1;
	return 0;	
}

inline void check() {
	int q=0;
//	for(int i=1;i<=k;i++) printf("%d ",kw[i]); puts("");
	memset(nkw,0,sizeof(nkw));
	memset(nnkw,0,sizeof(nnkw));
	for(int i=1;i<=k;i++) nkw[i]=kw[i];
	while(1) {
		for(int i=1;i<=k;i++) nnkw[i]=nkw[i];
		if(outside()) {
			ans=(ans+q)%MOD;
			return;
		}
		for(int i=1;i<=n;i++) {
			nkw[step[i].x]+=step[i].y; q++;
			if(outside()) {
				ans=(ans+q)%MOD;
//				printf("%lld\n",ans);
				return;
			} bool f=0;
			for(int j=1;j<=k;j++) f|=(nkw[j]!=nnkw[j]);
			if(!f) {puts("-1"); exit(0);}
		}
	}
}

inline void gt(int x) {
	if(x>k) {
		check();
		return;
	} for(int i=1;i<=w[x];i++) {
		kw[x]=i; gt(x+1);
	}
}

inline void subtask1() {
	gt(1); printf("%lld\n",ans);
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++) step[i].x=read(),step[i].y=read();
	if(n<=5) subtask1();
	return 0;
}

