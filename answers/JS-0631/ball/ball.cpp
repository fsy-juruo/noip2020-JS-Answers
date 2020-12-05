#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 300;
inline int read(){
	int x = 0, f = 1; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -f;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
	return x * f;
}
int n, m;
stack<int> s[maxn];
int p[maxn][maxn];
int f[maxn][maxn][3];//第i根柱子到j位1/2的个数 
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i ++)//第i根柱子 
	for(int j = 1; j <= m; j ++) {p[i][j] = read();s[i].push(p[i][j]);}	
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			if(p[i][j] == 1){
				f[i][j][1] = f[i][j - 1][1] + 1;
				f[i][j][2] = f[i][j - 1][2];
			}
			else{
				f[i][j][2] = f[i][j - 1][2] + 1;
				f[i][j][1] = f[i][j - 1][1];				
			}
		}
	} 
	if(n == 1){ cout<<0; return 0;}
	return 0;
}

