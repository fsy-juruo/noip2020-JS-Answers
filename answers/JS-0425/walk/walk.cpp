#include<bits/stdc++.h>
using namespace std;
#define maxn 500003
#define inf 2147483647
#define mod 1000000007
int n,k,w[13],c[maxn],d[maxn],far[13],near[13],F,N,W,tmp,eff,step[2*maxn],res[maxn];
struct Multiple_Axis_Structure{
	int square[13];
}now,route;
int solve(int x,int Eff){
	if(x+N<1 ||x+F>W){
		tmp=x;
		for(int i=1;i<=n;i++){
			tmp+=d[i];
			if(tmp<1 || tmp>W) return step[x]=i;
		}
	}
	if(step[x+Eff]!=0) return step[x]=(n+step[x+Eff])%mod;return -inf;
}
int Solve(int k,int NOW_HANDLE){
	if(res[NOW_HANDLE]!=0) return res[NOW_HANDLE];
	int standard[k+1],NOW=NOW_HANDLE;
	for(int i=k;i>=1;i--){
		standard[i]=NOW_HANDLE%10;
		if(standard[i]==0) standard[i]=10;
		NOW_HANDLE/=10;
	}
	for(int i=1;i<=k;i++)
		if(standard[i]<1 || standard[i]>w[i]) return res[NOW]=0;
	bool OUT=false;
	for(int i=1;i<=k;i++)
		if(standard[i]+far[i]>w[i] || standard[i]+near[i]<1) OUT=true;
	if(OUT==false){
		int retur=0;
		for(int i=1;i<=k;i++){
			standard[i]+=route.square[i];
			if(standard[i]==10) standard[i]=0;
			retur=retur*10+standard[i];
		}
		return res[NOW]=(solve(k,retur)+n)%mod;
	}
	for(int i=1;i<=n;i++){
		standard[c[i]]+=d[i];
		if(standard[c[i]]<1 || standard[c[i]]>w[i]) return res[NOW]=i;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		F=-inf,N=inf;
		cin>>W;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&c[i],&d[i]);
			tmp+=d[i];
			F=max(F,tmp);
			N=min(N,tmp);
		}
		eff=tmp;
		int ans=0;
		if(eff<0) for(int i=1;i<=W;i++) ans=(ans+solve(i,eff))%mod;
		else if(eff>0) for(int i=W;i>=1;i--){ans=(ans+solve(i,eff))%mod;
//		cout<<ans<<endl;
		}
		else for(int i=1;i<=W;i++){
			int solution=solve(i,0);
			if(solution<0){
				puts("-1");
				return 0;
			}
			ans=(ans+solution)%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++) far[i]=-inf,near[i]=inf;
	for(int i=1;i<=k;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		now.square[c[i]]+=d[i];
		far[c[i]]=max(far[c[i]],now.square[c[i]]);
		near[c[i]]=min(near[c[i]],now.square[c[i]]);
	}
	route=now;
//	puts("");
//	cout<<Solve(2,31)<<endl;
	int base=1,ans=0;
	for(int i=1;i<=k;i++) base*=10;
	for(int i=1;i<=base;i++){
//		int solution=Solve(k,i);
//		cout<<k<<' '<<i<<' '<<solution<<endl;
		ans=(ans+Solve(k,i))%mod;
	}
	cout<<ans<<endl;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

3 2
3 3
1 1 
2 -1
1 1


*/
