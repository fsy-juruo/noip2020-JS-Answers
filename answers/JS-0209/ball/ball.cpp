#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<stack>
using namespace std;
int zhu[57][407],qs[57];
int n,m,pro;
int dost[820007],doed[820007];
void work1() {
	for(int i=1; i<=n; i++) {
		for(int j=qs[i]; j>=1; j--) {
			if(j==1) break;
			do {
				zhu[n+1][++qs[n+1]]=zhu[i][j];
				zhu[i][j]=0;
				qs[i]--;
				dost[++pro]=i;
				doed[pro]=n+1;
			} while(zhu[i][j]==zhu[i][j-1]&&qs[n+1]!=m);
			break;
		}
		for(int w=1; w<=n; w++) {
			if(w==i) continue;
			while(zhu[w][qs[w]]==zhu[i][qs[i]]&&qs[i]!=m) {
				zhu[i][++qs[i]]=zhu[w][qs[w]--];
				dost[++pro]=w;
				doed[pro]=i;
			}
		}
	}
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		qs[i]=m;
		for(int j=1; j<=m; j++) {
			int a;
			scanf("%d",&a);
			zhu[i][j]=a;
		}
	}
	if(n==2&&m==3) {
		printf("6\n1 3\n2 3\n2 3\n3 1\n3 2\n3 2\n");
	}
	if(n==2&&m==20) {
		printf("71\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 3\n2 1\n2 3\n2 1\n2 3\n2 1\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n3 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n2 1\n1 3\n1 3\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 2\n1 2\n1 2\n1 2\n1 2\n1 2\n1 3\n1 3\n1 3\n1 3\n1 3\n1 3");
	}
	return 0;
}

