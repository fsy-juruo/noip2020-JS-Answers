#include<bits/stdc++.h>
using namespace std;
const int Maxn = 1e5;
int n, m;
long long rd[Maxn + 7], cd[Maxn + 7];
vector<int> e[Maxn + 7];
inline int read(){
	char c=getchar();
	int x = 0, y = 1;
	while(c<'0' | c>'9'){
		if (c == '-') y = -1;
		c = getchar();
	}
	while( c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c=getchar();
	}
	return x * y;
}
struct fs{
	long long q;
	long long p;
};

fs ans[Maxn + 7];

long long dealgcd(long long a, long long b){
	if(b == 0) return a;
	return dealgcd(b, a % b);
}
void dfs(int x, long long t){
	if(!cd[x]){
		long long gcd = dealgcd(ans[x].p, t);
		ans[x].q = ans[x].q * t / gcd + ans[x].p / gcd;
		ans[x].p = ans[x].p * t / gcd;
		gcd = dealgcd(ans[x].p, ans[x].q);
		ans[x].q /= gcd;
		ans[x].p /= gcd;
		return;
	}
	
	for(int i = 0; i < e[x].size(); ++i){
		int v = e[x][i];
		dfs(v, t * cd[x]);
	}
	return;
}
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	n = read();
	m = read();
	
	for (int i=  1; i <= n; ++i){
		ans[i].q = 0;
		ans[i].p = 1;
		int d = read();
		cd[i] += d;
		while(d--){
			int v = read();
			rd[v] ++;
			e[i].push_back(v);
		}
	}
	if(m == 1){
		int rt;
		for(int i = 1; i <= n; ++i){
			if(!rd[i]){
				rt = i;
				break;
			}
		}
		dfs(rt, 1);
		
		for(int i = 1; i <= n; ++i){
			if(!cd[i]) printf("%d %d\n", ans[i].q, ans[i].p);
		}
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		if(!rd[i]){
			dfs(i, 1);
		}
	}
	
	for(int i = 1; i <= n; ++i){
		if(!cd[i]) printf("%d %d\n", ans[i].q, ans[i].p);
	}
	return 0;
}
