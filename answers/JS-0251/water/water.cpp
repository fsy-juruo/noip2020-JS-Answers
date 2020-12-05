#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define M 10
#define MEM(x) (memset(x,0,sizeof(x)))
int n,m;
int  w_in[50];int ni=0;
int  w_out[50];int no=0;
int he[N],ne[N],to[N];int idx=0;

int nn[N],mm[N];
int gcd(int x,int y){
	while(y!=0){
		int t=x;
		x=y;
		y=t%y;
	}
	return x;
}
struct num{
	int a,b;	
};
num ja(const num &x,const num& y){
	int xa=x.a,xb=x.b,ya=y.a,yb=y.b;
	ya*=xb;int b=yb;
	yb*=xb;
	xb*=b;
	xa*=b;
	int a=xa+ya;b=xb;
	int _gcd=gcd(a,b);
	a=a/_gcd;
	b=b/_gcd;
	num t;t.a=a;t.b=b;
	return t;
}num water[N];
num chu(const num& x,int y){
	int a=x.a,b=x.b;
	b*=y;
	int _gcd=gcd(a,b);//cout<<_gcd;
	int _a=a / _gcd;
	int _b=b/_gcd;
	num t;t.a=_a;t.b=_b;
	return t;
}
inline void push(int x,int y){
	to[++idx]=y;
	ne[idx]=he[x];
	he[x]=idx;
}

inline void init();
int main(){
	init();
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;scanf("%d",&t);
		for(int j=1;j<=t;j++){
			int y;
			scanf("%d",&y);
			nn[y]=nn[y]+1;
			mm[i]++;
			push(i,y);
		}
	}
	;
//-----------------------------------
	for(int i=1;i<=n;i++){
		water[i].a=0;water[i].b=1;
		if(he[i]==0) w_out[++no]=i;
		if(nn[i]==0) w_in[++ni]=i;
	}
	for(int i=1;i<=1;i++){
		
		queue<int > q;q.push(w_in[i]);
		water[w_in[i]].a=1;
		water[w_in[i]].b=1;
		while(!q.empty()){
			int u=q.front();
		//	cout<<u<<endl;
			for(int i=he[u];i;i=ne[i]){
				int v=to[i];
				if(v==0 ) continue;
				water[v]=ja(water[v],chu(water[u],mm[u]));
				q.push(v);
			}
			q.pop();
		}
	}
	for(int i=1;i<=no;i++) printf("%d %d\n",water[w_out[i]].a,water[w_out[i]].b);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline void init(){
	MEM(he);MEM(to);
	MEM(nn);MEM(ne);MEM(mm);
}










