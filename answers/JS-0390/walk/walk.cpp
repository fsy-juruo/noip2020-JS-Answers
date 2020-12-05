#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int read(){
	char c=getchar();
	int s=0,f=1;
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s*f;
}

int readu(){
	char c=getchar();
	int s=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	return s;
}

ll readll(){
	char c=getchar();
	ll s=0ll,f=1ll;
	while (c<'0' || c>'9'){if (c=='-') f=-1ll;c=getchar();}
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s*f;
}

ll readull(){
	char c=getchar();
	ll s=0ll;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9'){s=s*10ll+c-'0';c=getchar();}
	return s;
}

const int MAXINT=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;
const int MAXK=10;
const int MAXN=500005;
const int MOD=1e9+7;

int n,k;
int w[MAXK],pos[MAXK],mini[MAXK],maxi[MAXK],start[MAXK];
int c[MAXN],d[MAXN];
int ans=0;

void solve1(int now){
	if (now>k){
		for (register int i=1;i<=k;++i){
			pos[i]=start[i];
		}
		int step,num;
		step=num=1;
		while(1){
			pos[c[num]]+=d[num];
			if (pos[c[num]]<1 || pos[c[num]]>w[c[num]]) break;
			step=(step+1)%MOD;
			num=num%n+1;
		}
		ans=(ans+step)%MOD;
		return;
	}
	for (register int i=1;i<=w[now];++i){
		start[now]=i;
		solve1(now+1);
	}
	return;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=readu();
	k=readu();
	for (register int i=1;i<=k;++i){
		w[i]=readu();
	}
	for (register int i=1;i<=n;++i){
		c[i]=readu();
		d[i]=read();
//		printf("(%d,%d)",c[i],d[i]);
		pos[c[i]]+=d[i];
		mini[c[i]]=min(mini[c[i]],pos[c[i]]);
		maxi[c[i]]=max(maxi[c[i]],pos[c[i]]);
	}
	/*
	for (register int i=1;i<=k;++i){
		printf("[%d,%d]",maxi[i],mini[i]);
	}
	*/
	bool fff=0;
	for (register int i=1;i<=k;++i){
//		printf("%d ",pos[i]);
		if (pos[i]!=0){
			fff=1;
//			printf("..");
			break;
		}
		if (maxi[i]-mini[i]>=w[i]){
			fff=1;
//			printf("...");
			break;
		}
	}
//	printf("{%d}",fff);
	if (fff==0){
		printf("-1");
		return 0;
	}
//	if (n<=100){
		solve1(1);
		printf("%d",ans);
//		return 0;
//	}
	return 0;
}

