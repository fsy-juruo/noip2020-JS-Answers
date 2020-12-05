#include <bits/stdc++.h>
#define N 55
#define M 405
using namespace std;
int n,m;
int num[M][N],row[M],k[N][M],maxx,len=0,a[100005][5];
queue<int> q[N];

bool check(int kk,int r)
{
	for(int i=1;i<kk;++i){
		if(row[k[r][i]]!=r) return false;
	}
	return true;
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&k[i][j]);
			int co=k[i][j];
			num[co][i]++;
			q[i].push(k[i][j]);
		}
	}
	for(int i=1;i<=m;++i){
		maxx=0;
		for(int j=1;j<=n;++j){
			if(num[i][j]>maxx) maxx=num[i][j],row[i]=j;
		}
	}
	for(int i=1;i<=n;++i){
		int j=m;
		while(!check(j,i)){
			a[++len][1]=i,a[len][2]=n+1;
			int tmp=q[i].end();
			q[i].pop();
			q[n+1].push(tmp);
		}
	}
	while(!q[n+1].empty()){
		int tmp=q[n+1].top();
		a[++len][1]=n+1,a[len][2]=tmp;
		q[n+1].pop();
	}
	printf("%d\n",len);
	for(int i=1;i<=len;++i){
		printf("%d %d\n",a[i][1],a[i][2])
	}
	return 0;
}
