#include<cstdio>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
int n,m,d[100007],x[100007][10];
LL p[100007],q[100007];
LL gcd(LL a,LL b){
	if (a%b==0) return b;
	return gcd(b,a%b);
}
void jia(LL a,LL b,int y){
	p[y]=a*q[y]+p[y]*b;
	q[y]*=b;
	LL tmp=gcd(max(p[y],q[y]),min(p[y],q[y]));
	p[y]/=tmp; q[y]/=tmp;
}
void dfs(int now){
	if (d[now]==0) return;
	for (int i=1;i<=d[now];i++){
		jia(p[now],q[now]*d[now],x[now][i]);
		dfs(x[now][i]);
	}
	p[now]=0;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>d[i];
		q[i]=1;
		if (i<=m) p[i]=1;
		for (int j=1;j<=d[i];j++) cin>>x[i][j];
	}
	for (int i=1;i<=m;i++) dfs(i);
	for (int i=1;i<=n;i++)
		if (d[i]==0) cout<<p[i]<<' '<<q[i]<<endl;
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
