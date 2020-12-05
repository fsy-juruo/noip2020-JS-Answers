#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
inline int read() {
	int x(0),neg(1);char ch(getchar());
	while(!isdigit(ch)) {if (ch=='-') neg=-1;ch=getchar();}
	while(isdigit(ch)) {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*neg;
}
const int MAXN=400;
int a[MAXN+5][MAXN+5];
struct node{
	int x,y;
}ans[MAXN+5];
struct Q{int v,sr;};
vector<Q> ok[820000];
int used[MAXN+5];
int cnt[MAXN+5];
int flag=0;
int n,m;
inline bool cmp(const Q &a,const Q &b) {
	return a.sr<b.sr;
}
inline void dfs(int u,int x,int y) {
	if (u>820001) {return ;}
	int cntt=0;
	for (int i=1;i<=n+1;++i) if (used[i]) ++cntt;
	if (cntt==n) {
		flag=1;
		printf("%lld\n",u-1);
		for (int i=1;i<u;++i) cout<<ans[i].x<<' '<<ans[i].y<<endl;
		return ;
	}
	if (flag) return ;
	ok[u].clear();
	for (int i=1;i<=n+1;++i) 
		if (!used[i]) 
			ok[u].pb((Q){i,rand()*111111%23333});
	sort(ok[u].begin(),ok[u].end(),cmp);
	int tot=ok[u].size();
	for (int ii=0;ii<tot;++ii) {
		if (flag) return ;
		for (int jj=0;jj<tot;++jj) {
			if (flag) return ;
			int i=ok[u][ii].v,j=ok[u][jj].v;
			if (i!=j && cnt[i] && cnt[j]!=m && (i!=y || j!=x)) {
				a[j][++cnt[j]]=a[i][cnt[i]--];
				if (cnt[j]==m) {
					int cc=a[j][1];
					int ff=1;
					for (int k=2;k<=cnt[j];++k) {
						if (a[j][k]!=cc) {
							ff=0;
							break;
						}
					}
					if (ff) used[j]=1;
				}
				ans[u].x=i,ans[u].y=j;
				dfs(u+1,i,j);
				a[i][++cnt[i]]=a[j][cnt[j]--];
				used[j]=0;
			}
		}
	}
}
signed main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	srand(time(NULL));
	n=read(),m=read();
	for (int i=1;i<=n;++i) {
		cnt[i]=m;
		for (int j=1;j<=m;++j) a[i][j]=read();
	}
	if (n==1) puts("0");
	else dfs(1,0,0);
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
