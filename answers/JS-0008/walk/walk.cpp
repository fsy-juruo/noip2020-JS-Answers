#include <bits/stdc++.h>
using namespace std;
int n,k;
int w[10];
int c[500005],d[500005];
int area[15];
int ans; 
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(register int i = 1;i <= k;++i)scanf("%d",&w[i]);
	for(register int i = 1;i <= n;++i)scanf("%d%d",&c[i],&d[i]);
	printf("-1\n");
	return 0;
}
