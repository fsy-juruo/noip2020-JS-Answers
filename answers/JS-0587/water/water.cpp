#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
struct edge{
	int to,next;
}e[5*maxn];
int n,m,cn,d[maxn],head[maxn];
long long val[maxn][2];
vector<int>t[maxn];
bool out[maxn];
void add_edge(int u,int v){
	e[++cn].to=v;
	e[cn].next=head[u];
	head[u]=cn;
}
long long gcd(long long x,long long y){
	if(x<y) swap(x,y);
	if(x%y==0) return y;
	long long r=x%y;
	while(r){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
void add(int to,int from){
	if(!val[from][0]&&!val[from][1]) return;
	if(!val[to][0]&&!val[to][1]){
		val[to][0]=val[from][0];
		val[to][1]=val[from][1]*d[from];
		return;
	}
	long long nm=val[from][1]*d[from];
	long long q=val[to][1]*nm,p=val[to][1]*val[from][0]+val[to][0]*nm;
	long long mo=gcd(p,q);
	val[to][0]=p/mo;
	val[to][1]=q/mo;
}
void bfs(){
	queue<int>q;
	for(int i=1;i<=m;i++){
		val[i][0]=val[i][1]=1;
		q.push(i);
	}
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(int i=head[h];i;i=e[i].next){
			if(!out[e[i].to]) q.push(e[i].to);
			add(e[i].to,h);
		}
		val[h][0]=val[h][1]=0;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			int to;
			scanf("%d",&to);
			add_edge(i,to);
		}
		if(!d[i]) out[i]=1;
	}
	bfs();
	for(int i=1;i<=n;i++)
	  if(out[i]){
	  	int mo=gcd(val[i][0],val[i][1]);
	  	if(!val[i][0]&&val[i][1]){
	  		printf("0 1\n");
	  		continue;
		}
	  	printf("%lld %lld\n",val[i][0]/mo,val[i][1]/mo);
	  }
}
