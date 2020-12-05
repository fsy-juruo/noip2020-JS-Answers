#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
typedef unsigned long long ll;
const ll Mx = 18446744073709551615uLL;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)

int n,m;
vector<int> edge[N];
int d[N];

ll gcd(ll x,ll y){
	return y == 0 ? x : gcd(y,x%y);
}

struct fraction{
	ll x,y;
	fraction(ll a=0,ll b=1){
		x = a,y = b;
		assert(b > 0);
		ll w = gcd(x,y);
		x /= w; y /= w;
	}
	fraction operator +(const fraction &b) const {
		fraction c;
		if(Mx/b.y < y/gcd(y,b.y)){
			c.y = Mx; c.x = (b.y/gcd(y,b.y)*x+y/gcd(y,b.y)*b.x);
			return c;
		}
		ll lcm = y/gcd(y,b.y)*b.y;
		return fraction(lcm/y*x+lcm/b.y*b.x,lcm);
	}
	fraction operator /(const ll &b) const {
		return fraction(x,y*b);
	}
}ans[N];

queue<int> q1;
int di[N];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin >> n >> m;
	fr(i,1,n){
		cin >> di[i];
		edge[i].resize(di[i]+1);
		fr(j,1,di[i])cin >> edge[i][j],++d[edge[i][j]];
	}
	
	fr(i,1,m)q1.push(i),ans[i] = fraction(1,1);
	while(!q1.empty()){
		int x = q1.front(); q1.pop();
		fr(i,1,(int)edge[x].size()-1){
			int y = edge[x][i];
			--d[y];
			ans[y] = ans[y]+(ans[x]/(ll)di[x]);
			if(d[y] == 0)q1.push(y);
		}
	}
	fr(i,1,n){
		if(di[i] == 0){
			if(ans[i].y == Mx)cout << ans[i].x <<' ' << "36279705600000000000" << endl;
			else cout << ans[i].x <<' ' << ans[i].y << endl;
		//	if(i == 36)cerr << ans[i].x <<' ' << ans[i].y << endl;
		}
	}
	return 0;
}
