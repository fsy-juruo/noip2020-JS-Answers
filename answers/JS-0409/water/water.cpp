#include<bits/stdc++.h>
using namespace std;
struct node{
	int y,next;
}e[500007];
int head[100007],tot;
int n,m;
long long p[100007],q[100007],a[100007];
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
void add(int x,int y){
	e[++tot].y=y;e[tot].next=head[x];head[x]=tot;
}
void dfs(int x,int fa){
	long long g=a[x];
	if(head[x]) q[x]*=g;
	for(int i=head[x];i;i=e[i].next){
		int y=e[i].y;
		if(y!=fa){
			if(p[y]==0||q[y]==0) p[y]=p[x],q[y]=q[x];
			else{
				long long k=gcd(q[y],q[x]);
				long long t=q[y]/k*q[x];
				p[y]=p[y]*(t/q[y])+p[x]*(t/q[x]);
				q[y]=t;
				k=gcd(p[y],q[y]); p[y]/=k;q[y]/=k;
			}
			dfs(y,x);
		}
	}
	if(head[x]!=0) p[x]=q[x]=0;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=1;j<=a[i];j++)
			scanf("%d",&y),add(i,y);
	}
	for(int i=1;i<=m;i++){
		p[i]=q[i]=1;
		dfs(i,0);
	}
	for(int i=1;i<=n;i++)
		if(head[i]==0) printf("%lld %lld\n",p[i],q[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
