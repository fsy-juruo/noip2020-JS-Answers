#include<bits/stdc++.h>
#define mod 1000000007
//#define getchar nc
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
int n,k,w[15],p[105],q[105],ans;
bool f=1;
inline int dfs1(register int a,register int op,register int dep){
	if(dep>114514) {
	f=0;return 0;}
	a+=q[op];
	if(a<=0||a>w[1]) return 0;
	++op;
	if(op==n+1) op=1;
	return dfs1(a,op,dep+1)+1;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(register int i=1;i<=k;++i) w[i]=read();
	for(register int i=1;i<=n;++i) p[i]=read(),q[i]=read();
	if(k==1){
		for(register int i=1;i<=w[1];++i)
			ans=(0ll+dfs1(i,1,0)+ans)%mod;
		if(f)
		printf("%d\n",ans);
		else puts("-1");
	}
	else puts("-1");
	return 0;
}

