#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n,m,len;
int in[MAXN],out[MAXN];
vector<int> G[MAXN];
queue<int> q;

ll gcd(ll x,ll y){
	if(!y)
		return x;
	return gcd(y,x % y);
}

struct Fraction{
	ll x,y; // x / y
	
	Fraction(ll _x = 0,ll _y = 1){
		ll g = gcd(_x,_y);
		x = _x / g;
		y = _y / g;
	}
	
	Fraction operator + (const Fraction &rhs) const{
		return Fraction(x * rhs.y + y * rhs.x,y * rhs.y);
	}
	
	Fraction operator / (const int &rhs) const{
		return Fraction(x,y * (ll)rhs);
	}
	
	void print(){
		printf("%lld %lld\n",x,y);
	}
} flow[MAXN];

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1,x,y;i <= n;i++){
		scanf("%d",&x);
		while(x--){
			scanf("%d",&y);
			G[i].push_back(y);
			in[y] += 1;
			out[i] += 1;
		}
	}
	for(int i = 1;i <= m;i++)
		flow[i] = Fraction(1,1);
	for(int i = 1;i <= n;i++){
		if(!in[i])
			q.push(i);
	}
	while(!q.empty()){
		int u = q.front();
		q.pop();
		Fraction tmp = flow[u] / out[u];
		for(int i = 0;i < (int)G[u].size();i++){
			int v = G[u][i];
			flow[v] = flow[v] + tmp;
			in[v] -= 1;
			if(!in[v])
				q.push(v);
		}
	}
	for(int i = 1;i <= n;i++){
		if(!out[i])
			flow[i].print();
	}
	return 0;
}

