//WSQ
#include<cstdio>
#include<queue>
#define ll long long
using namespace std;
int n,m;
int tot;
struct node{
	int to,next;
}a[1000005];
int head[100005];
int ru[100005],chu[100005];
void add(int x,int y){a[++tot].to=y;a[tot].next=head[x];head[x]=tot;}
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll zi[100005],mu[100005];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		if(i<=m)zi[i]=1;else zi[i]=0;
		mu[i]=1;
		scanf("%d",&chu[i]);
		for(int j=1;j<=chu[i];j++){
			int x;
			scanf("%d",&x);
			add(i,x);
			ru[x]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=m;i++)q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ll xx=zi[x],yy=mu[x]*1LL*chu[x];
		ll gg=gcd(xx,yy);
		xx/=gg;yy/=gg;
		for(int i=head[x];i;i=a[i].next){
			int y=a[i].to;
			ru[y]--;
			if(!ru[y])q.push(y);
			ll ggg=gcd(yy,mu[y]);
			ll mm=mu[y];
			mu[y]=yy*mu[y]/ggg;
			zi[y]=zi[y]*yy/ggg;
			zi[y]=zi[y]+mm/ggg*xx;
			ggg=gcd(zi[y],mu[y]);
			zi[y]/=ggg;mu[y]/=ggg;
		}
	}
	for(int i=1;i<=n;i++)if(chu[i]==0)printf("%lld %lld\n",zi[i],mu[i]);
	return 0;
}
