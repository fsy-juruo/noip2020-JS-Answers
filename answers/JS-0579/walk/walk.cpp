#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
int n,k;
int w[15],c[500005]={0},d[500005]={0};
int cnt=0;
const int mod=1e9+7;
int ans=0;
int p[10];
int pn[10];
int f[500005]={0};
int mint[2000005]={0};
int rmax=0,lmax=0;
const int ad=1000000;
bool in()
{
	for(int i=1;i<=k;++i){
		if(pn[i]<1||pn[i]>w[i]){
			return false;
		}
	}
	return true;
}
int work()
{
	for(int i=1;i<=k;++i){
		pn[i]=p[i];
	}
	int num=0;
	while(in()){
		num++;
		pn[c[(num-1)%n+1]]+=d[(num-1)%n+1];
		if(num>=1000000){
			std::cout<<"-1"<<std::endl;
			cnt=1;
			return 0;
		}
	}
	return num;
}
void dfs(int x)
{
	if(x==k+1){
		ans+=work();
		if(cnt==1) return;
	}
	for(int i=1;i<=w[x];++i){
		p[x]=i;
		dfs(x+1);
	}
	p[x]=0;
	return;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&c[i],&d[i]);
	}
	if(n<=1000){
		dfs(1);
		if(cnt==1) return 0;
		else std::cout<<ans<<std::endl;
		return 0;
	}
	else if(k==1){
		memset(mint,0x3f,sizeof(mint));
		mint[ad]=0;
		for(int i=1;i<=n;++i){
			f[i]=f[i-1]+d[i];
			if(f[i]>rmax) rmax=f[i];
			if(f[i]<lmax) lmax=f[i];
			if(i<mint[f[i]+ad]) mint[f[i]+ad]=i;
		}
		for(int i=1;i<=w[1];++i){
			if(1-i>lmax) ans=(ans+mint[-i+ad])%mod;
			if(w[1]-i<rmax) ans=(ans+mint[w[1]-i+1+ad])%mod;
			else{
				if(f[n]>0){
					ans=(ans+int((w[1]-i-rmax)/f[n])+1+mint[w[1]-(w[1]-i-rmax)%f[n]+1+ad])%mod;
				}
				else if(f[n]<0){
					ans=(ans+int((lmax-1+i)/f[n])+1+mint[-(lmax-1+i)%f[n]+1+ad])%mod;
				}
				else{
					std::cout<<"-1"<<std::endl;
					return 0;
				}
			}
		}
	}
	else{
		std::cout<<"-1"<<std::endl;
	}
	
}
