#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define int long long unsigned
#define rint long long unsigned
#define maxn (500000+50)
inline int cmzgcd(int m, int n){
	while (n != 0){
		int t = m % n;
		m = n;
		n = t;
	}
	return m;
}
int n,m,d[maxn],toa,a[maxn],b[maxn],hea[maxn],nex[maxn],to[maxn],k;

inline void adde(int u,int v){
	nex[++k]=hea[u]; hea[u]=k; to[k]=v;
}
inline void abadd(int &a,int &b,const int c){
	a=a*c+b; b*=c;
	const int gc=cmzgcd(a,b);
	a/=gc; b/=gc;
}
void dfs(int p,int fa,int c){
	abadd(a[p],b[p],c);
	for(rint i=hea[p];i;i=nex[i])
		if(to[i]!=fa)
			dfs(to[i],p,c*d[p]);
}

signed main(){
	freopen("water.in","r",stdin); freopen("water.out","w",stdout);
	scanf("%llu%llu",&n,&m);
	for(rint i=1;i<=n;++i){
		a[i]=b[i]=1;
		scanf("%llu",&d[i]);
		for(rint j=1;j<=d[i];++j){
			scanf("%llu",&toa);
			adde(i,toa);
		}
	}
	for(rint i=1;i<=m;++i)
		dfs(i,0,1);
	for(rint i=1;i<=n;++i)
		if(!d[i]) printf("%llu %llu\n",a[i]-b[i],b[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
