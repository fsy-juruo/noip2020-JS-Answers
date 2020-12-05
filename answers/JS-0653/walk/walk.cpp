#include <bits/stdc++.h>
using namespace std;

#define inf 2147483647

typedef long long ll;
typedef unsigned long long ull;

const ll mod=1e9+7;

inline int read() {
	int ret=0;
	char ch=getchar(),last=' ';
	while(!isdigit(ch)) {ch=getchar();last=ch;}
	while(isdigit(ch)) {ret=ret*10+ch-'0';ch=getchar();}
	if(last=='-') ret=-ret;
	return ret;
}

int n,k,day[200],t[200],node[200];
ll w[200];
struct go{
	int c,d;
}a[500005];

int maxx[20],minx[20],asum[20];
ll calc() {
	int i;
	
	int minn=inf;
	for(i=1;i<=k;i++) {
		if(day[i]==0 || minx[i]==inf || maxx[i]==-inf) {
			t[i]=inf;
			continue;
		}
		if(day[i]<0) {
			int d=node[i]-1+(minx[i]);
			if(d<0) t[i]=0;
			else {
				t[i]=-d/day[i]+1;
			}
			if(node[i]+maxx[i]>w[i]) t[i]=0;
		}
		if(day[i]>0) {
			int d=w[i]-node[i]-(maxx[i]);
			if(d<0) t[i]=0;
			else {
				t[i]=d/day[i]+1;
			}
			if(node[i]+minx[i]<1) t[i]=0;
		}
		if(minn>t[i]) {
			minn=t[i];
		}
	}
	
	for(i=1;i<=k;i++) {
		node[i]+=minn*day[i];
	}
	for(i=1;i<=n;i++) {
		node[a[i].c]+=a[i].d;
		if(node[a[i].c]<1 || node[a[i].c]>w[a[i].c]) break;
	}
	return (1LL*minn*n%mod+i)%mod;
}

ll ans;
void dfs(int step) {
	if(step==k+1) {
		int c[200];
		for(int i=1;i<=k;i++) {
			c[i]=node[i];
		}
		int add=calc();
		ans=(ans+add)%mod;
		
		
		for(int i=1;i<=k;i++) {
			node[i]=c[i];
		}
		
		return;
	}
	for(int i=1;i<=w[step];i++) {
		node[step]=i;
		dfs(step+1);
	}
	return;
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=k;i++) {
		w[i]=1LL*read();
	}
	for(int i=1;i<=n;i++) {
		a[i].c=read();
		scanf("%d",&a[i].d);
		day[a[i].c]+=a[i].d;
	}
	
	for(int i=1;i<20;i++) {
		minx[i]=inf;
		maxx[i]=-inf;
	}
	for(int i=1;i<=n;i++) {
		asum[a[i].c]+=a[i].d;
		minx[a[i].c]=min(minx[a[i].c],asum[a[i].c]);
		maxx[a[i].c]=max(maxx[a[i].c],asum[a[i].c]);
		//if(node[a[i].c]<1 || node[a[i].c]>w[a[i].c]) flag=1,break;
	}
	
	if(n<=100000) {
		dfs(1);
		printf("%lld\n",ans%mod);
	} else {
		printf("-1\n");
	}
	return 0;
}

