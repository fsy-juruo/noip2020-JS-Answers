#include <bits/stdc++.h>
#define ll long long
#define re register
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int maxn=1e5+5;
const int maxm=10+5;
int n,m,d[maxn];
ll p[maxn],q[maxn];
vector<int> son[maxn];
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
void dfs(int st){
	for(re int i=0;i<son[st].size();i++){
		int ver=son[st][i];
		p[ver]*=q[st]*d[st];
		p[ver]+=q[ver]*p[st];
		q[ver]*=d[st]*q[st];
		ll tmp=gcd(p[ver],q[ver]);
		p[ver]/=tmp;
		q[ver]/=tmp;
		dfs(ver);
	}
	if(d[st]){
		p[st]=0;
		q[st]=1;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;i++){
		p[i]=0;
		q[i]=1;
		scanf("%d",&d[i]);
		for(re int j=1;j<=d[i];j++){
			int x;scanf("%d",&x);
			son[i].push_back(x);
		}
	}
	for(re int i=1;i<=m;i++){
		p[i]=1;
		dfs(i);
	} 
	for(re int i=1;i<=n;i++){
		if(d[i]) continue;
		if(q[i]==1) printf("%lld\n",p[i]);
		else printf("%lld %lld\n",p[i],q[i]);
	}
	return 0;
}
