#include<bits/stdc++.h>
using namespace std;

namespace io{
	const int size=1<<22|1;
	char iBuf[size],*iS,*iT,c;
	char getc(){
		if(iS==iT){
			iS=iBuf;
			iT=iBuf+fread(iBuf,1,size,stdin);
		}
		if(iS==iT)return EOF;
		return *iS++;
	}
	template<class T>void qread(T &x){
		int f=1;
		for(c=getc();c<'0'||c>'9';c=getc())
			if(c=='-')f=-1;
		for(x=0;c>='0'&&c<='9';c=getc())
			x=(x<<3)+(x<<1)+(c&15);
		x*=f;
	}
}

const int maxn=100005;
const int base=1e9;
int n,m,ql,qr;
int edge[maxn][7],deg[maxn],cdeg[maxn],que[maxn];

class Bigint{
public:
	int a[3];
	Bigint(){memset(a,0,sizeof(a));}
	Bigint(int _a){
		memset(a,0,sizeof(a));
		for(int i=0;i<3;i++)a[i]=_a%base,_a/=base;
	}
	Bigint operator+(const Bigint &o)const{
		Bigint res;
		int add=0;
		for(int i=0;i<3;i++){
			res.a[i]=a[i]+o.a[i]+add;
			add=res.a[i]/base;
			res.a[i]%=base;
		}
		assert(!add);
		return res;
	}
	Bigint operator*(const int &o)const{
		Bigint res;
		int add=0;
		for(int i=0;i<3;i++){
			long long cur=1LL*a[i]*o+add;
			add=cur/base;
			res.a[i]=cur%base;
		}
		assert(!add);
		return res;
	}
	int operator%(const int &o)const{
		int res=0;
		for(int i=2;i>=0;i--)
			res=(1LL*res*base+a[i])%o;
		return res;
	}
	Bigint operator/(const int &o)const{
		Bigint res;
		int add=0;
		for(int i=2;i>=0;i--){
			long long cur=1LL*add*base+a[i];
			res.a[i]=cur/o;
			add=cur%o;
		}
		assert(!add);
		return res;
	}
	void print(){
		int p=2;
		while(p>=0&&!a[p])p--;
		if(p<0){
			putchar('0');
			return;
		}
		printf("%d",a[p]);
		for(int i=p-1;i>=0;i--)printf("%09d",a[i]);
	}
}val[maxn],bans;

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	bans=Bigint(1);
	for(int i=1;i<=11;i++)bans=bans*60;
	io::qread(n);io::qread(m);
	for(int i=1;i<=n;i++){
		io::qread(deg[i]);
		for(int j=1;j<=deg[i];j++)
			io::qread(edge[i][j]),cdeg[edge[i][j]]++;
	}
	ql=1;qr=0;
	for(int i=1;i<=n;i++)if(!cdeg[i])que[++qr]=i;
	while(ql<=qr){
		int x=que[ql++];
		if(x<=m)val[x]=bans;
		if(!deg[x])continue;
		val[x]=val[x]/deg[x];
		for(int i=1;i<=deg[x];i++){
			int y=edge[x][i];
			cdeg[y]--;
			val[y]=val[y]+val[x];
			if(!cdeg[y])que[++qr]=y;
		}
	}
	for(int i=1;i<=n;i++)if(!deg[i]){
		Bigint x=val[i],y=bans;
		while(x%2==0&&y%2==0)x=x/2,y=y/2;
		while(x%3==0&&y%3==0)x=x/3,y=y/3;
		while(x%5==0&&y%5==0)x=x/5,y=y/5;
		x.print();putchar(' ');
		y.print();putchar('\n');
	}
	return 0;
}
