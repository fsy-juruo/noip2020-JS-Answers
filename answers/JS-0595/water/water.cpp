#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>G[100005];
int in[100005],out[100005];
ll p[100005],q[100005];
int n,m;
queue<int>qq;
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void solve(){
	while(!qq.empty()){
		int t=qq.front();qq.pop();
		int l=G[t].size();
		if(l>0){
			q[t]*=l;
			for(int i=0;i<l;i++){
				ll np,nq;
				int k=G[t][i];
				nq=q[k]/gcd(q[k],q[t])*q[t];
				np=p[k]*nq/q[k]+p[t]*nq/q[t];
				q[k]=nq;
				p[k]=np;
				in[k]--;
				if(in[k]==0)qq.push(k);
				int GCD=gcd(p[k],q[k]);
				p[k]/=GCD;
				q[k]/=GCD;
			}
			p[t]=0;
			q[t]=1;
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		q[i]=1;
		int d;
		scanf("%d",&d);
		for(int j=0;j<d;j++){
			int x;
			scanf("%d",&x);
			G[i].push_back(x);
			in[x]++;
			out[i]++;
		}
	}
	for(int i=1;i<=n;i++)if(in[i]==0){
		qq.push(i);
		p[i]=1;
	}
	solve();
	for(int i=1;i<=n;i++)if(out[i]==0)printf("%lld %lld\n",p[i],q[i]);
	return 0;
}
