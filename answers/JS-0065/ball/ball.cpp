#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define rep(i,j,k) for(int (i) = (j);(i) <= (k);(i)++)
#define rap(i,j,k) for(int (i) = (j);(i) < (k) ;(i)++)
#define per(i,j,k) for(int (i) = (j);(i) >= (k);(i)--)
#define sit set<int>::iterator
#define mit map<int,int>::iterator
#define itrm(it,g) for(it = g.begin(); it != g.end(); it++)
#define mpr make_pair
#define pii pair<int,int>
vector<pii> op;
int n,m,a[505][505];
vector<int> a[505];
void add(int x,int y){
	op.pb(mpr(x,y));
}
void swp(int x1,int y1,int x2,int y2){
	rep(i,y1,m) add(x1,n+1);

}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
	rep(i,1,n) rep(j,i+1,n) {
		while(1){
			int one = -1,two = -1;
			rep(k,1,m)
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

