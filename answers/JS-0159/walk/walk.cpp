#include<bits/stdc++.h>
using namespace std;
const int N=11,M=500010,INF=1000000007;
int n,k;
int x,y;
int w[N];
int check[N],ma[N],mi[N],xy[N],xyx[N];
int d[M];
long long ans=0;
int a;
bool f[M],flag;
bool judg(){
	for(int i=1;i<=n;i++){
		if(check[i]!=0) return false;
		if(ma[i]-mi[i]+1>w[i]) return false;
	}
	return true;
}
void work(int m){
	if(m==1){
		for(int i=1;i<=w[1];i++){
			xy[1]=i;
			for(int j=1;j<=k;j++) xyx[j]=xy[j];
			flag=false;
			while(flag==false){
				for(int j=1;j<=k;j++) 
					if(ma[j]+xyx[j]>w[j]||mi[j]+xyx[j]<1){
						flag=true;
						break;
					}
				if(flag) break;
				else{
					ans=(ans+n)%INF;
					for(int j=1;j<=k;j++) xyx[j]+=check[j];
				}
			}
			for(int j=1;j<=n;j++){
				ans=(ans+1)%INF;
				a=d[j];
				if(f[j]) xyx[a]+=1;
				else xyx[a]-=1;
				if(xyx[a]>w[a]||xyx[a]<=0) break;	
			}
		}
	}
	else{
		for(int i=1;i<=w[m];i++){
			xy[m]=i;
			work(m-1);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&d[i],&y);
		check[d[i]]+=y;
		ma[d[i]]=max(ma[d[i]],check[d[i]]),mi[d[i]]=min(mi[d[i]],check[d[i]]);
		if(y==1) f[i]=true;
	}
	if(judg()){
		printf("-1\n");
		return 0;
	}
	work(k);
	printf("%lld\n",ans);
	return 0;
}
