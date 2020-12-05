//WSQ
#include<cstdio>
#define mod 1000000007
#define ll long long
using namespace std;
int n,k;
int w[15];
int c[500005],d[500005];
int a[15][2][100005];
int now[15],no[15];
int last[15];
int min(int a,int b){return a<b?a:b;}
int abs(int a){return a>0?a:-a;}
ll ans;
ll P=1;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
		now[i]=1;
		P*=w[i];
		if(P>=1e9){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=w[i];j++)a[i][1][j]=a[i][0][j]=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		last[c[i]]+=d[i];
		if(last[c[i]]==0)continue;
		int j;
		if(last[c[i]]>0)j=1;
		else j=0;
		if(a[c[i]][j][abs(last[c[i]])]==2e9)a[c[i]][j][abs(last[c[i]])]=i;
	}
	while(now[k]<=w[k]){
		int i=1;
		while(now[i]>w[i]){
			now[i]-=w[i];
			now[i+1]++;
			i++;
		}
		if(now[k+1])break;
		for(i=1;i<=k;i++)no[i]=now[i];
		int temp=1e9;
		while(temp==1e9){
			for(i=1;i<=k;i++)temp=min(temp,min(a[i][0][no[i]],a[i][1][w[i]-no[i]+1]));
			if(temp==1e9){
				ans=(ans+1LL*n)%mod;
				for(int i=1;i<=k;i++)no[i]=no[i]+last[i];
			}
			else{
				ans=(ans+1LL*temp)%mod;
				break;
			}
		}
		now[1]++;
	}
	printf("%lld\n",ans);
	return 0;
}
