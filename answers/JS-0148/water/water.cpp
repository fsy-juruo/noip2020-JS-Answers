#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,d[100003],h[100003][7],rd[100003];
ll sm[100003][3];
queue<int>q;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
void add(int b,int a){
	ll sn=sm[b][2]*sm[a][1]+sm[a][2]*d[a]*sm[b][1];
	ll mr=sm[b][2]*sm[a][2]*d[a];
	ll gd=gcd(sn,mr);
	sn/=gd,mr/=gd;
	sm[b][1]=sn,sm[b][2]=mr;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];++j){
			scanf("%d",&h[i][j]);
			rd[h[i][j]]++;
		}
		sm[i][2]=1;
	}
	for(int i=1;i<=m;++i)
		sm[i][1]=1,q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=d[u];++i){
			int v=h[u][i];
			add(v,u),rd[v]--;
			if(rd[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=n;++i)
		if(d[i]==0)
			printf("%lld %lld\n",sm[i][1],sm[i][2]);
	return 0;
}
