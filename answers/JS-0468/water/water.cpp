#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,tot;
long long t;
int r[100010],s[100010];
long long p[100010],q[100010];
int hd[100010],nxt[500010],to[500010];

template <typename T> void read(T &x){
	x=0;char h=getchar();
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;
}
void pls(int x,int y){
	++tot;
	to[tot]=y;
	nxt[tot]=hd[x];
	hd[x]=tot;
	return ;
}
long long gcd(long long a,long long b){
	if (a%b==0) return b;
		   else return gcd(b,a%b);
}
void clc(int x,long long a,long long b){
	t=q[x]*b/gcd(q[x],b);
	a=a*(t/b)+p[x]*(t/q[x]);b=t;
	t=gcd(a,b);a/=t;b/=t;
	p[x]=a;q[x]=b;
	return ;
}
void wrk(int x){
	r[x]=-1;
	for (int i=hd[x];i!=0;i=nxt[i]){
		r[to[i]]--;
		clc(to[i],p[x],q[x]*s[x]);
//		cout<<to[i]<<' '<<x<<' '<<p[x]<<' '<<q[x]*s[x]<<endl;
		if (r[to[i]]==0) wrk(to[i]);
	}
	
	return ;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(m);
	for (int i=1;i<=n;i++){
		read(s[i]);
		for (int j=1;j<=s[i];j++){
			read(y);
			pls(i,y);r[y]++;
		}
		p[i]=0;q[i]=1;
	}
	for (int i=1;i<=m;i++) p[i]=1,q[i]=1;
	for (int i=1;i<=n;i++)
	if (r[i]==0) wrk(i);
	for (int i=1;i<=n;i++)
	if (hd[i]==0) {
		cout<<p[i]<<' '<<q[i];
		puts("");
	}
	return 0;
}
