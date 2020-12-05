#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back

const int N=1e5+5;
const int inf=1e9+7;
const int mod=998244353;

ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
struct fact{
	ll p,q;
	void dec(){
		ll d=gcd(p,q);
		p/=d,q/=d;
	}
	friend fact operator + (fact a,fact b){
		ll d=gcd(a.q,b.q),lcm=a.q*b.q/d;
		fact ans; ans.q=lcm,ans.p=a.p*(lcm/a.q)+b.p*(lcm/b.q);
		ans.dec(); return ans;
	}
}ans[N];

int n,m,deg[N],d[N],out[N][5];
queue <int> q;

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=0;j<d[i];j++)scanf("%d",&out[i][j]),deg[out[i][j]]++;
	}
	for(int i=1;i<=n;i++)
		if(i<=m)ans[i]={1,1};
		else ans[i]={0,1};
	for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int t=q.front(); q.pop();
		fact tmp=ans[t]; tmp.q*=d[t],tmp.dec();
		for(int i=0;i<d[t];i++){
			int to=out[t][i];
			ans[to]=ans[to]+tmp,deg[to]--;
			if(!deg[to])q.push(to);
		}
	} for(int i=1;i<=n;i++){
		ans[i].dec();
		if(d[i]==0)printf("%lld %lld\n",ans[i].p,ans[i].q);
	}
	return 0;
}
