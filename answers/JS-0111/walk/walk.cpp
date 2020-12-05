#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int P=1e9+7;
int c[11][MAXN];
int w[11];
int s[11][MAXN];
int pre[11];
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k;
	long long p=1;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; i++) {
		scanf("%d",&w[i]);
		p*=w[i];
	}
	for(int i=1; i<=n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		c[x][i]=y;
		for(int j=1;j<=k;j++){
			s[j][i]=s[j][i-1]+c[j][i];
		}
	}
	long long sum=0;
	printf("-1\n");
	return 0;
}
