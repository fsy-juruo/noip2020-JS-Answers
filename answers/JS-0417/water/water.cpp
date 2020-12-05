#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;

struct youli{
	ll p,q;
	youli(void){
		p=0,q=1;
	}
	youli(int s,int t){
		p=s,q=t;
	}
	youli(int s){
		p=s,q=1;
	}
	void simp(void){
		ll r=__gcd(p,q);
		p/=r;
		q/=r;
	}
	void print(void){
		simp();
		printf("%lld %lld",p,q);
	}
};
inline youli add(youli x,youli y){
	ll gfm=x.q*y.q/__gcd(x.q,y.q);
	ll dx=gfm/x.q,dy=gfm/y.q;
	youli z(dx*x.p+dy*y.p,gfm);
	z.simp();
	return z;
}
inline youli div(youli x,ll y){
	youli z(x.p,x.q*y);
	z.simp();
	return z;
}
inline youli makeyl(int s,int t){
	youli z(s,t);
	z.simp();
	return z;
}

const int N=100000,D=5;
youli rece[N+10];
bool drain[N+10];
int si[N+10][D+5],idg[N+10],topu[N+10];

void make_topu(void){
	int ps=1,pe=1,aya;
	for(int i=1;i<=m;++i){
		topu[pe++]=i;
	}
	while(ps<pe){
		aya=topu[ps++];
		for(int i=1;i<=si[aya][0];++i){
			--idg[si[aya][i]];
			if(!idg[si[aya][i]])topu[pe++]=si[aya][i];
		}
	}
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&(si[i][0]));
		if(!si[i][0])drain[i]=1;
		for(int j=1;j<=si[i][0];++j){
			scanf("%d",&(si[i][j]));
			++idg[si[i][j]];
		}
	}
	for(int i=1;i<=m;++i){
		rece[i]=makeyl(1,1);
	}
	make_topu();
	for(int i=1;i<=n;++i){
		int ii=topu[i];
		youli k=rece[ii];
		if(!si[ii][0])continue;
		k=div(k,si[ii][0]);
		for(int j=1;j<=si[ii][0];++j){
			int o=si[ii][j];
			rece[o]=add(rece[o],k);
		}
	}
	
	for(int i=1;i<=n;++i){
		if(drain[i]){
			rece[i].print();
			puts("");
		}
	}
	
	return 0;
}

