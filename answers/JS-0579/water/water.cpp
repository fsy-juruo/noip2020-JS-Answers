#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
struct Frac{
	long long p,q;
};
int n,m;
std::vector<int> edge[100005];
std::vector<int> sn;
std::vector<int> ori;
int inn[100005]={0};
int d[100005]={0};
Frac ans[100005];
bool vis[100005]={0};
void tpsort(int x)
{
	for(int i=0;i<edge[x].size();++i){
		inn[edge[x][i]]--;
		if(inn[edge[x][i]]==0){
			vis[edge[x][i]]=1;
			sn.push_back(edge[x][i]);
			tpsort(edge[x][i]);
		}
	}
	for(int i=0;i<ori.size();++i){
		if(vis[ori[i]]==0){
			vis[ori[i]]=1;
			sn.push_back(ori[i]);
			tpsort(ori[i]);
		}
	}
}
long long gcd(long long a,long long b)
{
	if(a<b) std::swap(a,b);
	if(b==0) return b;
	while(true){
		a%=b;
		if(a==0) return b;
		b%=a;
		if(b==0) return a;
	}
}
void simp(Frac &a)
{
	int gc=gcd(a.p,a.q);
	a.p/=gc;
	a.q/=gc;
}
Frac operator+(Frac a,Frac b)
{
	Frac res;
	res.q=a.q*b.q;
	res.p=a.p*b.q+a.q*b.p;
	simp(res);
	return res;
}
Frac operator/(Frac a,long long b)
{
	a.q*=b;
	simp(a);
	return a;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		for(int j=1,tv;j<=d[i];++j){
			scanf("%d",&tv);
			edge[i].push_back(tv);
			inn[tv]++;
		}
	}
	for(int i=1;i<=n;++i){
		if(inn[i]==0){
			ori.push_back(i);
			ans[i].p=1;
			ans[i].q=1;
		}
		else{
			ans[i].p=0;
			ans[i].q=1;
		}
	}
	vis[ori[0]]=1;
	sn.push_back(ori[0]);
	tpsort(ori[0]);
	int u,v;
	Frac tmp;
	for(int i=0;i<sn.size();++i){
		u=sn[i];
		if(d[u]!=0)	tmp=ans[u]/(long long)d[u];
		for(int j=0;j<edge[u].size();++j){
			v=edge[u][j];
			ans[v]=ans[v]+tmp;
		}
	}
	for(int i=1;i<=n;++i){
		if(d[i]==0){
			printf("%lld %lld\n",ans[i].p,ans[i].q);
		}
	}
}
