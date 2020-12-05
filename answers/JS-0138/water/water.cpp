#include<bits/stdc++.h>
using namespace std;
int va[100019][2],k[100019],ni[100019][10];
int main(){
	int n,m;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(va,1,sizeof(va));
	for(int i=m+1;i<=n;i++)
		va[i][0]=0;
	for(int i=1;i<=n;i++){
		int d;
		scanf("%d",&d);
		if(d==0) {
			k[i]=1;
			continue;
		}
		for(int j=1;j<=d;j++){
			int a;
			scanf("%d",&a);
			va[a][0]=va[a][0]*d*va[i][1]+va[i][0]*va[a][1];
			va[a][1]=va[a][1]*d*va[i][1];
			int z=1,x=va[a][0],y=va[a][1];
			while(x!=0){
				z=x;
				x=y%x;
				y=z;
			}
			va[a][0]/=y;
			va[a][1]/=y;
		}
		va[i][1]=0;
		va[i][0]=0;
	}
	for(int i=1;i<=n;i++)
		if(k[i])
			printf("%d %d\n",va[i][0],va[i][1]);
	return 0;
}
