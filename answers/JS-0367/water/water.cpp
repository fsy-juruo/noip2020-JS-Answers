#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
inline int read(){
	int w=1,x=0;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return w*x;
}
int n,m,vh[N];
vector <int> g[N];
struct node{
	ll p,q;
};
node ans[N],c[N];
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
node add(node a,node b){
	if(a.p==0)return b;
	if(b.p==0)return a;
	node aa;
	aa.p=a.p*b.q+a.q*b.p;
	aa.q=a.q*b.q;
	ll t=gcd(aa.p,aa.q);
	aa.p/=t,aa.q/=t;
	return aa;
}

node mul(node a,ll num){
	a.q=a.q*num;
	ll t=gcd(a.p,a.q);
	a.p/=t;
	a.q/=t;
	return a;
}

void dfs(int x,node num){
	node t;
	int len=g[x].size();
	if(len==0){
		c[x]=add(c[x],num);
		return ;
	}
	t=mul(num,len);
	for(int i=0;i<len;i++){
		int v=g[x][i];
		dfs(v,t);
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		int x,y;
		x=read();
		if(x==0)vh[i]=1;
		for(int j=1;j<=x;j++){
			y=read();
			g[i].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		memset(c,0,sizeof(c));
		node t;
		t.p=t.q=1;
		dfs(i,t);
		for(int i=1;i<=n;i++)
			if(vh[i])ans[i]=add(ans[i],c[i]);
	}
	for(int i=1;i<=n;i++)
		if(vh[i]) printf("%lld %lld\n",ans[i].p,ans[i].q);
	return 0;
}
