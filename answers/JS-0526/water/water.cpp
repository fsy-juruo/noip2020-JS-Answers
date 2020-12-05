#include<bits/stdc++.h>
using namespace std;
long long f,s,sum[150000],len[150000],p[150000];
int n,m;
vector<int> v[150000];
long long gcd(long long x,long long y){
	if(x%y)return gcd(y,x%y);
	return y;
}
void add(long long a,long long b,long long c,long long d){
	f=(long long)(a*d+b*c);
	s=(long long)(b*d);
	long long g=gcd(f,s);
	f/=g;
	s/=g;
}
void dfs(int pla){
	if(!len[pla])return ;
	int i;
	long long k=p[pla]*len[pla],g=sum[pla];
	sum[pla]=0;
	p[pla]=1;
	for(i=0;i<len[pla];i++){
		add(sum[v[pla][i]],p[v[pla][i]],g,k);
		p[v[pla][i]]=s;
		sum[v[pla][i]]=f;
		dfs(v[pla][i]);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int i,k,t;
	for(i=1;i<=n;i++){
		p[i]=1;
		scanf("%d",&k);
		len[i]=k;
		while(k--){
			scanf("%d",&t);
			v[i].push_back(t);
		}
	}
	for(i=1;i<=m;i++){
		sum[i]=1;
		dfs(i);
	}
	for(i=1;i<=n;i++){
		if(!len[i]){
			printf("%lld %lld\n",sum[i],p[i]);
		}
	}
	return 0;
}
