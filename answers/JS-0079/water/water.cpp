#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=6e5+5;
int n,m;
int hd[N],to[M],nex[M],cnt,in[N];
ll u[N],v[N];
int q[N],d[N],ans[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void add(int x,int y){
	cnt++;to[cnt]=y;nex[cnt]=hd[x];hd[x]=cnt;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j,num=0;
	for(i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(j=1;j<=d[i];j++){
			int x;
			scanf("%d",&x);
			add(i,x);
			in[x]++;
		}
		u[i]=0;
		v[i]=1;
		if(d[i]==0){
			num++;
			ans[num]=i;
		}
	}
	int h=1,t=0;
	for(i=1;i<=n;i++) 
	if(!in[i]){
		t++;
		q[t]=i;
		u[i]++;
	} 
	while(h<=t){
		for(i=hd[q[h]];i;i=nex[i]){
			ll p=gcd(v[q[h]]*d[q[h]],v[to[i]]);
			ll v2=v[q[h]]*d[q[h]]/p;
			u[to[i]]*=v2;
			u[to[i]]=u[to[i]]+u[q[h]]*(v[to[i]]/p);
			v[to[i]]*=v2;
			p=gcd(v[to[i]],u[to[i]]);
			v[to[i]]/=p;u[to[i]]/=p;
			in[to[i]]--;
			if(!in[to[i]]){
				t++;
				q[t]=to[i];
			}
		}
		h++;
	}
	for(i=1;i<=num;i++){
		printf("%lld %lld\n",u[ans[i]],v[ans[i]]);
	}
	return 0;
}
