#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
const int maxn=100077;
using namespace std;
struct edge {
	int st,fm,fz;
} w[maxn];

vector <int>s[maxn];
queue <int> q;
int n,m;
int ch[maxn],bv[maxn],v[maxn];;

int gcd(int x,int y) {
	if(y==0) return x;
	else gcd(y,x%y);
}

int gec(int x,int y) {
	int ans=gcd(x,y);
	return y*x/ans;
}

void add(int x,int y) {
	int a=w[x].fm,b=w[y].fm,temp=gec(a,b);
	if(!a) {
		w[x]=w[y];
		return;
	}
	if(a==b) {
		w[x].fz+=w[y].fz;
		return;
	} else {
		w[x].fz*=temp/w[x].fm,w[x].fm=temp;
		w[y].fz*=temp/w[y].fm,w[y].fm=temp;
		return add(x,y);
	}
}
void bfs() {
	while(!q.empty()) {
		int x=q.front();
		if(v[x]) {q.pop();continue;}
		for(int i(1); i<=s[x][0]; ++i) {
			int temp=s[x][i];
			add(temp,x);
			if(!v[temp]&&!bv[temp]) 	
			w[temp].fm=w[temp].fm*s[temp][0],q.push(temp),bv[temp]=1; 
		}
		q.pop();
	}
	return;
}
void hj(int x) {
	int temp=gcd(w[x].fz,w[x].fm);
	if(temp!=1) w[x].fz/=temp,w[x].fm/=temp;
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i(1); i<=n; ++i) {
		int num;
		scanf("%d",&num),s[i].push_back(num);
		if(!num) {
			v[i]=1;
			continue;
		}
		for(int j(1); j<=num; ++j) {
			int v;
			scanf("%d",&v),s[i].push_back(v);
		}
	}
	for(int i(1); i<=m; ++i) {
		w[i].st=1,w[i].fz=1,w[i].fm=s[i][0];
	}
	q.push(1);
	bfs();
	for(int i(1); i<=n; ++i) {
		if(v[i]){
			hj(i);
		printf("%d %d",w[i].fz,w[i].fm);
		}

	}
	return 0;
}
