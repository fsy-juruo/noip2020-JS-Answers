/*
EI说过，希望都打上了注释
那么，我就多来些注释所带来的希望罢
EI ORZ
神仙墙上的所有神仙 ORZ
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
NOIP RP ++
*/
#include<bits/stdc++.h>
#define reg register
#define ri reg int
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline void read(int&x){
	x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar());
	x=c-'0';
	for(c=getchar();isdigit(c);c=getchar())x=x*10+c-'0';
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
const int mxn=55,mxm=404;
int n,m;
int a[mxn][mxm],siz[mxn];
bool used[mxn];
vector<pii>ans;
inline void G(int x,int y){
	ans.push_back(mp(x,y));
	a[y][++siz[y]]=a[x][siz[x]];
	a[x][siz[x]]=0;--siz[x];
}

inline void solve_1(int col){//now we need to make that all balls with color col is in the col_th place
	if(col==n){
		for(int i=siz[n+1];i;--i)G(n+1,n);
		return;
	}
	for(int i=siz[col];i;--i)G(col,n+1);
	int lst=n+1;
	for(int i=col+1;i<=n+1;++i){
		for(int j=siz[i];j;--j){
			if(a[i][j]!=col)continue;
			for(int k=siz[i];a[i][k]!=col;--k){
				if(siz[col]<m){
					G(i,col);
					continue;
				}
				G(i,lst);
			}
			if(siz[lst]==m)G(lst,col);
			G(i,lst);
			for(int j=siz[col];j and a[col][j]!=col;--j)G(col,i);
			G(lst,col);
		}
		lst=i;
	}
}
inline void solve1(){
	for(int col=1;col<=n;++col)solve_1(col);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();++i)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;++i)siz[i]=m;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>a[i][j];
	solve1();
	return 0;
}
