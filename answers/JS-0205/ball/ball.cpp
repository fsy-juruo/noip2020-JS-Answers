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
int n,m,mxd;
int top[55],stk[55][805];
PII ans[820005];
bool flag;

inline int Rand(int x){
	return 1ll*rand()*rand()%x+1;
}
inline bool Check(){
	int cnt=0;
	for(int i=1;i<=n+1;++i) if(top[i]==m) ++cnt;
	if(cnt!=n) return false;
	for(int i=1;i<=n+1;++i){
		if(top[i]!=m) continue;
		for(int j=2;j<=m;++j)
			if(stk[i][j]!=stk[i][j-1]){
				return false;
			}
	}
}
inline void dfs(int dep){
	if(Check()){
		flag=true;mxd=dep;
		return;
	}
	while(1){
		int x=Rand(n+1),y=Rand(n+1);
		if(top[x]>=1&&top[y]<=m-1){
			ans[dep]=MP(x,y);
			stk[y][++top[y]]=stk[x][top[x]--];
			dfs(dep+1);
			--top[y];++top[x];
		}
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand((unsigned)time(0));
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			stk[i][++top[i]]=read();
		}
	dfs(1);
	for(int i=1;i<=mxd;++i)
		printf("%d %d\n",ans[i].fir,ans[i].sec);
	return 0;
}

