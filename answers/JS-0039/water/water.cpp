#include <bits/stdc++.h>
using namespace std;
int read(){
	int n = 0, f = 1;
	char x =  getchar();
	while((x < '0' || x > '9') && x != '-') x = getchar();
	if(x == '-'){f = -1; x = getchar();}
	while(x >= '0' && x <= '9'){n = n * 10 + x - '0';x = getchar();}
	return n * f;
}
int n, m;
int cd[100010], rd[100010];
int head[100010], to[1000010], last[1000010], cnt = 1;
void add(int u,int v){
	last[cnt] = head[u];
	to[cnt] = v;
	head[u] = cnt ++;
}
long long gcd(long long a,long long b){
	if(a % b == 0) return b;
	else return gcd(b, a % b);
}
long long fz[100010], fm[100010];
queue <int> que;
bool h[100010];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(head, -1, sizeof(head));
	n = read();m = read();
	int v;
	for(int i = 1;i <= n;i ++){
		cd[i] = read();
		for(int j = 1;j <= cd[i];j ++){
			v = read();
			add(i, v);
			rd[v] ++;
		}
	}
	for(int i = 1;i <= m;i ++){
		que.push(i);
		fz[i] = 1;fm[i] = 1;
	}
	int bh;
	while(!que.empty()){
		bh = que.front();
		que.pop();
		for(int i = head[bh];i != -1;i = last[i]){
			if(fz[to[i]] == 0){
				fz[to[i]] = fz[bh];
				fm[to[i]] = fm[bh] * cd[bh];
				long long gcd_ = gcd(fm[to[i]], fz[to[i]]);
				fm[to[i]] /= gcd_;
				fz[to[i]] /= gcd_;
			}
			else{
				long long gcd_ = gcd(fm[to[i]], fm[bh] * cd[bh]);
				long long fz_ = fz[bh], fm_ = fm[bh] * cd[bh];
				fm_ *= fm[to[i]] / gcd_;
				fz_ *= fm[to[i]] / gcd_;
				fm[to[i]] *= (fm[bh] * cd[bh]) / gcd_;
				fz[to[i]] *= (fm[bh] * cd[bh]) / gcd_;
				fz[to[i]] += fz_;
				gcd_ = gcd(fm[to[i]], fz[to[i]]);
				fm[to[i]] /= gcd_;
				fz[to[i]] /= gcd_;
			}
			rd[to[i]] --;
			if(rd[to[i]] == 0){
				que.push(to[i]);
			}
		}
	}
	for(int i = 1;i <= n;i ++){
		if(cd[i] == 0){
			printf("%lld %lld\n", fz[i], fm[i]);
		}
	}
	return 0;
}

