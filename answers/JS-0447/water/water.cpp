#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int a[MAXN],ai[MAXN][15];
int sum[MAXN];
int F[MAXN],T[MAXN];
int dep[MAXN];
long long fz[MAXN],fm[MAXN];
void ser(int x,int deep){
	dep[x]=max(deep,dep[x]);
	for (int j=1;j<=a[x];++j)
		ser(ai[x][j],deep+1);
}
long long yf(long long x,long long y){
	if (x%y==0) return y;
	return yf(y,x%y);
}
int main (){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int f=0,t=0;
	for (int i=1;i<=n;++i) fz[i]=0,fm[i]=1;
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		if (!a[i]) F[++f]=i;
		for (int j=1;j<=a[i];++j)
			scanf("%d",&ai[i][j]),sum[ai[i][j]]++;
	}
	for (int i=1;i<=n;++i)
		if (!sum[i]) T[++t]=i,fz[i]=1;
	for (int i=1;i<=t;++i)
		ser(T[i],1);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=12;++j)
			if (dep[i]==j){
				long long FM1=fm[i];
				long long FZ1=fz[i];
				FM1*=a[i];
				for (int k=1;k<=a[i];++k){
					long long FM2=fm[ai[i][k]];
					long long FZ2=fz[ai[i][k]];
					fm[ai[i][k]]=FM2*FM1;
					fz[ai[i][k]]=FZ2*FM1+FM2*FZ1;
					if (fz[ai[i][k]]==0) fm[ai[i][k]]=1;
					else {
						int x=yf(fz[ai[i][k]],fm[ai[i][k]]);
						fm[ai[i][k]]/=x;
						fz[ai[i][k]]/=x;
					}
				}
			}
	for (int i=1;i<=f;++i)
		printf("%lld %lld\n",fz[F[i]],fm[F[i]]);
	return 0;
}

