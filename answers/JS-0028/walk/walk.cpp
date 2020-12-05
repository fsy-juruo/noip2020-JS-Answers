#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 100005;
const int maxk = 15; //wei du shu
const int modd = 1000000007;
int n, k;
int w[maxk];
int c[maxn], d[maxn], sum;
int nowp[maxk], tnp[maxk];

int main() {
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	int i, j, t, q, l, ans=0;
	scanf("%d%d", &n, &k);
	sum=1;
	for(i=1; i <= k; i++) {
		scanf("%d", &w[i]);
		if(k != 1 && w[i] >= 100005) {
			printf("-1\n");
			return 0;
		}
		sum=sum*w[i];
	}
	for(i=1; i <= n; i++) {
		scanf("%d%d", &c[i], &d[i]);
	}
	for(i=0; i < sum; i++) {
		t=i;
		for(j=1; j <= k; j++) {
			nowp[j]=t%w[j]+1;
			tnp[j]=nowp[j];
			t=t/w[j];
			//cout<<nowp[j]<<' ';
		}
		l=1;
		while(1) {
			nowp[c[l]]+=d[l];
			ans=(ans+1)%modd;
			if(nowp[c[l]] < 1 || nowp[c[l]] > w[c[l]]) break;
			if(l == n) {
				for(q=1; q <= k; q++) if(tnp[q] != nowp[q]) break;
				if(q == k+1) {
					printf("-1\n");
					return 0;
				}
			}
			l=l%n+1;
		}
		//cout<<ans<<endl;
	}
	printf("%d\n", ans);
	return 0;
}
/*
5 3
 5 5 5
2 1
1 1
1 -1
2 -1
3 1
*/
