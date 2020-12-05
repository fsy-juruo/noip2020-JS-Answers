#include<bits/stdc++.h>
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template<typename T> void fw(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) fw(x/10);
	putchar(x%10+48);
}
template<typename T> void fwk(T x){fw(x);putchar(' ');}
template<typename T> void fwl(T x){fw(x);puts("");}
const int N=1e5+10,M=2e6+10;
int n,m;
int head[N],ver[M],Next[M],tot;
int outd[N],outnte[N],l;
inline long long gcd(long long x,long long y){
	while(y){
		long long z=x%y;
		x=y,y=z;
	}
	return x;
}
struct fs{
	long long p;
	long long q;
	void change(){
		long long d=gcd(p,q);
		p/=d;q/=d;
	}
}dat[N];
fs pluss(fs a,fs b){
	fs x;
	if(a.p==0) return b;
	if(b.p==0) return a;
	long long d=gcd(a.q,b.q);
	x.q=a.q*b.q/d;
	x.p=a.p*b.q/d+b.p*a.q/d;
	x.change();
	return x;
}
fs chu(fs a,long long b){
	a.q*=b;
	a.change();
	return a;
}
inline void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
inline void work(int x){
	bool flg=1;
	for(int i=head[x];i;i=Next[i]){
		flg=0;
		int y=ver[i];
		if(dat[y].p==0) work(y);
		fs xx=chu(dat[y],outd[y]);
		dat[x]=pluss(dat[x],xx);
	}
	if(flg){
		dat[x].p=1;dat[x].q=1;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	fr(n),fr(m);
	for(int i=1;i<=n;i++){
		fr(outd[i]);
		dat[i].q=1;
		if(outd[i]){
			for(int j=1,k;j<=outd[i];j++){
				fr(k);
				add(k,i);
			}
		}else{
			outnte[++l]=i;
		}
	}
	
	for(int i=1;i<=l;i++){
		work(outnte[i]);
		fwk(dat[outnte[i]].p);fwl(dat[outnte[i]].q);
	}
	return 0;
}

