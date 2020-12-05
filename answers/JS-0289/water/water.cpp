#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> P;
int w[100010];
int wt[100010][6], size[100010];
P p[100010];
long long gcd(long long a, long long b){
	if(a > b) swap(a, b);
	return a == 0 ? b : gcd(b % a, a);
}
void print(P a){
	long long ans = gcd(a.first, a.second);
	printf("%lld %lld\n", a.first/ans, a.second/ans);
}
void add(P &a, P b){
	if(a.first == 0){
		a.first = b.first;
		a.second = b.second;
		return;
	}
	long long ans = gcd(a.second, b.second);
	a.first *= b.second / ans;
	b.first *= a.second / ans;
	a.first += b.first;
	a.second = a.second * b.second / ans;
}
void solve(int a, P b){ // pipe a
	add(p[a], b);
	if(size[a] == 0) return;
	b.second *= size[a];
	for(int i = 1; i <= size[a]; i++)
	 solve(wt[a][i], b);
}
int main(){
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++)
		 scanf("%d", &wt[i][j]);
		size[i] = k;
	}
	P a = make_pair(1, 1);
	for(int i = 1; i <= m; i++)
	 solve(i, a);
	for(int i = 1; i <= n; i++)
	 if(size[i] == 0) print(p[i]);
	return 0;
}

