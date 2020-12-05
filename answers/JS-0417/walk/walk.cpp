#include <bits/stdc++.h>
using namespace std;

const int N=500000,MOD=1000000007;
int n,k,w[20],t[20],rt[N+10][2],u,v;
int mw[20][2];//mw[d][r]=l表示第d维的（min:r=0;max:r=1）偏移值为l 

int main(){
	
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&(w[i]));
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&u,&v);
		rt[i][0]=u,rt[i][1]=v;
		t[u]+=v;
		mw[u][0]=min(mw[u][0],t[u]);
		mw[u][1]=max(mw[u][1],t[u]);
	}
	bool f=0;
	for(int i=1;i<=k;++i){
		if(t[i]){
			f=1;
			break;
		}
	}
	if(!f){
		printf("-1");
		return 0;
	}
	 
	return 0;
}
