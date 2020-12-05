#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[60][410];
int st[60];

void src(void){
	
}

int main(){
	
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		a[i][0]=m;
		for(int j=1;j<=m;++j){
			scanf("%d",&(a[i][j]));
		}
	}
	src();
	return 0;
}
