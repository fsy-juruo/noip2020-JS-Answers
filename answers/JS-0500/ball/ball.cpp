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
const int maxn=55;
const int maxm=405;
int n,m;
int a[maxn][maxm];
int tmp[maxn][maxm];
inline bool check(){
	for(int i=1;i<=n;i++){
		int temp=tmp[i][1];
		if(tmp[i][0]!=m) return false;
		for(int j=2;j<=m;j++) if(tmp[i][j]!=temp) return false;
	}
	return true;
} 
inline void dfs(vector<pii> ans){
	int d[maxn][maxm];
	for(int i=1;i<=n+1;i++) 
		for(int j=0;j<=m;j++)
			d[i][j]=tmp[i][j];
	if(check()){
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].F,ans[i].S);
		exit(0);
	}
//	puts("FUCK");
	for(int i=1;i<=n+1;i++)
		for(int j=i+1;j<=n+1;j++) if(d[i][0]>=1&&d[j][0]<=m-1){
			int tmp1=d[i][d[i][0]];
			d[i][d[i][0]--]=0; d[j][++d[j][0]]=tmp1;
			for(int ii=1;ii<=n+1;ii++) 
				for(int jj=0;jj<=m;jj++)
					tmp[ii][jj]=d[ii][jj];
			ans.pb(mp(i,j)); dfs(ans); ans.pop_back();
			d[i][++d[i][0]]=tmp1; d[j][d[j][0]--]=0;
		}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(); m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++) a[i][0]=m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			tmp[i][j]=a[i][j];
	vector<pii>vec; vec.clear();
	dfs(vec);
	return 0;
}

