#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const ll INF64=1e18;
const int MOD=1e9+7;
inline char nc(){
	static char buf[100005],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	char ch=getchar(); int sum=0; int f=0;
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) sum=(sum<<3)+(sum<<1)+(ch^48),ch=getchar();
	return f?-sum:sum;
}
const int maxn=5e5+5;
int n,k,w[15];
int c[maxn],d[maxn];
int sum[15][maxn];
namespace Subtask1{
	int a[45],tmp[45];
	int ans;
	inline bool check(){
		for(int i=1;i<=k;i++)
			if(tmp[i]<1||tmp[i]>w[i]) return false;
		return true;
	}
	inline bool pd(){
		for(int i=1;i<=k;i++) if(tmp[i]!=a[i]) return true;
		return false;
	}
	inline void bfs(){
		int idx=1;
		for(int i=1;i<=k;i++) tmp[i]=a[i];
//		for(int i=1;i<=k;i++) cout<<tmp[i]<<' ';
//		cout<<endl;
		while(true){
			tmp[c[idx]]+=d[idx]; 
			idx++; if(idx>n){
				idx=1; if(!pd()){
					printf("-1\n"); exit(0);
				}
			}  
//			for(int i=1;i<=k;i++) cout<<tmp[i]<<' ';
//			cout<<endl;
			ans++; if(ans>MOD) ans-=MOD;
			if(!check()) break;
		}
//		cout<<ans<<endl;
//		cout<<endl;
	}
	inline void dfs(int dep){
		if(dep==k+1){
			bfs(); return;
		}
		for(int i=1;i<=w[dep];i++){
			 a[dep]=i; dfs(dep+1); a[dep]=0;
		}
	}
	inline void solve(){
		dfs(1);
		printf("%d\n",ans);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(); k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++) c[i]=read(),d[i]=read();
	if(n<=100) Subtask1::solve();
	else printf("-1\n");
	return 0;
}
/*
5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1
*/
