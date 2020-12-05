#include<bits/stdc++.h>
using namespace std;
struct TNT{
	int p,q;
}a[100005];
int n,m,s[100005],sum,d[100005];
int e[100005][55];
int gcd(long long a,long long b){
	return a%b==0?b:gcd(b,a%b);
}
void plu(int x,int y){
	TNT tmp;
	tmp.p=a[y].p,tmp.q=a[y].q*d[y];
	long long p1=1ll*tmp.p*a[x].q+1ll*tmp.q*a[x].p;
	long long q1=1ll*tmp.q*1ll*a[x].q;
	int G=gcd(p1,q1);
	p1/=G,q1/=G;
	a[x].p=int(p1),a[x].q=int (q1);
}
void bfs(){
	int hash[100005];
	memset(hash,0,sizeof(hash));
	queue<int> Q;
	for(int i=1;i<=m;i++)Q.push(i);
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=1;i<=d[u];i++){
			int v=e[u][i];
			plu(e[u][i],u);
			if(hash[v])continue;
			else {
				Q.push(v);
				hash[v]=1;
			}
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int x,j=1;j<=d[i];j++){
			scanf("%d",&e[i][j]);
		}
		if(d[i]==0)s[++sum]=i;
	}
	for(int i=1;i<=n;i++)a[i].p=0,a[i].q=1;
	for(int i=1;i<=m;i++)a[i].p=1,a[i].q=1;
	bfs();
	for(int i=1;i<=sum;i++){
		cout<<a[s[i]].p<<' '<<a[s[i]].q<<endl;
	}
	return 0;
}
/*
5 2
2 3 5
2 4 5
2 5 4
0
0
*/
