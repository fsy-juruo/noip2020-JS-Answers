#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;

//NOIP FIGHT!
struct frac{
	long long m;
	long long s;
};

long long gcd(long long a,long long b){
	if(a == 1)return 1;
	if(b%a == 0)return a;
	return gcd( b%a , a );
}

struct frac add(struct frac a,struct frac b){
	if(a.s == 0){
		return b;
	}
	if(b.s == 0){
		return a;
	}
	long long lcm = a.m*b.m/gcd(a.m,b.m);
	a.s = a.s * b.m/gcd(a.m,b.m);
	b.s = b.s * a.m/gcd(a.m,b.m);
	struct frac res;
	res.m = lcm;
	res.s = a.s + b.s;
	return res;
}

long long n,m;
vector<long long> g[100010];
struct frac water[100010];
queue<long long> q;

void bfs(long long f){
	struct frac div;
	div.s = water[f].s;
	div.m = water[f].m*g[f].size();
	q.push(f);
	while(!q.empty()){
		div.s = water[q.front()].s;
		div.m = water[q.front()].m*g[q.front()].size();
		for(long long i = 0;i<g[q.front()].size();i++){
			water[g[q.front()][i]] = add(water[g[q.front()][i]],div);
			water[q.front()].s = 0;
			water[q.front()].m = 1;
			q.push(g[q.front()][i]);
		}
		q.pop();
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		long long d;
		cin>>d;
		for(long long j = 0;j<d;j++){
			long long x;
			cin>>x;
			g[i].push_back(x-1);
		}
	}
	for(long long i = 0;i<m;i++){
		water[i].s = 1;
		water[i].m = 1;
		bfs(i); 
	}
	for(long long i = 0;i<n;i++){
		if(g[i].size() == 0){
			cout<<water[i].s/gcd(water[i].s,water[i].m)<<" "<<water[i].m/gcd(water[i].s,water[i].m)<<endl;
		}
	}
	return 0;
}
