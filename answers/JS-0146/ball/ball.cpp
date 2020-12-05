#include<bits/stdc++.h>
#define ll long long
#define N 305
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=b;i>=a;--i)
#define all(x) x.begin(),x.end()
#define VI vector<int>
#define pii pair<int,int>
#define fi first
#define SZ(x) ((int)x.size())
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
int n,m;
struct node{
	int a[N],top;
	pii F,S; // (len,id)
	node(){}
	void push(int x){a[++top] = x;}
	int pop(){return a[top--];}
	int count(int x){int ans = 0;rep(i,1,top) if(a[i] == x) ans++; return ans;}
	void resize(){
		F = S = mp(0,0);
		a[0] = 1919810;
		per(i,0,m){
			if(a[i] != a[m]){ F = mp(m-i,a[m]); break; }
		}
		per(i,0,m-F.fi) {
			if(a[i] != a[m-F.fi]) { S = mp(m-F.fi-i,a[m-F.fi]); break; }
		}
	}
}p[N];
void move(int a,int b){printf("%d %d\n",a,b); p[b].push(p[a].pop()); }
void uni(int X,int Y){
	int sx,sy; sx = p[X].F.fi; sy = p[Y].F.fi;
	rep(i,1,sx+sy) move(X,n+1);
	rep(i,1,sy) move(Y,X);
	rep(i,1,sy) move(n+1,Y);
	rep(i,1,sx) move(n+1,X);
	p[X].resize();
	p[Y].resize();
}
void Swap(int X,int Y){ // X.F == Y.S
	int sx = p[X].F.fi,sy1 = p[Y].F.fi,sy2 = p[Y].S.fi;
	rep(i,1,max(sx+sy2,sy1+sy2)) move(Y,n+1);
	rep(i,1,sx) move(X,Y);
	rep(i,1,max(sx-sy1,0)) move(n+1,X);
	rep(i,1,sy2) move(n+1,Y);
	rep(i,1,sy1) move(n+1,X);
	p[X].resize();
	p[Y].resize();
}
void solve(int A,int B){
	while(1){
		rep(i,1,n) if(p[i].F.fi == m) return;
		if(p[A].F.se == p[B].F.se) uni(A,B);//,printf("uni %d %d\n",A,B);
		else Swap(A,B),swap(A,B);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int tmp;
		rep(j,1,m) scanf("%d",&tmp),p[i].push(tmp);
	}
	rep(i,1,n) p[i].resize();
	if(n == 2) { solve(1,2); return 0;}	
	rep(i,1,n/2){
		solve(i*2-1,i*2);
	}
	return 0;
}
/*
2 5
2 1 1 2 2
1 2 1 2 1

2 20
2 2 2 2 2 2 1 1 1 1 1 1 2 2 2 1 2 2 2 2
1 1 1 1 1 2 1 2 1 2 1 1 2 1 1 2 1 1 2 2

2 10
1 1 1 2 2 2 1 2 2 2 2
2 1 1 2 1 1 2 1 1 2 2

*/

