#include<bits/stdc++.h>
using namespace std;
#define mo 1000000007
#define rint register int

long long unsigned ans;
int n,k,w[15],c[500050],d[500050],pos[15];

void df1(int dep){
	if(dep==k){
		int po2[15];
		memcpy(po2,pos,(k+1)<<3);
		for(rint i=1;1;i=(i%n)+1){
			ans=(ans+1)%mo;
			po2[c[i]]+=d[i];
			if(po2[c[i]]<1||po2[c[i]]>w[c[i]]) return;
		}
	}
	else
		for(rint i=1;i<=w[dep+1];++i){
			pos[dep+1]=i;
			df1(dep+1);
		}
}

signed main(){
	freopen("walk.in","r",stdin); freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(rint i=1;i<=k;++i)
		scanf("%d",&w[i]);
	for(rint i=1;i<=n;++i)
		scanf("%d%d",&c[i],&d[i]);
	df1(0);
	printf("%llu\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
