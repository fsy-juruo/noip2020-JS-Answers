//give me two bottle of water and a hard question
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cstring>
#define F(i,l,r) for(int i = l; i <= r; ++i)
#define REP(i,r,l) for(int i = r; i >= l; --i)
#define pa pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
const int N = 1e5 + 10;
int n,m,to,in[N],d[N],ans = 0,now;
LL numa[N],numb[N];
vector<int> G[N];
queue<int> q;
void add(int u,int v) {
	G[u].push_back(v);
}
int gcd(int a,int b) {
	if(b == 0) return a;
	else return gcd(b,a%b);
}
LL lmn(LL a,LL b) {
	return a * b / gcd(a,b);
}
void easy(LL &a,LL &b) {
	LL gd = gcd(a,b);
	a /= gd,b /= gd;
	return;
}
void add_up(LL &aa,LL &ab,LL ba,LL bb) {
	LL t = lmn(ab,bb);
	LL ax = t / ab,bx = t / bb;
	aa *= ax,ab = t;
	ba *= bx,bb = t;
	aa += ba;
	easy(aa,ab);
	return;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(numa,0,sizeof(numa));
	F(i,1,N  - 1)
		numb[i] = 1;
	scanf("%d%d",&n,&m);
	F(i,1,n) {
		scanf("%d",&d[i]);
		F(k,1,d[i]) {
			scanf("%d",&to);
			add(i,to);
			in[to]++;
		}
	}
	F(i,1,n) {
		if(in[i] == 0) {
			q.push(i);
			numa[i] = 1;
			numb[i] = 1;
		}
	}
	while(!q.empty()) {
		now = q.front();q.pop();
		if(d[now] == 0) continue;
		LL tmpa = numa[now],tmpb = numb[now] * d[now];
		easy(tmpa,tmpb);
		F(i,0,d[now] - 1) {
			int v = G[now][i];
			add_up(numa[v],numb[v],tmpa,tmpb);
			if(--in[v] == 0)	q.push(v);
		}
	}
	F(i,1,n) {
		if(d[i] == 0) {
			printf("%lld %lld\n",numa[i],numb[i]);
		}
	}
	return 0;
}
//all goes well
//$hanker_007$