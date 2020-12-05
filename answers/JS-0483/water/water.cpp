#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct node{
	long long p,q;
}w[MAXN];
int n,m,d[MAXN],a[MAXN][10],t[MAXN],f[MAXN];
long long k,l,g;
long long gcd(long long x,long long y){
	if(x<y)return gcd(y,x);
	if(x%y==0)return y;
	return gcd(y,x%y);
}
void add(int x,int y){
	//if(x==10)cout<<y<<' '<<w[y].p<<' '<<w[y].q*d[y]<<endl;
	if(w[x].p==0||f[x]==0){w[x].p=w[y].p;w[x].q=w[y].q*d[y];}
	else {
		k=w[x].p*w[y].q*d[y]+w[x].q*w[y].p;
		l=w[x].q*w[y].q*d[y];
		g=gcd(k,l);
		w[x].p=k/g;
		w[x].q=l/g;
	}
	//cout<<x<<' '<<y<<' '<<w[x].p<<' '<<w[x].q<<endl;
	return;
}
void dfs(int now,int dep){
	if(dep==12)return;
	for(int i=1;i<=d[now];++i){
		//cout<<a[now][i]<<endl;
		add(a[now][i],now);
		dfs(a[now][i],dep+1);
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		if(d[i]==0){
			t[++cnt]=i;
			f[i]=1;
		}
		for(int j=1;j<=d[i];++j)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=m;++i){w[i].p=1;w[i].q=1;dfs(i,0);}
	for(int i=1;i<=cnt;++i){
		printf("%lld %lld\n",w[t[i]].p,w[t[i]].q);
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
