#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f,MAXN=5e5+10,MAXK=12,MAXH=1e7;
const LL MOD=1e9+7;
int N,K,pc[MAXN],pd[MAXN],w[MAXK];
int maxv[MAXK],minv[MAXK],ef[MAXK];
int hs(int a[]) {
	int ret=0;
	for(int i=K; i>0; i--) {
		ret=ret*w[i]+a[i]-1;
	}
	return ret;
}
inline void dh(int a[],int h) {
	for(int i=1; i<=K; i++) {
		a[i]=h%w[i]+1;
		h/=w[i];
	}
}
LL f[MAXH];
inline LL dfs(int x) {
	if(f[x]) {
		return f[x];
	}
	int ret=0;
	int pos[MAXK];
	dh(pos,x);
	//over the limit
	int flag=0;
	for(int i=1; i<=K; i++) {
		if(pos[i]+maxv[i]>w[i]||pos[i]+minv[i]<1) {
			flag=1;
			break;
		}
	}
	if(flag) {
		for(int i=1; i<=N; i++) {
			pos[pc[i]]+=pd[i];
			if(pos[pc[i]]>w[pc[i]]||pos[pc[i]]<1) {
				//caution
				f[x]=i;
				return f[x];
			}
		}
//		puts("ERROR");
	}
	for(int i=1; i<=K; i++) {
		pos[i]+=ef[i];
	}
	int h=hs(pos);
	ret=(dfs(h)+N)%MOD;
	f[x]=ret;
	return f[x];
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&N,&K);
	int stanum=1;
	for(int i=1; i<=K; i++) {
		scanf("%d",w+i);
		stanum*=w[i];
	}
	int tmp[MAXK]= {0};
	for(int i=1; i<=N; i++) {
		scanf("%d%d",pc+i,pd+i);
		tmp[pc[i]]+=pd[i];
		maxv[pc[i]]=max(maxv[pc[i]],tmp[pc[i]]);
		minv[pc[i]]=min(minv[pc[i]],tmp[pc[i]]);
	}
	int flag=0;
	for(int i=1; i<=K; i++) {
		ef[i]=tmp[i];
		if(ef[i]||maxv[i]-minv[i]+1>w[i]) {
			flag=1;
		}
	}
	if(!flag) {
		puts("-1");
		return 0;
	}
	LL ans=0;
	for(int i=0; i<stanum; i++) {
		dh(tmp,i);
		int flow=dfs(i);
		ans=(ans+flow)%MOD;
	}
	printf("%lld",ans);
	return 0;
}
