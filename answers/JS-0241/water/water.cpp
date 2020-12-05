#include<bits/stdc++.h>
#define MAXN 100005
#define ll long long
using namespace std;
queue <int> Q;
int n,m,head[MAXN],cnt;
struct tmp
{
	int from,to;
}a[MAXN<<2];
void add(int x,int y)
{
	a[++cnt].from=head[x];
	head[x]=cnt;
	a[cnt].to=y;
}
ll gcd(ll a,ll b){return (b==0)?a:gcd(b,a%b);}
ll p[MAXN],q[MAXN];
int v[MAXN],num[MAXN],sum[MAXN];
void deal(int x,int y)
{
	ll P=p[x],Q=q[x];
	Q*=num[x];
	ll G1=gcd(P,Q);
	P/=G1; Q/=G1;
	ll p2=P*q[y]+Q*p[y],q2=Q*q[y];
	ll G2=gcd(p2,q2);
	p2/=G2; q2/=G2;
	p[y]=p2; q[y]=q2;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		q[i]=1;
		scanf("%d",&num[i]);
		int y;
		for(int j=1;j<=num[i];j++){
			scanf("%d",&y);
			add(i,y); sum[y]++;
		}
	}
	for(int i=1;i<=m;i++){
		p[i]=q[i]=1;
		Q.push(i);
	}
	while(!Q.empty()){
		int x=Q.front(); Q.pop();
		for(int i=head[x];i;i=a[i].from){
			int y=a[i].to;
			sum[y]--;
			deal(x,y);
			if(!sum[y]) Q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
	if(!num[i]) printf("%lld %lld\n",p[i],q[i]);
	return 0;
}
