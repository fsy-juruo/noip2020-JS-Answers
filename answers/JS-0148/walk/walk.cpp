#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,k,w[13],c[500003],d[500003],h[13],hh[13],ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int p=1;
	for(int i=1;i<=k;++i){
		scanf("%d",&w[i]);
		h[i]=1,p*=w[i];
	}
	for(int i=1;i<=n;++i)
		scanf("%d%d",&c[i],&d[i]);
	h[k]=0;
	for(int i=1;i<=p;++i){
		h[k]++;
		int a=k,cnt=0;
		while(h[a]>w[a]){
			h[a]-=w[a];
			a--,h[a]++;
		}
		for(int j=1;j<=k;++j) hh[j]=h[j];
		a=1;
		while(1){
			hh[c[a]]+=d[a],cnt++;
			if(hh[c[a]]<1||hh[c[a]]>w[c[a]])
				break;
			if(++a>n) a=1;
		}
		ans=(ans+cnt)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}
