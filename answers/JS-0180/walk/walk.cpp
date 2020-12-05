#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ll long long
int n,k;
int w[20],d[N],c[N];
int D[20],l[15],L[15];
const ll P=1e9+7;
ll ans;
void dfs(int now){
	if(now==k+1){
		for(int i=1;i<=k;i++)L[i]=l[i];
		
		int stp=0;
//		while(1){
//			for(int i=1;i<=k;i++){
//				L[i]+=D[i];
//			}
//			stp+=n;
//			int flg=1;
//			for(int i=1;i<=k;i++){
//				if(L[i]>w[i]||L[i]<=0){
//				flg=0;
//				break;
//				}
//			}if(flg==0)break;
//		}
//		stp-=n;
//		for(int i=1;i<=k;i++)L[i]-=D[i];
		while(1){
			L[c[stp%n]]+=d[stp%n];
			stp++;
			int flg=1;
			for(int i=1;i<=k;i++){
				if(L[i]>w[i]||L[i]<=0){
				flg=0;
				break;
				}
			}
			if(flg==0)break;
		}
		(ans+=stp)%=P;
	}
	
	for(int i=1;i<=w[now];i++){
		l[now]=i;
		dfs(now+1);
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
	for(int i=0;i<n;i++){
		scanf("%d%d",&c[i],&d[i]);
		D[c[i]]+=d[i];
	}
	int flg=1;
	for(int i=1;i<=k;i++)if(D[i]!=0){
		flg=0;
		break;
	}
	if(flg){
		cout<<-1<<endl;
		return 0;
	}
	if(k==1){
		if(D[1]<0)D[1]=-D[1];
		for(int i=1;i<=w[1];i++){
			ans=(ans+(w[1]-i)/D[i]+1)%P;
		}
	}
	else 
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
