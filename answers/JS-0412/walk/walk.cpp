#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N=500005;
const ll mod=1e9+7;
int n,k;
int w[15];
int c[N],d[N];
int dmax[15],dmin[15],dsum[15];
int p[15],q[15];
ll cnt[N],dead[N];
ll ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++) scanf("%d%d",c+i,d+i);
	for(int i=1;i<=n;i++){
		dsum[c[i]]+=d[i];
		dmax[c[i]]=max(dmax[c[i]],dsum[c[i]]);
		dmin[c[i]]=min(dmin[c[i]],dsum[c[i]]);
	}
	for(int i=1;i<=k+1;i++){
		if(i==k+1){
			printf("-1\n");
			return 0;
		}		
		if(dsum[i]!=0 || w[i]<=dmax[i]-dmin[i]) break;
	}
	for(int i=1;i<=k;i++) q[i]=1;
	if(n<=100){
		while(q[0]<1){
			for(int i=1;i<=n;i++) p[i]=q[i];
			int sum=0;
			while(1){
				bool f=false;
				for(int i=1;i<=n;i++){
					p[c[i]]+=d[i];ans++;sum++;
					if(p[c[i]]<=0||p[c[i]]>w[c[i]]){
						f=true;break;
					}
				}
				if(f) break;
			}
			
			q[k]++;
			for(int i=k;i>=1;i--){
				if(q[i]>w[i]) q[i]=1,q[i-1]++;
			}	
			//cout<<sum<<" "<<endl;		
		}
		printf("%lld\n",ans%mod);
	}
	else if(k==1){
		ans=0;
		//cout<<dmin[1]<<" "<<dmax[1]<<" "<<dsum[1]<<endl;
		memset(dead,inf,sizeof(dead));
		int z=0;
		for(int i=1;i<=n;i++){
			z+=d[i];
			if(z>0) cnt[i]=w[1]+1-z,dead[w[1]+1-z]=min(dead[w[1]+1-z],i*1ll);
			else cnt[i]=-z,dead[-z]=min(dead[-z],i*1ll);
		}
		dead[w[1]+1]=0;
		if(dsum[1]>0){
			for(int i=w[1]-dmax[1];i>=-dmin[1]+1;i--){
				int len=(w[1]-dmax[1]+1)-i;
				int s=(len/dsum[1])*n;
				int p=dead[i+(len/dsum[1])*dsum[1]+dsum[1]];
				//cout<<i<<" "<<s<<" "<<i+(len/dsum[1])*dsum[1]+dsum[1]<<endl;
				dead[i]=n+dead[i+dsum[1]];
			}
		}
		else{
			for(int i=-dmin[1]+1;i<=w[1]-dmax[1];i++){
				int len=i-dmin[1];
				//dsum[1]=-dsum[1];
				int s=(len/dsum[1])*n;
				int p=n+dead[i-(len/dsum[1])*dsum[1]-dsum[1]];
				dead[i]=n+dead[i+dsum[1]];
			}
		}
		//cout<<endl;
		//for(int i=1;i<=w[1];i++)	cout<<dead[i]<<endl;
		//cout<<endl<<endl;;
		//cout<<ans<<endl;
		for(int i=1;i<=w[1];i++)
			ans=(ans+dead[i])%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

4 1 10
1 -1
1 -1
1 1
1 -1
*/
