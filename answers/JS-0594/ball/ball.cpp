#include<bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = 550;
const int MA = 820000;
const int U = 1e6;
inline int read() {
	int f=1,x=0;char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) if(ch=='-') f=0;
	for(; isdigit(ch); ch=getchar()) x=x*10+ch-'0';
	return f?x:-x;
}
#define pi pair<int,int>
#define fr first
#define to second

int n, m;
int tot;
pi a[U];
int top[N], st[N][M];
int ans;
int nu;
bool f;

bool check() {
	for(int i = 1; i <= n+1; i ++) {
		int col = st[i][1];
		for(int j = 2; j <= top[i]; j ++)
			if(col != st[i][j]) return 0;
	}
	return 1;
}

void doit() {
	if(ans > U) {f=0;return;}
	if(ans > nu) {f=0;return;}
	if(!top[a[ans].fr]) {f=0;return;}
	if(top[a[ans].to]>=m-1) {f=0;return;}
	if(check()) {f=1;return;}
	ans ++;
	st[a[ans].to][++top[a[ans].to]] = st[a[ans].fr][top[a[ans].fr]--];
	doit();
	st[a[ans].fr][++top[a[ans].fr]] = st[a[ans].to][top[a[ans].to]--];
}

int main() {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	n = read(), m = read();
	nu = U;
	if(n <= 10) {
		nu = 1e5;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			st[i][++top[i]] = read();
		}
	}
	while(tot < nu) {
		for(int i = 1; i <= n+1; i ++)
			for(int j = 1; j <= n+1; j ++) 
				if(i != j) 
					a[++tot].fr = i, a[tot].to = j;
	}	
	while(1) {
		random_shuffle(a+1, a+1+nu);
		ans = 1, f = 1;
		doit();
		if(f) {
			printf("%d\n", ans);
			for(int i = 1; i <= ans; i ++)
				printf("%d %d\n", a[i].fr, a[i].to);
			return 0;
		}
	}
	return 0;
}

