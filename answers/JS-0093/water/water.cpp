#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=500010;
int n,m,cnt;
vector<int> edge[MAXN];
struct node{
	ll up,down;
}val[MAXN];
int size[MAXN];
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
inline ll gcd(ll x,ll y){
	ll r=x%y;
	while(r!=0){
		x=y,y=r,r=x%y;
	}
	return y;
}
inline void add(ll x,ll y){
	ll m=val[x].down*val[y].down/gcd(val[x].down,val[y].down);
	val[y].up=val[x].up*(m/val[x].down)+val[y].up*(m/val[y].down);
	val[y].down=m;
	m=gcd(val[y].up,val[y].down);
	val[y].up/=m;
	val[y].down/=m;
}
queue<int> q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=re(),m=re();
	for(int i=1;i<=n;i++){
		int x=re();
		size[i]=x;
		for(int j=1;j<=x;j++){
			int y=re();
			edge[i].push_back(y);
		}
		if(i<=m){
			q.push(i);
			val[i].up=1;
		}
		val[i].down=1;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(size[x]==0) continue;
		val[x].down*=size[x];		
		for(int i=0;i<size[x];i++){
			int y=edge[x][i];
			add(x,y);
			q.push(y);
		}
		val[x].up=0;
		val[x].down=1;
	}
	for(int i=1;i<=n;i++)
		if(size[i]==0)
			printf("%lld %lld\n",val[i].up,val[i].down);
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
