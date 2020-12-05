#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 605;
int n, m;
int a[maxn][maxn], t[55];
int ans[820005][5], ansz;

void sw(int aa, int bb) {
	ansz++;
	ans[ansz][1]=aa; 
	ans[ansz][2]=bb;
	a[bb][t[bb]+1]=a[aa][t[aa]];
	t[bb]++; t[aa]--;
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int i, j, a1=0, a2=0, now1;
	t[1]=m; t[2]=m; t[3]=0;
	for(i=1; i <= n; i++) {
		for(j=1; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if(i == 1 && a[i][j] == 1) a1++;
			if(i == 1 && a[i][j] == 2) a2++;
		}
	}
	for(i=1; i <= a1; i++) {
		sw(2, 3);
	}
	while(t[1] > 0) {
		if(a[1][t[1]] == 1) {
			sw(1, 2);
		}
		else {
			sw(1, 3);
		}
	}
	for(i=1; i <= a1; i++) sw(2, 1);
	for(i=1; i <= a2; i++) sw(3, 1);
	while(t[2] > 0) sw(2, 3);
	for(i=1; i <= a2; i++) sw(1, 2);
	while(t[3] > 0) {
		if(a[3][t[3]] == 1) sw(3, 1);
		else sw(3, 2);
	}
	printf("%d\n", ansz);
	for(i=1; i <= ansz; i++) {
		printf("%d %d\n", ans[i][1], ans[i][2]);
	}
	return 0;
}
