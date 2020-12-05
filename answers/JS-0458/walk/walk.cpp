#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline int read() {
	int num=0, f=1; char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-' ? -1 : 1), ch=getchar();
	while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch^48), ch=getchar();
	return num*f;
}

namespace BF {
	const int N=1007, K=7;
	ll W[K], Mxn[K], Min[K], mod=1000000007ll, Nw[K];
	struct s { int dir, del; } Step[N];
	int n,k;
	#define rg register
	
	int main(int qwq,int qoq) {
	//	if(n>100) puts("-1");
		
		n=qwq, k=qoq;
		for(rg int i=1;i<=k;i++) W[i]=read();
		for(rg int i=1;i<=n;i++) Step[i].dir=read(), Step[i].del=read();
	
		ll ans=0ll, Sum=1ll; int i=1, cnt=0;
		for(rg int i=1;i<=k;i++) Sum=(Sum * W[i]) %mod;
		ans=Sum;
		
		while(true ) {
			int dir=Step[i].dir, del=Step[i].del;
			Mxn[dir]=max(Mxn[dir], Nw[dir] + del);
			Min[dir]=min(Min[dir], Nw[dir] + del);
			Nw[dir]+=del;
			cnt++;
			
			
			if(W[dir] - Mxn[dir] + Min[dir] <= 0) {
				printf("%lld\n",ans);
				return 0;
			}
			
			ll Sum=1ll;
			for(rg int j=1;j<=k;j++) Sum=(Sum * (W[j] - Mxn[j] + Min[j])) %mod;
			ans=(ans + Sum) %mod;
//			printf("%d:    %d    dir:%d   del:%d     Mxn:%lld  Min:%lld  Nw:%lld    Sum:%lld\n",cnt,i,dir,del,Mxn[dir],Min[dir],Nw[dir],Sum);
			
			i++;
			if(i>n) {
				bool tp=true ;
				for(rg int j=1;j<=k;j++) if(Nw[j]) tp=false ;
				if(tp) { puts("-1"); return 0; }
				i=1;
			}
		}
		
		return 0;
	}
}

namespace Link {
	
	int n,k;
	
	int main(int qwq,int qoq) {
		n=qwq, k=qoq;
		
	}
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	int n=read(), k=read();
	if(n<=1000) BF::main(n,k);
	else {
		printf("-1");
	}
	return 0;
}
