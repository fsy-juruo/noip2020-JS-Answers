#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 50;
struct node{
	int to,nx;
}edge[N*5];
int n,m,num;
int head[N],cd[N],rd[N];
ll p[N],q[N],d[N];
ll np,nq,ngcd,tmp,tmq;
void addedge(int u,int v) {
	edge[++num].to=v;
	edge[num].nx=head[u];
	head[u]=num;
}
ll gcd(ll a,ll b) {
	if (a==0||b==0)  return 1ll;
	if (a%b==0)  return b;
	if (b%a==0)  return a;
	if (a>b)  return gcd(b,a%b);
	return gcd(a,b%a);
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int i,j,x,u,v;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) {
		scanf("%lld",d+i);
		for (j=1;j<=d[i];j++) {
			scanf("%d",&x);
			addedge(i,x);
			cd[i]++;
			rd[x]++;
		}
		q[i]=1ll;
	}
	queue<int>que;
	for (i=1;i<=m;i++) {
		p[i]=1ll;
		que.push(i);
	}
	while (!que.empty()) {
		u=que.front();
		que.pop();
		np=p[u], nq=q[u]*d[u];
		ngcd=gcd(np,nq);
		np/=ngcd;
		nq/=ngcd;
		if (np==0)  nq=1ll;
		for (i=head[u];i;i=edge[i].nx) {
			v=edge[i].to;
			tmq=q[v]*nq;
			tmp=p[v]*nq+np*q[v];
			ngcd=gcd(tmp,tmq);
			tmp/=ngcd;
			tmq/=ngcd;
			if (tmp==0)  tmq=1;
			p[v]=tmp;
			q[v]=tmq;
			rd[v]--;
			if (rd[v]==0)  que.push(v);
		}
	}
	for (i=1;i<=n;i++) 
		if (cd[i]==0)  cout<<p[i]<<" "<<q[i]<<endl;	
	return 0;
}

