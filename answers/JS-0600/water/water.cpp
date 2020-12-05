#include<bits/stdc++.h>
using namespace std;
vector<int> g[100010];
vector<long long> p[100010];
int f[100010],a[100010];
long long gcd(long long a,long long b){
	if (a<b) swap(a,b);
	while (a%b!=0){
		long long c=a;
		a=b;
		b=c%a;
	}
	return b;
}
void dfs(int k,long long sum){
	if (g[k].size()==0){
		if (p[k].size()==0){
			p[k].push_back(1);
			p[k].push_back(sum);
			return;
		}
		long long pp,qq,gcdn;
		pp=p[k][0]*sum+p[k][1];
		qq=p[k][1]*sum;
		gcdn=gcd(pp,qq);
		pp=pp/gcdn;
		qq=qq/gcdn;
		p[k][0]=pp;
		p[k][1]=qq;
	}
	else{
		for (int i=0;i<g[k].size();i++){
			int l=g[k][i];
			dfs(l,sum*(long long)g[k].size());
		}
	}
}
int main(){
	freopen("r","water.in",stdin);
	freopen("w","water.out",stdout);

    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++){
    	int d;
    	scanf("%d",&d);
    	for (int j=1;j<=d;j++){
    		int k;
    		scanf("%d",&k);
    		g[i].push_back(k);
    		f[k]++;
		}
	}
	int tot=0;
	for (int i=1;i<=n;i++){
		if (f[i]==0) dfs(i,1);
		if (g[i].size()==0){
			tot++;
			a[tot]=i;
		}
	}
	for (int i=1;i<=tot;i++){
		printf("%lld %lld\n",p[a[i]][0],p[a[i]][1]);
    }

	return 0;
}

