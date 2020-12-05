#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define maxm 2000005
#define int long long
#define inf 0x3f3f3f3f
#define mod 1000000007
//#define local
void file(string ss){freopen((ss+".in").c_str(),"r",stdin);freopen((ss+".out").c_str(),"w",stdout);}
template<typename Tp> void read(Tp &x){
	x=0;int fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-'){fh=-1;}c=getchar();}
	while(c>='0'&&c<='9'){x=(x*10)+c-'0';c=getchar();}x*=fh;
}
struct Edge{int f,t,nxt;}edge[maxm];
int head[maxn],etot=1;
void add_edge(int f,int t){edge[++etot]=(Edge){f,t,head[f]};head[f]=etot;}
int n,m;
int rd[maxn],cd[maxn];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct fens{
	int p,q;
	fens operator +(fens y)const{
		int pp=1ll*p*y.q+1ll*q*y.p,qq=1ll*q*y.q,g;
		g=gcd(pp,qq);pp/=g;qq/=g;
		return (fens){pp,qq};
	}
	fens operator /(int y)const{
		int g=gcd(y,p);
		return (fens){p/g,1ll*(y/g)*q};
	}
};
fens a[maxn];
queue<int>q;
signed main(){
	#ifndef local
		file("water");
	#endif
	read(n);read(m);
	for(int i=1,t;i<=n;++i){
		read(t);cd[i]=t;
		for(int j=1,x;j<=t;++j){
			read(x);
			add_edge(i,x);rd[x]++;
		}
	}
	for(int i=1;i<=m;++i)a[i]=(fens){1,1};
	for(int i=m+1;i<=n;++i)a[i]=(fens){0,1};
	for(int i=1;i<=n;++i){
		if(!rd[i])q.push(i);
	}
	while(!q.empty()){
		int x=q.front();q.pop();
		fens vl=a[x];
		if(!cd[x])continue;
		vl=vl/cd[x];
		for(int i=head[x];i;i=edge[i].nxt){
			int y=edge[i].t;
			a[y]=a[y]+vl;
			if((--rd[y])==0)q.push(y);
		}
	}
	for(int i=1;i<=n;++i){
		if(!cd[i])printf("%lld %lld\n",a[i].p,a[i].q);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

