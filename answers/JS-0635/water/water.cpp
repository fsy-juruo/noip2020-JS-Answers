#include<cstdio>
using namespace std;
int n,m,i,j,gs,midd[100001][11];
long long p[100001],q[100001],h;
long long gcd(long long a,long long b){
	if(a<b)return gcd(b,a);
	if(a%b!=0)gcd(b,a%b);
	else return b;
}
void dfs(int dq,long long fs){
	if(midd[dq][0]==0){
		p[dq]=p[dq]*fs+q[dq];
		q[dq]=q[dq]*fs;
		h=gcd(q[dq],p[dq]);
		p[dq]/=h;
		q[dq]/=h;
		
	}
	else{
	for(int l=1;l<=midd[dq][0];l++)
	dfs(midd[dq][l],fs*midd[dq][0]);
	} 
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		p[i]=0;
		q[i]=1;
	}
//	for(i=1;i<=n;i++)printf("?:%d\n",q[i]);
	for(i=1;i<=n;i++){
		scanf("%d",&midd[i][0]);
		for(j=1;j<=midd[i][0];j++)
		scanf("%d",&midd[i][j]);
	}
	for(i=1;i<=m;i++)
	dfs(i,1);
	for(i=1;i<=n;i++)
	if(midd[i][0]==0)printf("%lld %lld\n",p[i],q[i]);
	return 0;
}/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
