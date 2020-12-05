//start:9:00
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=1e5+100;
int d[N],q[N],h,t,ru[N];
vector < int > G[N];
int gcd(int x,int y){
	if (x<y) swap(x,y);
	if (!y) return x;
	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
} 
struct frac{
	int x,y;
	void init0(){x=0,y=1;}
	void init1(){x=1,y=1;}
	void add(frac s){
		int p=lcm(y,s.y);
		x=x*p/y+s.x*p/s.y;
		y=p;
		int r=gcd(x,y);
//		cout << p << ' ' << r << ' ' << x << ' ' << y << endl;
		x/=r,y/=r;
	}
	frac divid(int c){
		frac tmp;
		tmp.x=x,tmp.y=y*c;
		return tmp;
	}
}ans[N];
void work(){
//	cout << gcd(4,6) << endl;
//	frac e1={3,4},e2={2,5};
//	e1.add(e2);
//	cout << e1.x << ' ' << e1.y << endl;
//	return;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> d[i];
		for (int j=1;j<=d[i];j++){
			int x;cin >> x;
			G[i].push_back(x);ru[x]++;
		}
	}
//	for (int i=1;i<=n;i++) cout << ru[i] << ' ';cout <<  endl;
	h=1;
	for (int i=1;i<=m;i++){
		q[++t]=i;ans[i].init1();
	}
	for (int i=m+1;i<=n;i++) ans[i].init0();
//	for (int i=1;i<=n;i++) cout << ans[i].x << ' ' << ans[i].y << endl;
	while (h<=t){
		int u=q[h];h++;
		for (int i=1;i<=d[u];i++){
			int tmp=G[u][i-1];
			frac tt=ans[u].divid(d[u]);
			ans[tmp].add(ans[u].divid(d[u]));
			frac tt2=ans[tmp];
//			cout << u << ' ' << tmp << ' ' << tt.x << ' ' << tt.y << ' ' << tt2.x << ' ' << tt2.y << endl;
			if (--ru[tmp]==0) q[++t]=tmp;
		}
//		for (int i=1;i<=n;i++) cout << ans[i].x << ' ' << ans[i].y << "  ";cout << endl;
	}
	for (int i=1;i<=n;i++){
		if (!G[i].size()){
			cout << ans[i].x << ' ' << ans[i].y << endl;
		}
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	work();
	return 0;
}
