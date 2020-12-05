#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(ne)x=-x;
}
void prt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)prt(x/10);
	putchar(x%10^48);
}
const int N=50,M=400;
int n,m;
int a[N+1][M+1];
vector<pair<int,int> > ans;
void swap(int x,int y,int z,int w){
//	cout<<x<<" "<<y<<" "<<z<<" "<<w<<"\n";
	swap(a[x][y],a[z][w]);
	if(m-y+1<m-w+1)swap(x,z),swap(y,w);
	for(int i=1;i<=m-y+1;i++)ans.pb(mp(x,n+1));
	for(int i=1;i<=m-w+1;i++)ans.pb(mp(z,x));
	ans.pb(mp(x,z)),ans.pb(mp(n+1,x)),ans.pb(mp(z,n+1));
	for(int i=1;i<=m-w+1;i++)ans.pb(mp(x,z));
	for(int i=1;i<=m-y+1;i++)ans.pb(mp(n+1,x));
}
int main(){
	freopen("ball.in","r",stdin);freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(a[i][j]);
	for(int i=1;i<=n;i++){
		int now=1;
		for(int j=i+1;j<=n;j++)for(int k=1;k<=m;k++)if(a[j][k]==i){
			while(a[i][now]==i)now++;
			swap(i,now,j,k);
		}
	}
	prt(ans.size()),putchar('\n');
	for(int i=0;i<ans.size();i++)prt(ans[i].X),putchar(' '),prt(ans[i].Y),putchar('\n');
	return 0;
}
