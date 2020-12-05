#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define getchar nc
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
inline ll gcd(register ll a,register ll b){
	return (b==0)?a:gcd(b,a%b);
}
struct fac{
	ll a,b;
}res[N];
inline fac ad(register fac a,register fac b){
	fac c;
	ll tmp=gcd(a.b,b.b);
	c.b=a.b/tmp*b.b;
	c.a=a.a*(b.b/tmp)+b.a*(a.b/tmp);
	tmp=gcd(c.a,c.b);
	c.a/=tmp,c.b/=tmp;
	return c;
}
int n,m,ocnt[N],deg[N];
vector<int> e[N];
queue<int> q;
inline void topsort(){
	for(register int i=1;i<=n;++i) if(!deg[i]) q.push(i),res[i].a=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		fac tmp;
		tmp.a=res[u].a,tmp.b=res[u].b*(ll)e[u].size();
		for(register int i=0;i<(int)e[u].size();++i){
			int v=e[u][i];
			res[v]=ad(res[v],tmp);
			if(--deg[v]==0) q.push(v);
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i){
		res[i].a=0,res[i].b=1;
		ocnt[i]=read();
		for(register int j=1;j<=ocnt[i];++j){
			int x=read();++deg[x];
			e[i].push_back(x);
		}
	}
	topsort();
	for(register int i=1;i<=n;++i)
		if(ocnt[i]==0)
			printf("%lld %lld\n",res[i].a,res[i].b);
	return 0;
}

