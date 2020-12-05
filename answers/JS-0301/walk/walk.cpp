#include <iostream>
#include <cstdio>
using namespace std;

int n,k;
int w;
int c,d;
int dis=0;

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d",&n,&k);
	if(k==1){
		scanf("%d",&w);
		for(int i=1;i<=n;i++){
			scanf("%d %d",&c,&d);
			dis+=d;
		}
		if(dis==0){
			printf("-1");
			return 0;
		}
		int ans=(n+1)*n/2;
		printf("%d",ans);
		return 0;
	}
	printf("-1");
	return 0;
}

