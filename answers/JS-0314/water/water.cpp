#include<bits/stdc++.h>
using namespace std;
int n,m,d[100010],rd[100010],h[500010],nxt[500010],to[500010],p,x;
long long fz[100010],fm[100010],bfz,bfm,gcdfz;
void add(int x,int y){
	p++;
	nxt[p]=h[x];
	to[p]=y;
	h[x]=p;
	rd[y]++;
//	cd[x]++;
}
long long gcd(long long x,long long y){
	long long a=min(x,y),b=max(x,y),bx;
		while(a!=0){
			 bx=a;
			a=b%a;
			b=bx;
		}
	return b;
}
void bfs(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		fm[i]=1;
		if(!rd[i]){
			q.push(i);
			fz[i]=fm[i]=1;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
	//	printf("%lld %d\n",u,q.size());
	if(d[u]!=0){
		gcdfz=gcd(d[u],fz[u]);

		bfm=fm[u]*(d[u]/gcdfz);
		bfz=fz[u]/gcdfz;
	//	printf("%lld %lld %lld\n",gcdfz,bfz,bfm);
		for(int i=h[u];i;i=nxt[i]){
		int v=to[i];
		if(!fz[v]){
			fz[v]=bfz;
		}
		else{
			fz[v]=fz[v]*bfm+bfz*fm[v];
		}
		
		fm[v]=fm[v]*bfm;
		gcdfz=gcd(fz[v],fm[v]);
	//	printf("%lld %lld %lld\n",fz[v],fm[v],gcdfz);
		fz[v]/=gcdfz;
		fm[v]/=gcdfz;
		rd[v]--;
			//	printf("%lld %lld ",v,rd[v]);
		if(!rd[v]){
			q.push(v);
		} 
		}
}
	//	printf("\n"); 
	}
}
int main(){

freopen("water.in","r",stdin);
freopen("water.out","w",stdout);
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++){
	scanf("%d",&d[i]);
	for(int j=1;j<=d[i];j++){
		scanf("%d",&x);
		add(i,x);
	}
}
bfs();
for(int i=1;i<=n;i++){
	if(!d[i]){
		gcdfz=gcd(fz[i],fm[i]);
		fz[i]/=gcdfz;
		fm[i]/=gcdfz;
		printf("%lld %lld\n",fz[i],fm[i]);
	//	printf("%lld\n",i);
	}
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
