#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n,m,strck[55][405],tp[55],ans[80005][3][25],tot,head=0,rear=1;
int hannuota;
void bfs(){
	while(1){
		for(int i=1;i<=m+1;i++){
			if(tp[i]>0){
				if(i!=1&&tp[1]<m){
					
				}
			}
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  	scanf("%d",&strck[i][j]);
	for(int i=1;i<=n;i++) tp[i]=m;
	tp[n+1]=0;
//	bfs();
	return 0;
}
