#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n, k, w[100050],c[100050],d[100010],fx,ans,now;

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i)
		scanf("%d", &w[i]);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &c[i], &d[i]);
	}
	if(k == 1){
		for(int i = 1; i <= w[1]; ++i){
			now = i;
			fx = 1;
			while(1){
				now += d[fx++];
				++ans;
				if(fx == n + 1) fx = 1;
				if(now <= 0 || now >w[1])break;
			}	
		}
		printf("%d", ans);
	}
	else printf("-1");
	fclose(stdin);fclose(stdout);
}
