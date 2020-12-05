#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f3f3f3f3f;
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(ne)x=-x;
}
void prt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)prt(x/10);
	putchar(x%10^48);
}
const int mod=1000000007;
const int N=1000000,M=20;
int n,m;
int a[M+1];
int c[N+1],d[N+1];
int v[M+1][N+1];
int stp[N+1];
int fst[2*N+1];
int *lwb(int k,int val){
	int ans=a[k]+1;
	int *vk=v[k];
	for(register int i=20;~i;--i)if(ans>1<<i&&vk[ans-(1<<i)]>=val)ans-=1<<i;
	return vk+ans;
}
signed main(){
	freopen("walk.in","r",stdin);freopen("walk.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(c[i]),read(d[i]);
	for(int i=1;i<=m;i++){//remember to make it first
		for(int j=1;j<=n;j++)
			if(c[j]==i)stp[j]=stp[j-1]+d[j];
			else stp[j]=stp[j-1];
		memset(fst,0x3f,sizeof(fst));
		fst[n]=0;
		for(int j=1;j<=n;j++)fst[stp[j]+n]=min(fst[stp[j]+n],j);
		for(int j=stp[n]<0?1:a[i];stp[n]<0?(j<=a[i]):(j>=1);j+=stp[n]<0?1:-1){
			v[i][j]=inf;
			if(-j>=-n)v[i][j]=fst[-j+n];
			if(a[i]+1-j<=n)v[i][j]=min(v[i][j],fst[a[i]+1-j+n]);
			if(1<=j+stp[n]&&j+stp[n]<=a[i]&&stp[n])v[i][j]=min(v[i][j],v[i][j+stp[n]]+n);
		}
//		for(int j=1;j<=a[i];j++)cout<<v[i][j]<<" ";puts("!");
		random_shuffle(v[i]+1,v[i]+a[i]+1);
		sort(v[i]+1,v[i]+a[i]+1);
	}
	int ans=0;
	for(int i=1;i<=m;i++)for(int j=1;j<=a[i];j++){
		int cnt=1;
		for(int k=1;k<=m;k++){
			if(k<i){
				int *fd=lwb(k,v[i][j]);
				cnt=cnt*(v[k]+a[k]+1-fd)%mod;
			}
			else if(k>i){
				int *fd=lwb(k,v[i][j]+1);
				cnt=cnt*(v[k]+a[k]+1-fd)%mod;
			}
		}
		if(v[i][j]==inf&&cnt)return puts("-1"),0;
		ans=(ans+v[i][j]%mod*cnt)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
