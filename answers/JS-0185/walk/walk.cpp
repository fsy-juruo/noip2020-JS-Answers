#include<bits/stdc++.h>
using namespace std;
bool pd=0;
long long ans=0;
long long M=1e9+7;
long long w[500500];
int a[500010][2];
long long css[20];
long long tem[20];
int n,k;
bool check(){
	for(int i=1;i<=k;++i){
		if(css[i]>w[i]||css[i]<1)return 0;
	}
	return 1;
}
void wor(){
	long long cnt=0;
	long long sum=0;
	int d=1;
	for(int i=1;i<=k;++i)tem[i]=css[i];
	while(1){
		if(!check())break;
		if(cnt>10000){
		pd=1;
		return;	
		}
		if(d>n){
		d=1;	
		cnt++;
		}
		css[a[d][0]]+=a[d][1];
		sum++;cnt++;
		sum%=M;
		d++;
	}
	for(int i=1;i<=k;++i)css[i]=tem[i];
	ans=(ans+sum)%M;
}
void wal(int wd){
	if(pd)return ;
	if(wd>k){
		wor();
		return ;
	}
	for(long long i=1;i<=w[wd];++i){
		css[wd]=i;
		wal(wd+1);
		css[wd]=0;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	wal(1);
	if(pd)puts("-1");
	else printf("%lld",ans);
	return 0;
}

