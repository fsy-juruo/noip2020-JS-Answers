#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rg register
#define inf 0x7f7f7f7f
#define ll long long
#define mod 1000000007
inline ll read(){
	rg ll ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
ll n,k,w[15],c[500005],d[500005];
ll a[15],sta[15],ans,ans1,b[15][500005],tot[15];
bool fla=1;
inline void init(int x){
	if(x==k){
		ll ret1=inf,ret2=inf,ret3=0,ret4=0;
		for(rg int i=1;i<=k;++i){
			/*ll tmp,now1,now2;
			if(a[i]==0) continue;
			if(a[i]>0){
				tmp=w[i]-sta[i]+1;
				now1=tmp/a[i];
				now2=b[i][tmp%a[i]];
			}else{
				tmp=sta[i];
				now1=tmp/(-a[i]);
				now2=b[i][tmp%(-a[i])];
			}
			//if(i==2&&tmp==2) system("pause"),printf("%lld\n",now1);
			if(b[i][tmp-(now1-2)*abs(a[i])]!=inf){
				now1-=2;
				now2=b[i][(tmp-now1*abs(a[i]))];
			}
			if(b[i][tmp-(now1-1)*abs(a[i])]!=inf){
				now1-=1;
				now2=b[i][(tmp-now1*abs(a[i]))];
			}
			if(now1<ret1){
				ret1=now1,ret2=now2;
			}else if(now1==ret1){
				ret2=min(ret2,now2);
			}*/
			ll hsy[15];
			for(rg int j=1;j<=k;++j) hsy[j]=sta[j];
			while(1){
				for(rg int j=1;j<=n;++j){
					hsy[c[j]]+=d[j];
					if(hsy[c[j]]>w[c[j]]||hsy[c[j]]<1){
						ret4=j; break;
					}
				}
				if(ret4) break;
				++ret3;
			}
		}
		//ans+=ret1*n+ret2; ans%=mod;
		//if(sta[2]==7) printf("%lld %lld ",b[2][2],b[3][1]);
		//printf("%lld %lld %lld %lld   %lld %lld %lld %lld\n",sta[1],sta[2],sta[3],sta[4],ret1,ret2,ret3,ret4);
		//if(ret1!=ret3||ret2!=ret4)
		//	printf("1\n");
		ans1+=ret3*n+ret4; ans1%=mod;
		return;
	}
	for(rg int i=1;i<=w[x+1];++i){
		sta[x+1]=i;
		init(x+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	memset(b,0x7f,sizeof(b));
	for(rg int i=1;i<=k;++i){
		w[i]=read();
	}
	for(rg int i=1;i<=n;++i){
		c[i]=read(); d[i]=read();
		a[c[i]]+=d[i];
		b[c[i]][abs(a[c[i]])]=min(i*1ll,b[c[i]][abs(a[c[i]])]);
	}
	for(rg int i=1;i<=k;++i){
		if(a[i]!=0) fla=0;
	}
	if(fla){
		printf("-1");
		return 0;
	}
	init(0);
	printf("%lld",ans1);
	return 0;
}
