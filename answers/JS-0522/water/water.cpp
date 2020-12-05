#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "water"
const int MAXN=100010;
int n,m,rbq[MAXN][6];

struct dV{
	LL p,q;
}wwz[MAXN];


inline int read(){
	int xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}

LL gcd(LL p,LL q){
	if(p<q) swap(p,q);
	if(!q) return p;
	return gcd(q,p%q);
}

dV add_wt(dV fr,LL p,LL q){
	int p_1=fr.p,q_1=fr.q;
	LL xfm,xfz,gys;
	xfm=q_1*q;
	xfz=(q_1*p+p_1*q);
	gys=gcd(xfm,xfz);
	xfm/=gys;
	xfz/=gys;
	dV LLer;
	LLer.p=xfz,LLer.q=xfm;	
//	cout<<p_1<<" "<<q_1<<"  "<<p<<" "<<q<<"  "<<xfz<<" "<<xfm<<endl;
	return LLer;
}

void jfs(int pt,LL fm,LL fz,int deep){
//	cout<<pt<<" "<<fm<<" "<<fz<<" "<<deep<<endl;
	if(deep>=12) return;
	if(!rbq[pt][0]) {
		wwz[pt]=add_wt(wwz[pt],fz,fm);
	}
	else{
		for(int i=1;i<=rbq[pt][0];++i) jfs(rbq[pt][i],fm*rbq[pt][0],fz,deep+1);
	}
}

int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	n=read(),m=read();
	dV sb;
	sb.p=0;
	sb.q=1;
	for(int i=1;i<=n;++i){
		wwz[i]=sb;
		rbq[i][0]=read();
		for(int j=1;j<=rbq[i][0];++j) rbq[i][j]=read();
	}
	for(int i=1;i<=m;++i){
		jfs(i,1,1,0);
	}
	for(int i=1;i<=n;++i){
		if(!rbq[i][0]) cout<<wwz[i].p<<" "<<wwz[i].q<<endl;
	}
	return 0;
}

