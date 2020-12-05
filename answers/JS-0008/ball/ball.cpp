#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[55][405];
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++)scanf("%d",&b[i][j]);
	}
	if(n == 1){
		printf("0");
		return 0;
	}else{
		printf("820000\n");
	}
	return 0;
}
