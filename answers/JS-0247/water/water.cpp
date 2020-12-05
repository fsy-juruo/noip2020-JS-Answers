#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	int y=1;
	char a;
	a=getchar();
	while(a<'0'||a>'9'){
		if(a=='-')y=-1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=y;
}
struct ffff{
	unsigned long long p,q;
};
int n,m;
vector<int> f[100008];
ffff fj[100008];
int fz[100008];
int hunfen;
ffff fadd (ffff a,ffff b){
	ffff jg;
	jg.q=a.q*b.q;
	jg.p=a.p*b.q+b.p*a.q;
	unsigned long long fffz=__gcd(jg.p,jg.q);
	jg.p/=fffz,jg.q/=fffz;
	return jg;
}
ffff fans(int a){
	if(fj[a].q){
		return fj[a];
	}
	fj[a].q=1;
	for(int i=0;i<f[a].size();++i){
		ffff ffzz=fans(f[a][i]);
		ffzz.q*=fz[f[a][i]];
		fj[a]=fadd(fj[a],ffzz);
	}
	return fj[a];
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i){
		int d;read(d);
		fz[i]=d;
		if(!d)++hunfen;
		for(int j=1;j<=d;++j){
			int a;
			read(a);
			f[a].push_back(i);
		}
	}
	if(hunfen==1){
		cout<<m<<' '<<1<<endl;
		return 0;
	}
	for(int i=1;i<=m;++i)fj[i].p=1,fj[i].q=1;
	for(int i=m+1;i<=n;++i){
		if(fz[i])continue;
		fans(i);
		cout<<fj[i].p<<' '<<fj[i].q<<endl;
	}
	return 0;
}

