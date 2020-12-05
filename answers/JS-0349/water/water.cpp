#include <bits/stdc++.h>
using namespace std;
inline int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}
struct my {
    long long p,q;
	void sim() {
		int s=__gcd(p,q);
		p/=s,q/=s;
	}
	void add(const my &n) {
		p=p*n.q+n.p*q;
		q=q*n.q;
		sim();
	}
	void chu(int x) {
		q*=x;
		sim();
	}
	void print() {
		sim();
		printf("%lld %lld\n",p,q);
	}
};
const int maxn=1e5+10;
vector<int> G[maxn];
int n,m,out[maxn],in[maxn];
my a[maxn];
void dfs(int id)
{
	/*cout<<"*"<<id<<endl;
	cout<<"*****";*/
	//a[id].print();
	my now=a[id];
	now.chu(out[id]);
	if(out[id]!=0) {
		a[id].p=0,a[id].q=1;
	}
	for(int i=0; i<G[id].size(); ++i) {
		a[G[id][i]].add(now);
		dfs(G[id][i]);
	}
}
int main()
{
	/*my t1,t2; t1.p=1,t1.q=4,t2.p=5,t2.q=9;
	t1.add(t2);
	t1.sim();
	t1.print();*/
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) {
		a[i].q=1;
		scanf("%d",&out[i]);
		for(int j=1; j<=out[i]; ++j) {
			int x;
			scanf("%d",&x);
			G[i].push_back(x);
			++in[x];
		}
	}
	for(int i=1; i<=n; ++i) {
		if(in[i]==0) {
			a[i].p=1;
			dfs(i);
		}
	}
	for(int i=1; i<=n; ++i) {
		if(G[i].size()==0) {
			//cout<<i<<endl;
			a[i].print();
		}
	}
	return 0;
}
