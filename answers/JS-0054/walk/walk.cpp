#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define N 500005
#define F first
#define S second
#define random(x) (rand()%(x))
#define mod 1000000007
int n,k,w[13],c[N],d[N],xw[13],dw[13];
int main(){
	
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	ll t1=0,t2=0,t3;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i){
		scanf("%d",w+i);
		xw[i]=1;dw[i]=w[i];
	}
	for(int i=1;i<=n;++i){
		scanf("%d%d",c+i,d+i);
	}
	for(int i=1,im;;++i){
		im=(i-1)%n+1;
		xw[c[im]]+=d[im];
		if(xw[c[im]]==0){
			t3=i;
			for(int j=1;j<=k;++j){
				if(j==c[im]) continue;
				t3=t3*(dw[j]-xw[j]+1)%mod;
			}
			//printf("%d:%lld\n",i,t3);
			t2=(t2+t3)%mod;
			xw[c[im]]=1;
		}
		dw[c[im]]+=d[im];
		if(dw[c[im]]>w[c[im]]){
			t3=i;
			for(int j=1;j<=k;++j){
				if(j==c[im]) continue;
				t3=t3*(dw[j]-xw[j]+1)%mod;
			}
			//printf("%d:%lld\n",i,t3);
			t2=(t2+t3)%mod;
			dw[c[im]]=w[c[im]];
		}
		//for(int j=1;j<=k;++j) printf("(%d,%d)",xw[j],dw[j]);puts("");
		if(xw[c[im]]>dw[c[im]]){
			break;
		}
		if(im==n){
			if(t2==0){
				puts("-1");
				return 0;
			}
			t1=(t1+t2)%mod;
			t2=0;
		}
	}
	t1=(t1+t2)%mod;
	printf("%lld\n",t1);
	return 0;
}
