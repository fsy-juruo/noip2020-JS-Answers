#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],d[15][2],t[15];
int x[15],xx[15],c[500005],y[500005];
long long mod=1000000007,ans;
bool Check(){
	for(int i=1;i<=k;i++) if(x[i]<1||x[i]>w[i]) return false;
	return true;
}
long long solve(){
	long long num=0;
	int i=1;
	while(Check()){			//for(int j=1;j<=k;j++) printf("%d ",x[j]);
							//printf("\n");
		x[c[i]]+=y[i];
		num=(num+1)%mod;
		i++;
		if(i>n) i-=n;
	}						//printf("\n %lld\n\n",num);
	
	return num;

}
void dfs(int p){
	if(p>k){
		for(int i=1;i<=k;i++) xx[i]=x[i];
		ans=(ans+solve())%mod;
		for(int i=1;i<=k;i++) x[i]=xx[i];
		return;
	}
	for(int i=1;i<=w[p];i++){
		x[p]=i;
		dfs(p+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&y[i]);
		t[c[i]]+=y[i];
		d[c[i]][0]=max(d[c[i]][0],t[c[i]]);
		d[c[i]][1]=min(d[c[i]][1],t[c[i]]);
	}
	bool flag=0;
	for(int i=1;i<=k;i++){
		if(t[i]){
			flag=1;
			break;
		}
	}
	if(!flag){
		bool ff=0;
		for(int i=1;i<=k;i++){
			if(1+d[i][0]-d[i][1]<w[i]){
				ff=1;
				break;
			}
		}
		if(!ff){
			printf("-1");
			return 0;
		}
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
