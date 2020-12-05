//gzz
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,j,k) for (int i=j;i<=k;++i)
#define dep(i,j,k) for (int i=j;i>=k;--i)
#define M(a,b) memset(a,b,sizeof(a))
#define FILE "walk"
#define mod 1000000007
using namespace std;
struct node{
	int c,d;
}h[100005];
int n,k,ans,tot=1,w[11],sum[100005][11],qd[11],yz[11];
bool out(int now){
	rep(i,1,k){
		yz[i]+=sum[now][i];
		if (yz[i]<1 || yz[i]>w[i]){
			rep(j,1,i) yz[j]-=sum[now][j];
			return true;	
		}
	}
	rep(i,1,k) yz[i]-=sum[now][i];
	return false;
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,1,k) scanf("%d",&w[i]),tot*=w[i];
	rep(i,1,n){
		scanf("%d%d",&h[i].c,&h[i].d);
		rep(j,1,k) sum[i][j]=sum[i-1][j];
		sum[i][h[i].c]+=h[i].d;
	}
	rep(i,n+1,n*2){
		rep(j,1,k) sum[i][j]=sum[i-1][j];
		sum[i][h[i-n].c]+=h[i-n].d;
	}
	rep(i,1,n*2){
		int x=0;
		rep(j,1,k) x+=abs(sum[i][j]);
		if (x==0){
			printf("-1\n");
			return 0;
		}
	}
	rep(i,1,k-1) qd[i]=1;
	rep(p,1,tot){
		int now=k;qd[k]++;
		while (qd[now]>w[now]){
			qd[now]=1;now--;qd[now]++;
		}
		rep(i,1,k) yz[i]=qd[i];
		bool flag=true;
		while(flag){
			bool ai=false;
			if (out(1)) ans=(ans+1)%mod,ai=true,flag=false;
			for (int i=2;i<=n*2 && flag;i++)
				if (!out(i-1) && out(i))  ans=(ans+i)%mod,ai=true,flag=false;
			if (!ai){
				rep(i,1,k) yz[i]+=sum[n*2][i];
				ans=(ans+2*n%mod)%mod;	
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
