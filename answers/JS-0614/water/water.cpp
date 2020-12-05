#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int end[15];
vector<int>G[maxn];
int n,m,tot;
struct node{
	long long a,b;
}ans[maxn];
int in[maxn],num[maxn];
queue<int>p,q;
long long gcd(long long x,long long y){
	if(x==y)
		return x;
	if(x>y)
		swap(x,y);
	if(y%x==0)
		return x;
	return gcd(x,y%x);
}
void add(int u,int v){
	long long x,y,k;
	x=(long long)ans[u].a*ans[v].b+(long long)ans[u].b*num[u]*ans[v].a;
	y=(long long)ans[u].b*ans[v].b*num[u];
	for(k=gcd(x,y);k!=1&&k!=0;k=gcd(x,y)){
		x/=k;
		y/=k;
	}
	ans[v].a=x;
	ans[v].b=y;
}
void topsort(){
	int i,u,v;
	for(i=1;i<=n;i++)
		if(!in[i]){
			q.push(i);
			ans[i].a=1;
		}
	while(!q.empty()){
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(i=0;i<G[u].size();i++){
				v=G[u][i];
				in[v]--;
				add(u,v);
				if(!in[v])
					p.push(v);
			}
		}
		while(!p.empty()){
			q.push(p.front());
			p.pop();
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j,d,v;
	for(i=1;i<=n;i++){
		ans[i].b=1;
		scanf("%d",&d);
		num[i]=d;
		for(j=1;j<=d;j++){
			scanf("%d",&v);
			G[i].push_back(v);
			in[v]++;
		}
	}
	topsort();
	for(i=1;i<=n;i++)
		if(!num[i])
			printf("%lld %lld\n",ans[i].a,ans[i].b);
	return 0;
}
