#include<bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define PII pair<int,int>
#define fir first
#define sec second
using namespace std;
typedef long long ll;
const int Inf=0x3f3f3f3f;
const ll Infll=1e18+7;
const int MAXN=1e5+10;
const ll Mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-48);ch=getchar();}
	return x*f;
}
struct Node{int c,d;}a[MAXN];
int n,K,ans;
int W[15];
int nowpos[15],tmp[15];
int s[15];
int mxu[MAXN],mxd[MAXN];
bool flag,fflag;
inline void dfs(int dep){
	if(dep==K+1){
		cout<<nowpos[1]<<' '<<nowpos[2]<<endl;
		for(int i=1;i<=K;++i){tmp[i]=nowpos[i];}
		
		bool f=true;
		for(int i=1;i<=n;++i){
			tmp[a[i].c]+=a[i].d;
			++ans;
			if(tmp[a[i].c]<1||tmp[a[i].c]>W[a[i].c]){
				f=false;break;
			}
		}
		if(!f) return;
		if(!flag){
			fflag=true;
			puts("-1");
			return;
		}
		f=true;
		while(f){
			for(int i=1;i<=n;++i){
				tmp[a[i].c]+=a[i].d;
				++ans;
				if(tmp[a[i].c]<1||tmp[a[i].c]>W[a[i].c]){
					f=false;break;
				}
			}
		}
	}
	else{
		for(int i=1;i<=W[dep];++i){
			nowpos[dep]=i;
			dfs(dep+1);
			if(fflag) return;
		}
	}
}
inline void Sub_Task1(){
	dfs(1);
	if(fflag) return;
	printf("%d\n",ans);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();K=read();
	for(int i=1;i<=K;++i) W[i]=read();
	for(int i=1;i<=n;++i){
		a[i].c=read();
		a[i].d=read();
		s[a[i].c]+=a[i].d;
	}
	flag=false;
	for(int i=1;i<=K;++i) 
		if(s[i]!=0) flag=true;
	if(n<=100) Sub_Task1();
	else puts("-1");
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
