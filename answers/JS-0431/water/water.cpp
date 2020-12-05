#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;

int node[MAXN][7];
int n,m;
int outPut[12];
int q[MAXN];
long long h,t;

struct fs{
	long long fz;
	long long fm;
}val[MAXN];

long long Gcd(long long x, long long y){
	long long r = x % y;
	while(r){
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

void mutify(long long x, long long y){
	long long gcd = Gcd(val[x].fz, y);
	if(gcd != 1)
		val[x].fz /= gcd, y /= gcd;
	val[x].fm *= y;
}

void add(long long x, fs adv){
	if(val[x].fm == 0){
		val[x].fm = adv.fm;
		val[x].fz = adv.fz;
	}
	else{
		if(adv.fm == 0)
			return;
		long long gcd1 = Gcd(val[x].fm, adv.fm);		
		adv.fz = adv.fz * val[x].fm / gcd1;
		val[x].fm = val[x].fm * adv.fm / gcd1;
		val[x].fz = val[x].fz * adv.fm / gcd1;
		val[x].fz += adv.fz;
		long long gcd2 = Gcd(val[x].fz, val[x].fm);
		val[x].fz /= gcd2, val[x].fm /= gcd2;
	}
	
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++){
		node[i][0] = read();
		if(node[i][0] == 0)
			outPut[++outPut[0]] = i;
		else
			for(int j = 1; j <= node[i][0]; j++)
				node[i][j] = read();
	}
	for(int i = 1; i <= m; i++){
		val[i].fz = 1, val[i].fm = 1;
		q[++t] = i;
	}
	t++,h++;
	while(h < t){
		int x = q[h];
		h++;
		if(node[x][0] != 0)
			mutify(x, node[x][0]);
		else
			continue;
		for(int i = 1; i <= node[x][0]; i++){
			add(node[x][i], val[x]);
			q[t] = node[x][i];
			t++;
		}
		val[x].fm = val[x].fz = 0;
	}
	for(int i = 1; i <= outPut[0]; i++)
	{
		long long gcd = Gcd(val[outPut[i]].fz, val[outPut[i]].fm);
		val[outPut[i]].fz /= gcd;
		val[outPut[i]].fm /= gcd;
		cout << val[outPut[i]].fz << ' ' << val[outPut[i]].fm << endl;
	}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
