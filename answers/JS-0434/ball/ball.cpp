//WSQ
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
struct node{
	int a[4][21];
	int b[100][2];
	int tot;
};
queue<node>q;
bool check(node xx){
	for(int i=1;i<=3;i++)if(xx.a[i][0]==m){
		for(int j=1;j<m;j++)if(xx.a[i][j]!=xx.a[i][j+1])return 0;
	}else if(xx.a[i][0]!=0)return 0;
	return 1;
}
void out(node xx){
	printf("%d\n",xx.tot);
	for(int i=1;i<=xx.tot;i++)printf("%d %d\n",xx.b[i][0],xx.b[i][1]);
}
node x;
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&x.a[i][j]);
	x.a[1][0]=x.a[2][0]=m;x.a[3][0]=0;
	memset(x.b,0,sizeof(x.b));
	x.tot=0;
	q.push(x);
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)if(i!=j&&x.a[i][0]&&x.a[j][0]<m){
				node y=x;
				y.a[j][0]++;
				y.a[j][y.a[j][0]]=y.a[i][y.a[i][0]];
				y.a[i][y.a[i][0]]=0;
				y.a[i][0]--;
				y.b[++y.tot][0]=i;
				y.b[y.tot][1]=j;
				if(check(y)){
					out(y);
					return 0;
				}
				q.push(y);
			}
	}
	return 0;
}
