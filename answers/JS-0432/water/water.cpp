#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int > p;
struct node
{
	int next,to;
} edge[200010];
int head[200010],cnt=1;
int d[200010],psk[200010],tmp=1,tot=1;
long long ans[200010][3];
queue<p > q;
void add(int u,int v)
{
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt++;
}
int pd(int x)
{
	for(int i = 1 ; i <= tmp ; i++ )
	{
		if(x==psk[i]){
			return i;
		}
	}
	return 0;
}
int gcd(int x,int y)
{
	int m=x,n=y,r;
	do
	{
		r=m%n;
		m=n;
		n=r;
	}while(r>0);
	return max(m,1);
}
int main()
{
	int n,m;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++ ){
		scanf("%d",&d[i]);
		if(d[i]==0){
			psk[tmp++]=i;
		}
		for(int j = 1 ; j <= d[i] ; j++ ){
			int y;
			scanf("%d",&y);
			add(i,y);
		}
	}
	for(int i = 1 ; i <= m ; i++ )
	{
		q.push(make_pair(1,i));
	}
	while(!q.empty())
	{
		p k=q.front();
		q.pop();
		int node=k.second;
		int f=pd(k.second);
		if(f){
			if(ans[f][2]==0){
				ans[f][1]=1;
				ans[f][2]=k.first;
//				if(gcd(ans[f][2],ans[f][1])!=1){
//					int kl=gcd(ans[f][2],ans[f][1]);
//					ans[f][1]/=kl;
//					ans[f][2]/=kl;
//				}			
				continue;
			}
			long long t=ans[f][2]*k.first/gcd(ans[f][2],k.first);
			ans[f][1]=t/ans[f][2]*ans[f][1]+t/k.first;
			ans[f][2]=t;
			if(gcd(ans[f][2],ans[f][1])!=1){
				int kl=gcd(ans[f][2],ans[f][1]);
				ans[f][1]/=kl;
				ans[f][2]/=kl;
			}
			continue;
		}
		for(int i = head[node] ; i ; i = edge[i].next )
		{
			long long s=k.first*d[node],to=edge[i].to;
			q.push(make_pair(s,to));
		}
	}
	for(int i = 1 ; i < tmp ; i++ )
	{
		printf("%lld %lld\n",ans[i][1],ans[i][2]);
	}
	return 0;
}
