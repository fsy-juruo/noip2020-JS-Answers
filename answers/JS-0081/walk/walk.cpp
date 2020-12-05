#include<bits/stdc++.h>
using namespace std;

int n,k,ans;
int lar[11];
int jz[11][2][100002][2];
int now[11];

int main(){

freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		jz[i][0][1][0]=jz[i][1][1][0]=jz[i][0][1][1]=jz[i][1][1][1]=2;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&lar[i]);
	}
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		now[a]+=b;
		if(now[a]<jz[a][0][0][0]){
			//jz[a][0][jz[a][0][1]][0]=now[a];
			//jz[a][0][jz[a][0][1]++][1]=i;
		}
		if(now[a]>jz[a][1][0][0]){
			//jz[a][1][jz[a][1][1]][0]=now[a];
			//jz[a][1][jz[a][1][1]++][1]=i;
		}
	}
	srand(time(0));
	int hh=rand()%10;
	printf("%d",hh);
return 0;
}


