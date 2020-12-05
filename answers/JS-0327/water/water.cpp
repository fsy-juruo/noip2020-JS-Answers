#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int r=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-') ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) r=r*10+ch-'0',ch=getchar();
	return r*f;
}
struct func{
	int fz,fm;
}num[100005];
vector<int> vec[100005];
int deg[100005],n,m,a[100005][11],vis[100005];
queue<int> q;
void add(int x,int y){
	vec[x].push_back(y);deg[y]++;
}
func yf(func x){
	if (x.fm==0) x.fm=1;
	int z=__gcd(x.fm,x.fz);
	x.fm/=z;
	x.fz/=z;
	return x;
}
func ad(func x,func y){
	if (x.fm==0) x.fm=1;
	if (y.fm==0) y.fm=1;
	int z=x.fm*y.fm/(__gcd(x.fm,y.fm));
	func ans;
	ans.fm=z;
	ans.fz=z/x.fm*x.fz+z/y.fm*y.fz;
	ans=yf(ans);
	return ans;
}
func div(func x,int y){
	x.fm*=y;
	x=yf(x);
	return x;
}
void prin(func x){
	cout<<x.fz<<' '<<x.fm<<endl;
}
void spfa(int m){
	for (int i=1;i<=n;i++) num[i].fz=0,num[i].fm=1,vis[i]=0;
	for (int i=m+1;i<=n;i++) if (deg[i]==0) q.push(i);
	while (q.size()){
		int u=q.front();
		vis[u]=1;
		q.pop();
		for (int i=1;i<=a[u][0];i++) {
			int v=a[u][i];
			if (vis[v]) continue;
			deg[v]--;
			if (deg[v]==0&&v>m) q.push(v);
		}
	}
	for (int i=1;i<=m;i++) deg[i]=0,num[i].fz=1,num[i].fm=1,q.push(i);
	while (q.size()){
		int u=q.front();
		q.pop();
		for (int i=1;i<=a[u][0];i++) {
			int v=a[u][i];
			if (vis[v]) continue;
			deg[v]--;
			num[v]=ad(num[v],div(num[u],a[u][0]));
			if (deg[v]==0) q.push(v);
		}
	}
	return ;
}
signed main(){
freopen("water.in","r",stdin);
freopen("water.out","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++) {
	a[i][0]=read();
	for (int j=1;j<=a[i][0];j++) a[i][j]=read(),add(i,a[i][j]);
}
spfa(m);
for (int i=1;i<=n;i++){
	if (a[i][0]==0){
		num[i]=yf(num[i]);
		prin(num[i]);
	}
}
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
